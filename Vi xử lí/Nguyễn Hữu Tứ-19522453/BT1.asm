.MODEL SMALL
.STACK 100H
.DATA
 under_line DB 0AH,0DH,"$" 
 NUMBER1 dd 52521452h  
 NUMBER2 dd 25251325h           
 KQ dd ?  
 .CODE
 MAIN PROC
    CALL ADD_2_NUMBER  
    CALL SUB_2_NUMBER 
 MAIN ENDP
;----------------------------------
ADD_2_NUMBER PROC
      mov      ax, @data  
      mov      ds, ax  
      mov      ax, word ptr NUMBER1          
      mov      bx, word ptr NUMBER1+2       
      mov      cx, word ptr NUMBER2         
      mov      dx, word ptr NUMBER2+2                   
      add      ax, cx                    
      mov      word ptr KQ, ax  
      adc      bx, dx       
      mov      word ptr KQ+2, bx      
      mov      bx, word ptr KQ+2      
      mov      dh, 2 
      jnc LOOP1
      mov ah,2
      mov dl,'1'
      int 21h 
 LOOP1:     mov      ch, 04h                
      mov      cl, 04h                  
 LOOP2:     rol      bx, cl                
      mov      dl, bl                
      and      dl, 0fH              
      cmp      dl, 09                
      jbe      LOOP4  
      add      dl, 07                   
 LOOP4:  add      dl, 30H  
      mov      ah, 02                    
      int      21H  
      dec      ch                        
      jnz      LOOP2   
      dec      dh  
      cmp      dh, 0  
      mov     bx, word ptr KQ         
      jnz      LOOP1  
      mov      ah, 4ch   
 RET    
 ADD_2_NUMBER ENDP             
;---------------------------------
SUB_2_NUMBER PROC
      lea dx,under_line
      mov ah,9
      int 21h
      
      mov      ax, @data  
      mov      ds, ax  
      mov      ax, word ptr NUMBER1          
      mov      bx, word ptr NUMBER1+2       
      mov      cx, word ptr NUMBER2         
      mov      dx, word ptr NUMBER2+2                   
      sub      ax, cx                    
      mov      word ptr KQ, ax  
      sub      bx, dx       
      mov      word ptr KQ+2, bx      
      mov      bx, word ptr KQ+2      
      mov      dh, 2  
 LOOP11:     mov      ch, 04h                
      mov      cl, 04h                  
 LOOP21:     rol      bx, cl                
      mov      dl, bl                
      and      dl, 0fH              
      cmp      dl, 09                
      jbe      LOOP31  
      add      dl, 07                   
 LOOP31:  add      dl, 30H  
      mov      ah, 02                    
      int      21H  
      dec      ch                        
      jnz      LOOP21   
      dec      dh  
      cmp      dh, 0  
      mov     bx, word ptr KQ         
      jnz      LOOP11  
      mov      ah, 4ch                  
      int      21h   
      RET    
      SUB_2_NUMBER ENDP        
;---------------------------------
      
END MAIN
      
