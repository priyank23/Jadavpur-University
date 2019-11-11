.model small
.stack 10
.data
    res db 3 dup(0)
.code

main proc
    mov ax,@data
    mov ds,ax

    mov bh,100
    mov bl,0

    xor ax,ax
    mov al,bl
    call output
    mov dl,','
    mov ah,2
    int 21H
    xor ax,ax
    mov al,bh
    call output
    mov dl,'0'
    mov ah,2
    int 21h
    mov dl,32
    int 21h
    add bl,2
    sub bh,2
    
    mov cl,25
print:
    xor ax,ax
    mov al,bl
    call output
    mov dl,','
    mov ah,2
    int 21H
    xor ax,ax
    mov al,bh
    call output
    mov dl,32
    mov ah,2
    int 21h

    add bl,2
    sub bh,2
    dec cl
    cmp cl,0
    jg print

    mov ah,4ch
    int 21H
ret
main endp

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


    pop dx 
    pop cx
    pop bx
    pop ax
    ret
output endp
end main