# Assignment 1

### How to run
- Open terminal
- Run `chmod +x server client`
- Run `./server`
- Open another terminal and run `./client < ip address > < port > < commands >`
- Enter username to continue

#### Commands
Commands can be in form
- `manager` : to ask the server for upgradation to manager mode
- `put < key > < value >`
- `get < key >`

All commands can be mixed and used together in the argruments.
Check output to see examples

---
### Memory Details
The memory files kept on the server side are :

- Client Profiles : Every client's key-value pairs are stored in their own csv files in the folder `values`
- Manager Profiles: `managers.csv` - a list of all client usernames who have manager authorization.
