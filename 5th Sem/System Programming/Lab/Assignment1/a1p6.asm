.model small
.stack 100
.data
    msg1 db "Enter the character: ",13,10,"$"
    msg2 db "Entered character: ",13,10,"$"
    var db ?
.code
main proc
    mov ax,@data
    mov ds,ax

    lea dx,msg1
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    mov var,al

    mov dl,10
    mov ah,2
    int 21h

    lea dx,msg2
    mov ah,9
    int 21h

    mov dl,var
    mov ah,2
    int 21h

    mov ah,4ch
    int 21h
main endp
end main