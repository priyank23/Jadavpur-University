import socket

# Receiving different values required
filename = str(input('Enter name of file to receive: '))
filename2 = str(input('Enter name of file in which received data should be put: '))
ipaddr = input('Enter ip of server: ')
port = int(input('Enter listening port of the server: '))

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

sock.connect((ipaddr, port))
ack = False

# Requesting file from the server
while not ack:
    sock.send(filename.encode())
    if sock.recv(1024).decode() == "Done": ack = True
    else:
        print('No file named '+ filename + 'present')
        filename = str(input('Enter name of file to receive: '))

# Receiving file from the server
with open(filename2, 'wb') as f:
    print('Receiving...')
    while(True):
        lines=sock.recv(1024)
        if not lines: break
        f.write(lines)

# Closing the socket
print('File received successfully.')
sock.shutdown(socket.SHUT_WR)
