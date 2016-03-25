# import socket
# from gi.repository import Gtk

# UDP_IP ='127.0.0.1'
# UDP_PORT=5005

# sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

# while True:
#     msg=raw_input()
#     if not msg:
#         break
#     sock.sendto(msg,(UDP_IP,UDP_PORT))   

# sock.close()
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
        self.set_default_size(300, 100)

        self.isSocketClosed = 1

        try:
            self.sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        except socket.error, e:
            printSocketError(e)

        grid = Gtk.Grid()
        self.add(grid)
        closeBtn = Gtk.Button(label="Close")
        closeBtn.connect("clicked", self.on_close_clicked)
        submitBtn = Gtk.Button(label="Submit")
        submitBtn.connect("clicked", self.on_submit_clicked)
        self.entry = Gtk.Entry()
        self.entry.set_text("Type here!")
        self.label = Gtk.Label('news: ')

        grid.add(closeBtn)
        grid.attach(submitBtn, 1, 0, 1, 1)
        grid.attach(self.entry, 0, 1, 3, 1)
        grid.attach(self.label, 0, 2, 3, 1)

    def close(self):
        if not self.isSocketClosed:
            print('close socket!')
            self.sock.shutdown(socket.SHUT_RDWR)
            self.sock.close()

    def __del__(self):
        self.close()

    def on_close_clicked(self, widget):
        self.close()
        print('Goodbye')
        Gtk.main_quit()

    def on_submit_clicked(self, widget):
        message=self.entry.get_text()
        try:
            self.sock.sendto(message,(host,port))
        except socket.error, e:
            self.label.set_text(self.label.get_text() + '\n'
                                + '$ Send failed')
            printSocketError(e)
            self.close()
            Gtk.main_quit()
        self.label.set_text(self.label.get_text()+
        	'\nMessage send successfully')
     
win = MainWindow()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()