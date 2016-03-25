from gi.repository import Gtk, GLib
import socket
import sys
import threading

host=''
port=6666

def printSocketError(err):
    print('Socket error: code({}), {}'.format(err[0], err[1]))

def updateLabel(label, reply):
    original = label.get_text()
    label.set_text(original + '\n' + reply)
    return False

def updateRecvMessage(conn, label):
    while True:
        reply = conn.recv(4096)
        if len(reply) > 0:
            print(reply)
            GLib.idle_add(updateLabel, label, reply)

class MainWindow(Gtk.Window):
    def __init__(self):
        Gtk.Window.__init__(self, title="Socket Sever")
        self.set_default_size(300, 100)

        self.isSocketClosed = 1

        try:
            self.sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        except socket.error, e:
            printSocketError(e)

        try:
            self.sock.bind((host,port))
        except socket.error, e:
            printSocketError(e)
            self.close()
            Gtk.main_quit()

        grid = Gtk.Grid()
        self.add(grid)
        closeBtn = Gtk.Button(label="Close")
        closeBtn.connect("clicked", self.on_close_clicked)

        self.label = Gtk.Label('news: ')

        grid.add(closeBtn)
        grid.attach(self.label, 0, 1, 3, 1)

        def client_thread(sock):
            while True:
                conn, addr = self.sock.recvfrom(2048)
                self.conn = conn
                GLib.idle_add(
                    lambda: self.label.set_text(
                        self.label.get_text() + '\n'
                        + '$ Received:'+str(conn)))

                self.recvThread = threading.Thread(target=updateRecvMessage,
                                                   args=(self.conn, self.label))
                self.recvThread.daemon = True
                self.recvThread.start()

        thread = threading.Thread(target=client_thread,
                                  args=(self.sock,))
        thread.daemon = True # do not wait for the client_thread()'s return before exit
        thread.start()

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

win = MainWindow()
win.connect('delete-event', Gtk.main_quit)
win.show_all()
Gtk.main()
