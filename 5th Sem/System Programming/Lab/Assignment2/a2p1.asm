.model small
.stack 10h
.data
    var1 dw 0
    var2 dw 0
    prompt1 db "Enter First Number:",32,"$"
    prompt2 db "Enter Second Number:",32,"$"
    prompt3 db "Sum:",32,"$"
    prompt4 db "Difference:",32,"$"
.code
main proc
    mov ax,@data
    mov ds,ax

    lea dx,prompt1
    mov ah,9
    int 21h

    call input
    mov var1,bx

    lea dx,prompt2
    mov ah,9
    int 21h
    
    call input
    mov var2,bx

    mov bx,var1
    mov ax,var2

    add bx,ax
    jnc print1
    mov dl,'1'
    mov ah,2
    int 21h
print1:
    lea dx,prompt3
    mov ah,9
    int 21h
    
    call output

    mov bx,var1
    mov ax,var2
    cmp bx,ax
    jge diff
    mov dl,'-'
    mov ah,2
    int 21h
    mov bx,var2
    mov ax,var1
diff:
    sub bx,ax
    lea dx,prompt4
    mov ah,9
    int 21h
    
    call output

    mov ah,4ch
    int 21h

main endp

input proc                     ; 16-bit input final data in bx and dx
    push cx
    xor bx,bx
    xor cx,cx
    xor dx,dx
    mov cl,1

    mov ah,1
    int 21h

    @input1:
        cmp al,0dh
        je line

        cmp al,39h
        jg @letter

        and al,0fh
        jmp @shift

    @letter:
        sub al,37h

    @shift:
        shl bh,1
        shl bh,1
        shl bh,1
        shl bh,1
        add bh,al
        int 21h

        inc cl
        cmp cl,2
        jle @input1
    mov cl,1
    @input2:
        cmp al,0dh
        je line

        cmp al,39h
        jg @letter2

        and al,0fh
        jmp @shift2

    @letter2:
        sub al,37h

    @shift2:
        shl bl,1
        shl bl,1
        shl bl,1
        shl bl,1
        add bl,al
        int 21h
        inc cl
        cmp cl,2
        jle @input2

    line:
        cmp bl,00
        jne exit
        mov bl,bh
        mov bh,0
    exit:  mov dx,bx
        pop cx
    ret
input endp

output proc                  ;16-bit ouput data in bx
    xor dx,dx
    push cx
    mov ah,2
    mov dl,bh
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

    mov dl,bh
    and dl,0fh
    cmp dl,9
    jle @print_letter1
    add dl,7h

    @print_letter1:
    add dl,30h
    int 21h

    mov dl,bl
    shr dl,1
    shr dl,1
    shr dl,1
    shr dl,1
    cmp dl,9
    jle @print_num2
    add dl,7h

    @print_num2:
    add dl,30h
    int 21h

    mov dl,bl
    and dl,0fh
    cmp dl,9
    jle @print_letter2
    add dl,7h

    @print_letter2:
    add dl,30h
    int 21h

    mov dl,10
    int 21h
    pop cx    
    ret
output endp
end main
