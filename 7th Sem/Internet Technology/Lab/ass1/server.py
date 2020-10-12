import socket
import sys
import os
import csv
import random

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
        self.st = None

        self.mgrs = {}
        if os.path.isfile('manager.csv'):
            reader = csv.reader(open('manager.csv'))
            for row in reader:
                mgr = row[0]
                self.mgrs[mgr] = row[1]

    def validate(self, username, conn):
        i = 1
        while i <= 3:
            password = conn.recv(1024).decode()
            if password == self.mgrs[username]: 
                conn.sendall("OK".encode())
                break
            else: conn.sendall("NOK".encode())
            i = i+1

        if i == 4: 
            del self.mgrs[username]
            print("User demoted from manager to guest!!")
            self.save_manager_list()

        else: 
            print("A manager accessed the connection")
            self.managers_utility(conn)
    
    def save_manager_list(self):
        with open('manager.csv', 'w') as f:
            for key in self.mgrs.keys():
                f.write("%s,%s\n"% (key, self.mgrs[key]))

    def add_manager(self, user, conn):
        if user in self.mgrs: 
            conn.sendall('Present'.encode())
            return
        r = random.random()
        if r < 0.25:
            print("Request for upgrade denied!")
            conn.sendall('Denied'.encode())
        else:
            conn.sendall('Granted'.encode())
            password = conn.recv(1024).decode()
            conn.sendall('ACK'.encode())
            self.mgrs[user] = password
            print("A new manager added")
            self.managers_utility(conn)
        
        self.save_manager_list()

    def managers_utility(self, conn):
        while True:
            user = conn.recv(1024).decode()
            if os.path.isfile('./values/'+user+'.csv'):
                self.st = store(user)
                conn.sendall('OK'.encode())
                return
            else:
                conn.sendall('NOK'.encode())
    
    def start(self):
        try:
            while True:
                conn, addr = self.s.accept()
                print('\n--------------------------')
                print('Connected by', addr)
                print('--------------------------\n')
                
                user = conn.recv(1024).decode()
                if user in self.mgrs:
                    conn.sendall("MANAGER".encode())
                    self.validate(user, conn)
                else: conn.sendall("GUEST".encode())
                
                print("Username: %s" % user)
                
                ownership = conn.recv(1024).decode()
                if ownership == 'manager':
                    self.add_manager(user, conn)
                else: conn.send('ACK'.encode())
                
                if self.st is None: self.st = store(user)
                st = self.st
                self.st = None
                
                while True: 
                    req = conn.recv(1024).decode()
                    conn.sendall("RecReq".encode())
                    if req == 'DONE': 
                        st.save()
                        break
                
                    print("Request Type: "+ req)
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
