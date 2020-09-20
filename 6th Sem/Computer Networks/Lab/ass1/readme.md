## Error Detection Module

This folder contains codes to implement an error detection module consisting of four schemes:
- LRC
- VRC
- Checksum
- CRC

###Following are the details of the files present:
- `message.txt` - The file containing input bits.
- `sender.java` - The code consisting of sender's module for various schemes.
- `intermediate.txt` - The sender's module writes its output in this file.
- `errorInsertion.java` - The code to help insert error bits in the intermediate.txt for better analysis.
- `receiver.java` - The code consisting of receiver's module for various shemes.
- `Checker.java` - The code to check whether the message received by the receiver module has error in it or not.
- `files.java` - Helper module for file handling.

###Steps to run
- Put all the files in one folder. (say `folder`)
- Put Makefile in the parent folder.
- `make`
- `java ass1.sender`
- `java ass1.ErrorHandling` (For inserting errors in the sent message)
- `java ass1.Receiver`
- 
