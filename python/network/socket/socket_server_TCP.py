import socket # for sockets
import sys # for exit
from thread import *

from gi.repository import Gtk

HOST=''
PORT=6666
message=''

def main_exit():
    if win:
        win.s.close()
    sys.exit()

class MyWindow(Gtk.Window):

    def __init__(self):
        self.isClosed = 1
        try:
            # create an AF_INEF, STREAM socket(TCP)
            self.s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        except socket.error,msg:
            print('Failed to create socket. Error code: '
                +str(msg[0]+', Error message: '+msg[1]))
            main_exit()
        print('Hello. Socket Created')

        Gtk.Window.__init__(self, title="Socket_Server")

        grid = Gtk.Grid()
        self.add(grid)
        listen = Gtk.Button(label="Listen")
        listen.connect("clicked",self.on_listen_clicked)
        close = Gtk.Button(label="Close")
        close.connect("clicked",self.on_close_clicked)
        deal = Gtk.Button(label="Deal")
        deal.connect("clicked",self.on_deal_clicked)
        self.entry = Gtk.Entry()
        self.entry.set_text("Entry")
        self.label = Gtk.Label('news: ')

        grid.add(listen)
        grid.attach(close, 1, 0, 1, 1)
        grid.attach(deal, 2, 0, 1, 1)
        grid.attach(self.entry, 0, 1, 3, 1)
        grid.attach(self.label, 0, 2, 3, 1)
        self.timeout_id = None

    def on_listen_clicked(self,widget):
        # bind socket to local host and port
        try:
            self.s.bind((HOST,PORT))
        except socket.error,msg:
            print('Bing failed. Error Code: '
                + str(msg[0])+' Message '+str(msg[1]))
            main_exit()
        self.label.set_text(self.label.get_text()+
            '\n'+
            '$ Socket bind complete')

        # start to listening on socket
        self.s.listen(10)
        self.label.set_text(self.label.get_text()+
            '\n'+
            '$ Socket now listening')

        self.isClosed = 0

        # function for handing listenions. This will be used to creat threads
        def clientthread(sock):
            while True:
                self.conn,addr=sock.accept()
                self.label.set_text(self.label.get_text()+
                    '\n'+
                    '$Connected with '+addr[0]+': '+str(addr[1]))

                while True:
                    # receiving from client
                    data=self.conn.recv(1024)
                    if data =='':
                        self.label.set_text(self.label.get_text() + 
                            '\nGet ...' + 'Goodbye')
                    else:   
                        self.label.set_text(self.label.get_text() + 
                            '\nGet ...' + data)
                    # reply='OK...'+data
                    if not data:
                        break
                    self.conn.sendall(data)

                # came out of loop
                self.conn.close()
                self.conn = None
        start_new_thread(clientthread, (self.s,))

    def on_close_clicked(self,widget):
        if self.conn:
            self.conn.close()
        print('Goodbye')
        Gtk.main_quit()

    def on_deal_clicked(self,widget):
        if self.isClosed == 0:
            message=self.entry.get_text()
            # print('I got it! '+ message)
            try:
                # set the whole string
                self.conn.sendall(message)
            except socket.error, msg:
                # send failed
                print('Send failed' + str(msg))
                self.label.set_text(self.label.get_text()+
                    '\n'+
                    '$ Send failed')
                main_exit()
            print('Message send successfully')
            reply=self.conn.recv(4096)
            # print(reply)
            self.label.set_text(self.label.get_text()+
                '\nSend...'+str(reply))
        else:
            # print('The connection is closed. ')
            self.label.set_text(self.label.get_text()+
            '\n'+'$ The connection is closed.')

win = MyWindow()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()
