#socket client
import socket
#sleep
import time
Delay=[0,1,2,3,4,5,6,7,8,9]
sock=socket.socket()
host=''
port=6006
print('Ready to connect.')
for connecting in Delay:
	time.sleep(1)
	print('connecting :'+str(connecting)+'s')
sock.connect((host,port))
print('(You are connecting now.)')
print(sock.recv(1024))