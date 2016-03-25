#socket server
import socket
#sleep : time.sleep(4) -> 4s
import time
Delay=[0,1,2,3,4,5,6,7,8,9]
sock=socket.socket()
host=''
port=6006
sock.bind((host,port))
sock.listen(0)
while True:
	c,addr=sock.accept()
	print 'Got connection from ',addr
	for reply in Delay:
		time.sleep(1)
		print('reply '+str(host)+':'+str(reply)+'s')
	c.send('Thank you for connecting')
	c.close()
