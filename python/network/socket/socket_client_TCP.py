import socket # for sockets
import sys # for exit

from gi.repository import Gtk

# try:
#     # create an AF_INEF, STREAM socket(TCP)
#     s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
# except socket.error,msg:
#     print('Failed to create socket. Error code: '+str(msg[0]+', Error message: '+msg[1]))
#     sys.exit()

host=''
port=6666
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

        Gtk.Window.__init__(self, title="Socket_Client")
        # self.set_size_request(200, 100)

        grid = Gtk.Grid()
        self.add(grid)
        button1 = Gtk.Button(label="Connect")
        button1.connect("clicked",self.on_button1_clicked)
        button2 = Gtk.Button(label="Close")
        button2.connect("clicked",self.on_button2_clicked)
        button3 = Gtk.Button(label="Submit")
        button3.connect("clicked",self.on_button3_clicked)
        self.entry = Gtk.Entry()
        self.entry.set_text("Entry")
        self.label = Gtk.Label('news: ')
        
        grid.add(button1)
        grid.attach(button2, 1, 0, 1, 1)
        grid.attach(button3, 2, 0, 1, 1)
        # grid.attach_next_to(self.entry, button1, 
        #     Gtk.PositionType.BOTTOM, 3, 1)
        grid.attach(self.entry, 0, 1, 3, 1)
        grid.attach(self.label, 0, 2, 3, 1)
        self.timeout_id = None

    def on_button1_clicked(self,widget):
        try:
            remote_ip=socket.gethostbyname(host)
        except socket.gaierror:
            # could not resolve
            print('Hostname could not be resolved.Exiting')
            main_exit()
        # print('IP address of '+host+' is '+remote_ip)
        self.label.set_text(self.label.get_text()+
            '\n'+
            '$ IP address of '+host+' is '+remote_ip)
        # connect to remote server
        print(remote_ip,port)
        self.s.connect((remote_ip,port))
        # print('Socket Connected to '+host+' on ip '+remote_ip)
        self.label.set_text(self.label.get_text()+
            '\n'+
            '$ Socket Connected to '+host+' on ip '+remote_ip)
        self.isClosed = 0

    def on_button2_clicked(self,widget):
        print('Goodbye')
        Gtk.main_quit()

    def on_button3_clicked(self,widget):
        if self.isClosed == 0:
            message=self.entry.get_text()
            # print('I got it! '+ message)
            try:
                # set the whole string
                self.s.sendall(message)
            except socket.error:
                # send failed
                # print('Send failed')
                self.label.set_text(self.label.get_text()+
                    '\n'+
                    '$ Send failed')
                main_exit()
            print('Message send successfully')
            reply=self.s.recv(4096)
            # print(reply)
            self.label.set_text(self.label.get_text()+
                '\nSend...'+str(reply))
            reply=self.s.recv(4096)
        else:
            # print('The connection is closed. ')
            self.label.set_text(self.label.get_text()+
            '\n'+'$ The connection is closed.')

win = MyWindow()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()

