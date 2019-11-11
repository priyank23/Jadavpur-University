.model small
.stack 100
.data

    msg1 db "Enter first number:" , 13,10, "$"
    msg2 db "Enter second number:",13,10,"$"
    msg3 db "Sum: ",13,10,"$"
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
    
    lea dx,msg3
    mov ah,9
    int 21h

    mov bl,var1
    mov cl,var2
    add bl,cl
    jc @pc1
    jmp @output
    
    @pc1:
        mov ah,2
        mov dl,'1'
        int 21h
        jmp @output

    @output:
        xor dx,dx
        mov ah,2
        mov dl,bl
        shr dl,1
        shr dl,1
        shr dl,1
        shr dl,1
        cmp dl,9
        jle @print_num
        add dl,7h

       @print_num:
        add dl,30h
        int 21h
    
        mov dl,bl
        and dl,0fh
        cmp dl,9
        jle @print_letter1
        add dl,7h

        @print_letter1:
        add dl,30h
        int 21h      
        jmp @exit
    
    @exit:
        mov ah,4ch
        int 21h
        
main endp
;taking 8bit numbers input
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