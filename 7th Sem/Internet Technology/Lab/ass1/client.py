import socket
import sys

class client:
    def __init__(self):
        self.ip = ''
        self.port = -1
        self.s = None
    
    def parse(self):    
        for i in range(3, len(sys.argv)):
            if sys.argv[i] == 'get':
                self.get_list.append(sys.argv[i+1])
                i = i+1

            elif sys.argv[i] == 'put':
                self.put_key_list.append(sys.argv[i+1])
                self.put_value_list.append(sys.argv[i+2])
                i = i+2

            else:
                print("Error!!")
                print("Usage: ./client <server_ip> <port> put <key> <value> get <key>")
                sys.exit(1)

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
