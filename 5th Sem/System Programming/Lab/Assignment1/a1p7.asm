.model small
.stack 100
.data
    msg1 db "Enter first number:" , 13,10, "$"
    msg2 db "Enter second number:",13,10,"$"
    msg3 db "Second Number is greater.$"
    msg4 db "Second Number is not greater.$"
    var1 db ?
    var2 db ?

.code
main proc
    mov ax,@data
    mov ds,ax
    
    lea dx,msg1
    mov ah,9
    int 21h

    call input
    mov var1,dl

    lea dx,msg2
    mov ah,9
    int 21h

    call input
    mov var2,dl

    mov bl,var1
    mov cl,var2
    cmp bl,cl
    jle @result
    jmp @result2

    @result:
        lea dx,msg3
        mov ah,9
        int 21h
        jmp @exit

    @result2:
        lea dx,msg4
        mov ah,9
        int 21h
        jmp @exit

    @exit:
        mov dl,10
        mov ah,4ch
        int 21h    

main endp

input proc
    xor bx,bx
    xor cx,cx
    xor dx,dx
    mov cl,4

    @input1:
        mov ah,1
        int 21h
        cmp al,0dh
        je line

        cmp al,39h
        jg @letter

        sub al,30h
        jmp @shift

    @letter:
        sub al,37h

    @shift:
        shl bl,cl
        add bl,al
        jmp @input1

    line:
        mov dx,bx
    ret
input endp

end main