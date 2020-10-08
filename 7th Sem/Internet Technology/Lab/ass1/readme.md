Assignment 1
Implement a TCP-based key-value store. The server implements the key-value store and clients make use
of it. The server must accept clients’ connections and serve their requests for ‘get’ and ‘put’ key value pairs.
All key-value pairs should be stored by the server only in memory. Keys and values are strings.
The client accepts a variable no of command line arguments where the first argument is the server hostname
followed by port no. It should be followed by any sequence of “get <key>” and/or “put <key> <value>”.
./client 192.168.124.5 5555 put city Kolkata put country India get country get city get Institute
India
Kolkata
<blank>
The server should be running on a TCP port. The server should support multiple clients and maintain their
key-value stores separately.
Implement authorization so that only few clients having the role “manager” can access other’s key-value
stores. A user is assigned the “guest” role by default. The server can upgrade a “guest” user to a “manager”
user.
