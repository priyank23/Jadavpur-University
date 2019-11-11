.model small
.stack 10
.data
	var1 dw ?
	     dw ?
	var2 dw ?
	     dw ?
	ans dw 0,0,0,0

	msg1 db "Number 1:",32,"$"
	msg2 db "Number 2:",32,"$"
	msg3 db "Product:",32,"$"
.code
main proc
	mov ax,@data
	mov ds,ax

	lea dx,msg1
	mov ah,9
	int 21h

	call input
	mov var1+2,dx
	mov var1,bx
	
	lea dx,msg2
	mov ah,9
	int 21h

	call input
	mov var2+2,dx
	mov var2,bx

	call multiply32
	
	lea dx,msg3
	mov ah,9
	int 21h

	mov bx,ans+6
	call output

	mov bx,ans+4
	call output

	mov bx,ans+2
	call output
	
	mov bx,ans
	call output

	mov ah,4ch
	int 21h
main endp

multiply32 proc
	mov ax,0
	mov dx,0
	mov ax,var1
	mul var2
	mov ans,ax
	mov ans+2,dx
	
	mov ax,0
	mov dx,0
	mov ax,var1+2
	mul var2
	add ans+2,ax
	adc ans+4,dx
	adc ans+6,0

	mov ax,0
	mov dx,0
	mov ax,var1
	mul var2+2
	add ans+2,ax
	adc ans+4,dx
	adc ans+6,0

	mov ax,0
	mov dx,0
	mov ax,var1+2
	mul var2+2
	add ans+4,ax
	adc ans+6,dx 
ret
multiply32 endp

input proc
	push cx
    xor bx,bx
    xor cx,cx
    xor dx,dx
    
    mov ch,1
lab:    mov ah,1
	mov cl,1    
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
	mov dx,bx
	inc ch
	cmp ch,2
	jle lab
    line:
        cmp bl,00
        jne exit
        mov bl,bh
        mov bh,0
    exit:
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

    pop cx    
    ret
output endp
end main
