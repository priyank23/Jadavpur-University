.model small
.stack 100
.data

    msg db "Do you want to exit(y/[n]):",13,10,"$"
    msg2 db "Loop continues...",13,10,"$" 

.code
main proc
    mov ax,@data
    mov ds,ax
    @loop:
        lea dx,msg
        mov ah,9
        int 21h

        mov ah,1
        int 21h

        cmp al,'y'
        je @exit

        mov dl,10
        mov ah,2
        int 21h

        lea dx,msg2
        mov ah,9
        int 21h
        jmp @loop

    @exit:
        mov ah,4ch
        int 21h
        
main endp
end main