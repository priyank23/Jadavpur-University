import socket
import sys
import os
import csv

class store:

    def __init__(self, username, password=None):
        self.username = username
        self.password = password
        self.pairs = {}

        if os.path.isfile('./values/'+self.username+'.csv'):
            reader = csv.reader(open('./values/'+self.username+'.csv'))
            
            for row in reader:
                key = row[0]
                self.pairs[key] = row[1]
        else:
            print("New User entered")
        
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
                conn.sendall("User Received".encode())
                #pswd = conn.recv(1024).decode()
                print("Username: %s" % user)
                st = store(user)
            
                while True: 
                    req = conn.recv(1024).decode()
                    print("Request Type: " + req)
                    conn.sendall("RecReq".encode())
                    if req == 'DONE': 
                        st.save()
                        break
                
                    key = conn.recv(1024).decode()
                    conn.sendall("RecKey".encode())

                    if req == 'get':
                        print("Key: "+key)
                        toReturn = st.pairs.get(key)
                        conn.recv(1024).decode() 
                        if toReturn is None:
                            conn.sendall("KeyError".encode())
                        else: conn.sendall(toReturn.encode())
                        
                    elif req == 'put':
                        val = conn.recv(1024).decode()
                        st.pairs[key] = val
                        print("Key: %s, Value: %s" % (key, val))
                        conn.sendall('OK'.encode())

                    else:
                        conn.sendall("ReqError".encode())
                        st.save()
                        break
            
                conn.close()
                print("connection closed!!")
        except KeyboardInterrupt:
            print("\nClosing the Server")
            self.s.close()

sock = server()
sock.start()
