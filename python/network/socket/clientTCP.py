from gi.repository import Gtk, GLib
import socket
import sys
import threading
import time

host=''
port=6666

def printSocketError(err):
    print('Socket error: code({}), {}'.format(err[0], err[1]))

def updateLabel(label, reply):
    original = label.get_text()
    label.set_text(original + '\n' + reply)
    return False

def updateRecvMessage(sock, label):
    while True:
        reply = sock.recv(4096)
        if len(reply) > 0:
            print(reply)
            GLib.idle_add(updateLabel, label, reply)

class MainWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="Socket Client")

        self.isSocketClosed = 1

        try:
            self.sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        except socket.error, e:
            printSocketError(e)

        grid = Gtk.Grid()
        self.add(grid)
        connectBtn = Gtk.Button(label="Connect")
        connectBtn.connect("clicked", self.on_connect_clicked)
        closeBtn = Gtk.Button(label="Close")
        closeBtn.connect("clicked", self.on_close_clicked)
        submitBtn = Gtk.Button(label="Submit")
        submitBtn.connect("clicked", self.on_submit_clicked)
        self.entry = Gtk.Entry()
        self.entry.set_text("Type here!")
        self.label = Gtk.Label('news: ')

        grid.add(connectBtn)
        grid.attach(closeBtn, 1, 0, 1, 1)
        grid.attach(submitBtn, 2, 0, 1, 1)
        grid.attach(self.entry, 0, 1, 3, 1)
        grid.attach(self.label, 0, 2, 3, 1)

    def close(self):
        if not self.isSocketClosed:
            print('close socket!')
            self.sock.shutdown(socket.SHUT_RDWR)
            self.sock.close()

    def __del__(self):
        self.close()

    def on_connect_clicked(self, widget):
        try:
            remote_ip=socket.gethostbyname(host)
        except socket.gaierror, e:
            # could not resolve
            printSocketError(e)
            Gtk.main_quit()
        # print('IP address of '+host+' is '+remote_ip)
        self.label.set_text(self.label.get_text() + '\n'
                            + '$ IP address of' + host + ' is ' + remote_ip)
        # connect to remote server
        self.sock.connect((remote_ip,port))
        self.label.set_text(self.label.get_text() + '\n'
                            + '$ Socket Connected to ' + host
                            + ' on ip ' + remote_ip)

        self.isSocketClosed = 0

        self.recvThread = threading.Thread(target=updateRecvMessage,
                                           args=(self.sock, self.label))
        self.recvThread.daemon = True
        self.recvThread.start()

    def on_close_clicked(self, widget):
        self.close()
        print('Goodbye')
        Gtk.main_quit()

    def on_submit_clicked(self, widget):
        if not self.isSocketClosed:
            message=self.entry.get_text()
            try:
                self.sock.sendall(message)
            except socket.error, e:
                self.label.set_text(self.label.get_text() + '\n'
                                    + '$ Send failed')
                printSocketError(e)
                self.close()
                Gtk.main_quit()
            print('Message send successfully')
        else:
            self.label.set_text(self.label.get_text() + '\n'
                                + '$ The connection is closed.')

win = MainWindow()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()
