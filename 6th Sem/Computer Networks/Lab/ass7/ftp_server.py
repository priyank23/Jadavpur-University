import socket
import os

port = int(input("Enter port number: "))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

sock.bind(('', port))
sock.listen(5)
c, addr = sock.accept()

# Receiving file request from the server
filename = c.recv(1024).decode()
fileValid = False

#Sending notification to the client that the file in present
if os.path.isfile(filename): 
    c.send("Done".encode())
    fileValid = True

#Requesting for some other filename to send
while not fileValid:
    c.send("Error".encode())
    filename = c.recv(1024)
    if os.path.isfile(filename):
        c.send("Done".encode())
        fileValid = True

# Sending the requested file
with open(filename, 'rb') as f:
    print('Sending file...')
    lines = f.read(1024)
    while(lines):
        c.send(lines)
        lines = f.read(1024)


# Closing the socket
print('File transfer complete')
c.shutdown(socket.SHUT_WR)
