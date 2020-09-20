##CSMA

### Following CSMA techniques are implemented:
- 1-persistent
- non-persistent
- p-persistent

### Files present
- `message.txt` - Input message to send
- `channel.java` - This acts as the channel for the participating channels.
- `station.java` - THis acts as the sending and receiving stations.

__PS - Assignment 1's code (`ass1` folder) is a requirement for this as well as that provides the frame encoding protocols.__

### Steps to compile & run
- Put all the files in a folder.
- Go to the parent folder and open terminal.
- `javac ass3/channel.java`
- `javac ass3/station.java`
- Open the channel - `java ass3.channel`
- Open the number of stations you require. Any station can act as either a sender or receiver. - `java ass3.station`
