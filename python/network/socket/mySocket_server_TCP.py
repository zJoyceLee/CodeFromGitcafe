import socket
import sys
from thread import *

HOST=''
PORT=6666
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print('Socket created')

# bind socket to local host and port 
try:
	s.bind((HOST,PORT))
except socket.error,msg:
	print('Bing failed. Error Code: '
		+ str(msg[0])+' Message '+str(msg[1]))
	sys.exit()
print('Socket bind complete')

# start to listening on socket
s.listen(10)
print('Socket now listening')

# function for handing connections. This will be used to creat threads
def clientthread(conn):
	# sending message to connected client
	# conn.send('Welcome to the server. \
	# 	Type something and click submit\n') # send only takes string
	# infinite loop so that function do not terminate and thread do not end.
	while(True):
		# receiving from client
		data=conn.recv(1024)
		print(data)
		reply='OK...'+data
		if not data:
			break

		conn.sendall(reply)

	# came out of loop
	conn.close()

# keep talking with the client
while 1:
	'''# now keep talking with the client
	data=conn.recv(1024)
	print(data)
	reply='OK...'+data
	if not data:
		break
	conn.sendall(data)'''
	# wait to accept a connection - blocking call
	conn, addr=s.accept()
	# display client information
	print('Conneted with'+addr[0]+':'+str(addr[1]))
	# start new thread takes 1st argument as a function name to be run
	# second is the tuple of arguments to the function.
	start_new_thread(clientthread,(conn,))

s.close()