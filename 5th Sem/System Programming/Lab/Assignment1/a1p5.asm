.model small
.stack 100
.data
    msg db "Program termination initialised",13,10,"$"

.code
main proc
    mov ax,@data
    mov ds,ax
    lea dx,msg
    mov ah,9
    int 21h

    mov ah,4ch
    int 21h
main endp
end main