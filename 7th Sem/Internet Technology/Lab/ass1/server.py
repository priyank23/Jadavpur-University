import socket
import sys

class server:
    
    def __init__(self, host='localhost', port = 8000):
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.port = port
        self.host = host
        self.s.bind((host, port)) 
        self.s.listen(1)
        conn, addr = self.s.accept()
        
        print('Connected by', addr)


sock = server()

