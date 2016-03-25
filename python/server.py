#!/usr/bin/env python
# -*- coding: utf-8 -*-


import socket
import sys
from Tkinter import *
import threading


class SocketServerApp():

    """About a simple socket server application"""

    global username_and_password 
    username_and_password= {'user1': 'pass1',
                            'user2': 'pass2',
                            'user3': 'pass3',
                            }

    def __init__(self, master=None):
        self.button1=None
        self.button2=None
        self.button3=None
        self.text1=None
        self.sock=None
        self.bool1=None
        self.user=None
        self.connection=None

        frame = Frame(master)
        frame['padx'] = 5
        frame['pady'] = 10
        frame['width'] = 200
        frame['height'] = 200
        frame['borderwidth'] = 5
        frame['relief'] = 'sunken'
        self.CreateGui(frame)

    def CreateGui(self, master=None):
        master.grid(column=0, row=0, columnspan=5, rowspan=3)

        
        self.button1 = Button(master)
        self.button1['text'] = 'Start'
        self.button1['command'] = self.StartCallback
        self.button1.grid(column=1, row=0)

        self.button2 = Button(master)
        self.button2['text'] = 'Stop'
        self.button2['command'] = self.StopCallback
        self.button2['state'] = 'disabled'
        self.button2.grid(column=3, row=0)

        self.text1 = Text(master)
        self.text1['width'] = 50
        self.text1['height'] = 20
        self.text1['state'] = 'disabled'
        self.text1.grid(column=0, row=3, columnspan=5)

    def StartCallback(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        if self.sock:
            self.button2['state'] = 'normal'
            self.text1['state'] = 'normal'
            self.text1.insert(1.0, "Start Service!\n")
            self.text1['state'] = 'disabled'
        server_address = ('localhost', 10000)
        print >> sys.stderr, 'starting up on %s port %s' % server_address
        self.sock.bind(server_address)
        self.sock.listen(1)

        t = threading.Thread(target=self.DealRequest)
        t.start()

    def StopCallback(self):
        self.text1['state'] = 'normal'
        self.text1.insert(1.0, "Stop Service!\n")
        self.text1['state'] = 'disabled'
        self.button2['state'] = 'disabled'
        self.connection.close()

    def DealRequest(self):
        self.bool1 = False
        while True:
            print >> sys.stderr, 'waiting for a connection'
            self.connection, client_address = self.sock.accept()
            try:
                print>>sys.stderr, 'connection from', client_address
                while True:
                    data = self.connection.recv(16)
                    print>>sys.stderr, 'received "%s"' % data
                    if data:
                        if data.startswith('user:'):
                            for n in username_and_password:
                                if n == data[5:]:
                                    self.bool1 = True
                                    self.user = n
                                    break
                            print(self.bool1)
                            if self.bool1:
                                self.connection.sendall('1')
                                self.text1['state'] = 'normal'
                                self.text1.insert(
                                    1.0, "username:" + self.user + "  correct!\n")
                                self.text1['state'] = 'disabled'
                            else:
                                self.connection.sendall('0')
                                self.text1['state'] = 'normal'
                                self.text1.insert(
                                    1.0, "username:" + self.user + "  wrong!\n")
                                self.text1['state'] = 'disabled'
                        elif data.startswith('mess:'):
                            self.connection.sendall(
                                'I received your message,\nit is "%s",\nI will deal with it,\nplease wait!\n' % data[5:])
                            self.text1['state'] = 'normal'
                            self.text1.insert(
                                1.0, "received message:" + data + " from " + client_address[0]+"\n")
                            self.text1['state'] = 'disabled'
                        elif data.startswith('pass:'):
                            if self.user:
                                if username_and_password[self.user] == data[5:]:
                                    self.connection.sendall('1')
                                    self.text1['state'] = 'normal'
                                    self.text1.insert(
                                        1.0, "password:" + data[5:] + "  correct!\n")
                                    self.text1['state'] = 'disabled'
                                    self.user = None
                                else:
                                    self.connection.sendall('0')
                                    self.text1['state'] = 'normal'
                                    self.text1.insert(
                                        1.0, "password:" + data[5:] + "  wrong!\n")
                                    self.text1['state'] = 'disabled'
                                    self.user = None
                            else:
                                self.connection.sendall('0')

                    else:
                        print >> sys.stderr, 'no data from', client_address
                        break
            finally:
                self.connection.close()


root = Tk()
SocketServerApp()
root.mainloop()
