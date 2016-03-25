#!/usr/bin/env python
# -*- coding: utf-8 -*-

from Tkinter import *
import socket


class SocketClientApp():

    """About a easy socket_client Application"""
    

    def __init__(self, master=None):
        self.label1=None
        self.entry1=None
        self.label2=None
        self.entry2=None
        self.e1=None
        self.e2=None
        self.label4=None
        self.button1=None
        self.button2=None
        self.button3=None
        self.text1= None
        self.text2=None
        self.sock=None
        self.username=None
        self.password=None
        self.message=None
        frame = Frame(master)
        frame['padx'] = 5
        frame['pady'] = 10
        frame['width'] = 200
        frame['height'] = 200
        frame['borderwidth'] = 5
        frame['relief'] = 'sunken'
        self.CreateGui(frame)

    def CreateGui(self, master=None):
        master.grid(column=0, row=0, columnspan=7, rowspan=6)

        self.label1 = Label(master)
        self.label1['width'] = 10
        self.label1['height'] = 1
        self.label1['text'] = "username:"
        self.label1['anchor'] = "nw"
        self.label1['fg'] = "red"
        self.label1.grid(column=0, row=0)

        self.e1 = StringVar()
        self.entry1 = Entry(master)
        self.entry1['width'] = 15
        self.entry1['textvariable'] = self.e1
        self.entry1.grid(column=1, row=0)

        self.label2 = Label(master)
        self.label2['width'] = 10
        self.label2['height'] = 1
        self.label2['text'] = "password:"
        self.label2['anchor'] = "nw"
        self.label2['fg'] = "red"
        self.label2.grid(column=0, row=1)

        self.e2 = StringVar()
        self.entry2 = Entry(master)
        self.entry2['textvariable'] = self.e2
        self.entry2['width'] = 15
        self.entry2['show'] = '*'
        self.entry2.grid(column=1, row=1)

        self.button1 = Button(master)
        self.button1['text'] = 'log in'
        self.button1['command'] = self.LoginCallback
        self.button1.grid(column=0, row=3)

        self.button2 = Button(master)
        self.button2['text'] = 'log out'
        self.button2['command'] = self.LogoutCallback
        self.button2['state'] = 'disabled'
        self.button2.grid(column=1, row=3)

        self.text1 = Text(master)
        self.text1['width'] = 50
        self.text1['height'] = 5
        self.text1['state'] = 'disabled'
        self.text1.grid(column=0, row=5, columnspan=5)

        self.button3 = Button(master)
        self.button3['command'] = self.SubmitCallback
        self.button3['text'] = 'submit'
        self.button3['state'] = 'disabled'
        self.button3.grid(column=0, row=6, columnspan=2)

        self.label4 = Label(master)
        self.label4['width'] = 15
        self.label4['height'] = 1
        self.label4['text'] = "request of server:"
        self.label4['fg'] = "red"
        self.label4.grid(column=5, row=0)

        self.text2 = Text(master)
        self.text2['width'] = 30
        self.text2['height'] = 10
        self.text2['state'] = 'disabled'
        self.text2.grid(column=5, row=1, columnspan=2, rowspan=5)

    def LoginCallback(self):
        self.username = self.e1.get()
        self.password = self.e2.get()
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_addr = ('localhost', 10000)
        self.sock.connect(server_addr)
        self.sock.sendall("user:" + self.username)
        state1 = self.sock.recv(1)
        self.sock.sendall("pass:" + self.password)
        state2 = self.sock.recv(1)
        if state1 + state2 == '11':
            self.text2['state'] = 'normal'
            self.text2.insert(1.0, 'log in successful!\n')
            self.text2['state'] = 'disabled'
            self.button2['state'] = 'normal'
            self.button3['state'] = 'normal'
            self.text1['state'] = 'normal'
        else:
            print(state1, state2)
            self.text2['state'] = 'normal'
            self.text2.insert(1.0, 'log in failed!\n')
            self.text2['state'] = 'disabled'

    def LogoutCallback(self):
        self.sock.close()
        self.text2['state'] = 'normal'
        self.text2.insert(1.0, 'log out!\n')
        self.text2['state'] = 'disabled'
        self.button2['state'] = 'disabled'
        self.button3['state'] = 'disabled'
        self.text1['state'] = 'disabled'

    def SubmitCallback(self):
        self.sock.sendall("mess:" + self.text1.get(0.0, END))
        self.message = self.sock.recv(100)
        self.text2['state'] = 'normal'
        self.text2.insert(1.0, self.message)
        self.text2['state'] = 'disabled'

root = Tk()
SocketClientApp(root)
root.mainloop()
