.model small
.stack 100
.data
    Num dw 0
    Den dw 0
    prompt db "Quotient: ",13,10,"$"
    prompt2 db "Dividend: ",13,10,"$"
    prompt3 db "Divisor: ",13,10,"$"
.code 
main proc
    mov ax,@data
    mov ds,ax

    lea dx,prompt2
    mov ah,9
    int 21h

    call inputDividend
    mov Num,bx

    lea dx,prompt3
    mov ah,9
    int 21h
    
    call inputDividend
    mov Den,bx

    mov dx,0000h
    mov ax,Num
    mov bx,Den

    div bx
    mov bx,ax

    lea dx,prompt
    mov ah,9
    int 21h
    
    call output

    mov ah,4ch
    int 21h
main endp

inputDividend proc                     ; 16-bit input final data in bx and dx
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
inputDividend endp

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