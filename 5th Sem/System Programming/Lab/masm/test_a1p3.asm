.model small
.stack 100
.data

    msg1 db "Enter first number:" , 13,10, "$"
    msg2 db "Enter second number:",13,10,"$"
    msg3 db "Sum: ",13,10,"$"
    var1 db 00h
    var2 db 00h
    sum db 0,0,0
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

    xor bx,bx
    xor cx,cx 
    mov bl,var1
    mov cl,var2
    add bx,cx
    jc @pc1 
    jmp @output
    
    @pc1:
        mov sum[0],'1'
        int 21h
        jmp @output

    @output:
        mov dx,bx
        call print_hex
        jmp @exit
    
    @exit:
       ; mov ah,4ch
       ; int 21h
    ret
main endp

print_hex proc
    push ax
    push bx
    push cx
    push dx
    
    mov cx,3
c_loop:
    dec cx
    mov ax, dx
    
    shr dx,1
    shr dx,1
    shr dx,1
    shr dx,1
    
    and ax,0fh
    
    mov bx, offset sum
    add bx,cx
    
    cmp ax,0ah
    jl set_digit
    add al,07h

set_digit:
    add al,30h
    mov [bx],al
    
    cmp cx,0
    jne c_loop
    
    lea dx,sum
    mov ah,9
    int 21h
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
print_hex endp

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