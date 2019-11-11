.model small
.stack 100
.data
    resDec db 3 dup(0)
    varD db 3 dup(0)
    msg1 db "Enter 8-bit Binary Number:",13,10,"$"
    msg2 db "The corresponding Decimal Number:",32,"$"
    msg3 db "Enter Decimal Number(0-255): ",13,10,"$"
    msg4 db "The corresponding Binary Number:",32,"$"
.code

main proc
    mov ax,@data
    mov ds,ax

    lea dx,msg1
    mov ah,9
    int 21h

    call inputBin

    lea dx,msg2
    mov ah,9
    int 21H

    mov ah,00
    mov al,bl

    call toDec

    mov dl,10
    mov ah,2
    int 21H
    mov dl,10
    mov ah,2
    int 21H

    lea dx,msg3
    mov ah,9
    int 21h

    call inputDec

    mov dl,10
    mov ah,2
    int 21H

    lea dx,msg4
    mov ah,9
    int 21H

    mov ah,00
    mov al,bl

    call toBin

    mov ah,4ch
    int 21h

main endp

inputBin proc
    xor cx,cx
    xor bx,bx
    xor ax,ax
    mov cl,1
    mov bl,1
    mov ah,1
    mov si,0
input:
    shl bl,1
    int 21h
    sub al,'0'
    or bl,al
    inc cl
    cmp cl,8
    jle input

    mov dl,10
    mov ah,2
    int 21H
    ret
inputBin endp

toDec proc                  ;data in ax
    push ax
    push bx
    push cx
    push dx
    MOV CX,0
    MOV BX,10
    MOV SI,OFFSET resDec
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

    MOV DL,resdec[0]
    MOV AH,2
    INT 21h

    MOV DL,resdec[1]
    INT 21h

    mov dl,resDec[2]
    int 21h

    MOV DL,32
    INT 21H

    pop dx 
    pop cx
    pop bx
    pop ax
    ret
toDec endp

inputDec proc                     ; final data in bx and dx
    push cx
    xor bx,bx
    xor cx,cx
    xor dx,dx
    mov cl,0
    mov di,2
    mov ah,1

    @input1:
        int 21h
        cmp al,0dh
        je store
        and al,0fh
        push ax
        add bl,al
        inc cl
        cmp cl,3
        jl @input1

    store:
        pop ax
        mov varD[di],al
        dec di
        dec cl
        cmp cl,0
        jg store

        pop cx
    ret
inputDec endp

toBin proc
    xor bx,bx
    add bl,varD[2]

    mov al,10
    mul varD[1]
    add bx,ax

    mov al,100
    mul varD[0]
    add bx,ax

    mov cl,1
    mov ah,2
output:
    shl bl,1
    jc p1
    jnc p0
p1:
    mov dl,'1'
    jmp p
p0:
    mov dl,'0'
p:
    int 21H
    inc cl
    cmp cl,8
    jle output

    mov dl,10
    int 21H
    ret
toBin endp
    
end main
