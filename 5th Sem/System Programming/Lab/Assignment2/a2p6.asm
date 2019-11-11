.model small
.stack 100
.data
    res db 3 dup(0)
.code

main proc
    mov ax,@data
    mov ds,ax

    call printFib

    mov ah,4ch
    int 21h
main endp

printFib proc
    xor ax,ax
    xor bx,bx
    xor cx,cx
    xor dx,dx

    mov cl,2

    mov dl,0
    mov bl,1
    mov al,1
    call output
Fib:
    mov al,dl
    add al,bl
    call output
    mov dl,bl
    mov bl,al
    inc cl
    cmp cl,10
    jle Fib
ret
printFib endp

output proc                  ;data in ax
    push ax
    push bx
    push cx
    push dx
    MOV CX,0
    MOV BX,10
    MOV SI,OFFSET RES
LOOP1: MOV DX,0
       DIV BX
       ADD DL,30H
       PUSH DX
       INC CX
       CMP AX,9
       JG LOOP1
     
       ADD AL,30H
       MOV [SI],AL
     
LOOP2: POP AX
       INC SI
       MOV [SI],AL
       LOOP LOOP2    

    MOV DL,res[0]
    MOV AH,2
    INT 21h

    MOV DL,res[1]
    INT 21h

    MOV DL,32
    INT 21H

    pop dx 
    pop cx
    pop bx
    pop ax
    ret
output endp
end main