.model small
.stack 100
.data
    msg db "Characters:",13,10,"$"
.code
main proc
    mov ax,@data
    mov ds,ax

    lea dx,msg
    mov ah,9
    int 21h

    mov bl,'A'
    mov cl,26
    mov si,0
    mov ah,2
    @Aloop:
        mov dl,bl
        int 21h
        inc bl
        ;mov dl,10
        ;int 21h
        inc si
        loop @Aloop
    mov dl,10
    int 21h
    mov ah,4ch
    int 21h
main endp
end main
