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
        user_stat = self.s.recv(1024).decode()
        if user_stat == 'MANAGER':
            print("You are marked as a manager!!\nEnter correct password else you will be demoted to a guest user!!")
            i = 1
            while i<=3:
                if i>1: print("Error!!\n%d attempts remaining!!" % (3-i+1))
                password = input("Password: ")
                self.s.sendall(password.encode())
                validity = self.s.recv(1024).decode()
                if validity == 'OK': break
                i = i + 1

            if i<=3: 
                print("Welcome Manager!!")
                self.managers_utility()
            else: print("You have been demoted to a guest user")
    
    def add_manager(self):
        authorisation = self.s.recv(1024).decode()
        if authorisation == 'Present': return
        if authorisation == 'Denied':
            print('Request for upgradation to manager denied by the server!!')
        else:
            password = input("Create password: ")
            while not input("Confirm password: ") == password:
                print("Password not matched!! Try again!!")
            self.s.send(password.encode())
            print(self.s.recv(1024).decode())
            print('You are now a manager')
            self.managers_utility()

    def managers_utility(self):
        while True:
            username = input("Enter the name of the user whose information you need: ")
            self.s.sendall(username.encode())
            res = self.s.recv(1024).decode()
            if res == 'OK': return
            print("User not present!!")

    def parse(self):
        i = 3
        if sys.argv[i] == 'manager':
            self.s.sendall('manager'.encode())
            self.add_manager()
            i = i+1
        else: 
            self.s.sendall('guest'.encode())
            self.s.recv(1024)
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
                self.s.sendall('put'.encode())
                self.s.recv(1024).decode()
                
                self.s.sendall(sys.argv[i+1].encode())
                self.s.recv(1024).decode()
                
                self.s.sendall(sys.argv[i+2].encode())
                res = self.s.recv(1024).decode()
                if not res == 'OK':
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
