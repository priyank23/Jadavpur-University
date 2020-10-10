import socket
import sys

class client:
    def __init__(self):
        self.ip = ''
        self.port = -1
        self.s = None
   
    def authenticate(self):
        username = input("Username: ")
        self.s.sendall(username.encode())
        print(self.s.recv(1024).decode())

    def parse(self):
        i = 3
        while i<len(sys.argv):
            #print(i)
            if sys.argv[i] == 'get':
                self.s.sendall('get'.encode())
                self.s.recv(1024).decode()
                self.s.sendall(sys.argv[i+1].encode())
                self.s.recv(1024).decode()
                self.s.sendall("ACK".encode())
                i = i+2
                val = self.s.recv(1024).decode()
                print(val)

            elif sys.argv[i] == 'put':
                print("put " + sys.argv[i+1] + " " + sys.argv[i+2])
                self.s.sendall('put'.encode())
                self.s.recv(1024).decode()
                
                self.s.sendall(sys.argv[i+1].encode())
                self.s.recv(1024).decode()
                
                self.s.sendall(sys.argv[i+2].encode())
                res = self.s.recv(1024).decode()
                if not res == 'OK':
                    print(res)
                    break
                i = i+3

            else:
                print("Error!!")
                print("Usage: ./client <server_ip> <port> put <key> <value> get <key>")
                self.s.close()
                sys.exit(1)
        
        self.s.sendall("DONE".encode())
        self.s.close()

    def connect(self):
        if len(sys.argv) < 3:
            print("Error!!")
            print("Usage: ./client <server_ip> <port> put <key> <value> get <key>")
            sys.exit(1)
        
        self.ip = sys.argv[1]
        self.port = int(sys.argv[2])
    
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    
        self.s.connect((self.ip, self.port))


c = client()
c.connect()
c.authenticate()
c.parse()
