import socket
import sys
import os
import csv

class store:

    def __init__(self, username, password):
        self.username = username
        self.password = password
        self.pairs = {}

        if os.path.isfile('./values/'+self.username+'.csv'):
            reader = csv.reader(open('./values/'+self.username+'.csv'))
            
            for row in reader:
                key = row[0]
                self.pairs[key] = row[1]
        
    def save(self):
        with open('./values/'+self.username+'.csv', 'w') as f:
            for key in self.pairs.keys():
                f.write("%s,%s\n"% (key, self.pairs[key]))


class server:
    
    def __init__(self, host='localhost', port = 8000):
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.port = port
        self.host = host
        self.s.bind((host, port)) 
        self.s.listen(1)

    def start(self):
        try:
            while True:
                conn, addr = self.s.accept()
                print('Connected by', addr)
        
                user = conn.recv(1024).decode()
                pswd = conn.recv(1024).decode()

                store = store(user, pswd)
            
                while True: 
                    req = conn.recv(1024).decode()
                    if req == 'DONE': 
                        store.save()
                        break
                
                    key = conn.recv(1024).decode()
                
                    if req == 'get':
                        toReturn = store.pairs.get(key)

                        if toReturn is not None:
                            conn.sendall("KeyError".encode())
                        else: conn.sendall(toReturn.encode())
                
                    elif req == 'put':
                        val = conn.recv(1024).decode()

                        store.pairs[key] = val

                    else:
                        conn.sendall("ReqError".encode())
            
                conn.close()
        except KeyboardInterrupt:
            print("\nClosing the Server")
            self.s.close()

sock = server()
sock.start()
