.model small
.stack 100h
	CR equ 13d
	LF equ 10d
.data
	msg1 db 'Enter an uppercase letter: $'
	result db CR, LF, 'The lowercase equivalent is: $'
.code

start:
	mov ax, @data
	mov ds, ax
	mov dx, offset msg1
	call puts 
	call getc 
	mov bl, al 
	add bl, 32d 
	mov dx, offset result
	call puts 
	mov dl, bl
	call putc 
	mov ax, 4c00h
	int 21h 


puts:
	mov ah, 9h
	int 21h 
	ret

putc: 
	mov ah, 2h
	int 21h
	ret

getc: 
	mov ah, 1h
	int 21h
	ret

end start