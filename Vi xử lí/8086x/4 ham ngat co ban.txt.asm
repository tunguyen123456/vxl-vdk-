.model small
.stack 100h
.data  
nhan db "Nguyen Huu Tu$"
.code
main proc
    
    ;write code this here 
    ;ham ngat loai 1
    ;cong dung: de nhap vao 1 ki tu tu ban phim  
    mov ah,1
    int 21h    
    
    
    ;ngat ah loai 2
    ;cong dung: de in ra 1 ki tu
    mov ah,2
    mov bl,36h
    int 21h  
    
    ;ham ngat ah loai 3
    ;cong dung: dung de in ra 1 chuoi ki tu 
    mov ax,@data
    mov ds,ax
    mov ah,9
    lea dx,nhan 
    int 21h
    
    
    
    ;ham ngat ah  4ch
    ;ham de dung chuong trinh  
    ; dat truoc main endp
    mov ah,4ch
    int 21h
    
    
    
    
main endp
end main