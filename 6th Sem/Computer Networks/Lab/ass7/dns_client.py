
import socket

# Accept ip address
name=str(input("Enter domain name or ip: "))
ipaddr=str(input("Enter ip of dns server: "))
port=int(input("Enter port of server: "))

sock=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

sock.connect((ipaddr,port))

# Send the domain name or ip
sock.sendto(name.encode(),0,(ipaddr,port))

# Wait for the server to send
iporname, addr=sock.recvfrom(1024)
iporname=iporname.decode()
print(iporname)

sock.close()
