.MODEL SMALL  
include 'emu8086.inc'
org 100h
.DATA
            tb1 db "Nhap so N: $"  
            tb2 db "Cac so nguyen to: $"  
            under_line DB 0AH,0DH,"$"    
            space db " $"
            outfile DB "c:\result.txt",0
            MAX dw ?     
            temp db ?
    
.CODE
MAIN PROC
        
            MOV AX,@DATA
            MOV DS,AX
    
        DISPLAY_TB1:    
   
            MOV AH,9
            LEA DX,tb1
            INT 21h
            CALL INPUT_NUMBER
    
              
            MOV AH,9
            LEA DX,under_line
            INT 21h
        DISPLAY_TB2:
            MOV AH,9
            LEA DX,tb2
            INT 21h   
            
            
            PUSH CX
            mov ah, 3ch
            mov cx, 0
            mov dx, offset  outfile
            int 21h
            jc EXIT
            mov MAX, ax
            POP CX
            
        
            MOV BX, 00H
            
        LOOP_PRINT:
            PUSH CX 
            MOV CX , BX
            
            CALL PRIME_FUNCTION  
            POP CX
            
            CMP AX, 01H
            
            JE PRINT  
            JMP NEXT      
MAIN ENDP   
;/////////////////////////// 
INPUT_NUMBER PROC                    
            MOV CX, 0H    
            MOV BX, 0H
        READ:
            MOV AH,01H  
            
            INT 21H
            
            CMP AL,0DH
            
            JZ EXIT1
            
            MOV BL,AL
            
            cmp BX,'0'                 
            JB EXIT                 
            cmp BX,'9'               
            JA EXIT               
            
            SUB BX, 30H         
                                     
            MOV AX, CX                                       
            MOV CX, 0AH                    
            
            MUL CX                         
            MOV CX, AX                      
            ADD CX, BX                     
                                    
            
            JMP READ   
        EXIT1:  
            RET  
                 
INPUT_NUMBER ENDP
     
;//////////////////////////
PRIME_FUNCTION PROC  
    
            PUSH CX 
            PUSH BX 
            CMP CX , 02H
            JB NOT_PRIME
             
           
            MOV BX, 02H    
LOOP_PRIME_NUMBER:
                        
            CMP BX, CX
            
            JB CONTINUE_PRIME_FUNCTION
            JMP  PRIME
            
CONTINUE_PRIME_FUNCTION: 
            MOV DX, 00H
            MOV AX, CX     
            DIV BX       
            CMP DX, 00H 
            JE NOT_PRIME   
            
            INC BX
            JMP LOOP_PRIME_NUMBER:
            
            
        PRIME:
            POP BX
            POP CX
            MOV AX, 01H
            RET    
            
            
             
        NOT_PRIME:
            POP BX
            POP CX
            MOV AX, 00H   
            RET  
       
PRIME_FUNCTION ENDP
;/////////////////////////////   
DISPLAY_NUMBER PROC
            CMP BX, 0AH
            JB LESS_THAN_10    
            MOV CX, 00H 
            MOV AX, BX
        CONTINUE_DISPLAY:   
            MOV BX, 10D  
            MOV DX, 00H
            DIV BX 
            ADD DX, 30H   
            PUSH DX  
            INC CX 
            CMP AX, 0  
            JE DISPLAY_END       
            JMP CONTINUE_DISPLAY
        
        
          
          
        
        LESS_THAN_10:
            ADD BX , 30h       
            
            CALL WRITE_FILE
            
            MOV DX, BX
            MOV AH, 02H
            INT 21H             
            RET                                           
            
        DISPLAY_END:  
            POP DX   
            MOV BX, DX
            
            CALL WRITE_FILE
            
            MOV AH, 02H
            INT 21H     
            
            
            LOOP DISPLAY_END
            
            RET         
DISPLAY_NUMBER ENDP                 
        
;///////////////////////////        
WRITE_FILE PROC
            
            PUSH BX
            PUSH cx 
            PUSH DX         
            mov ah, 40h   
            MOV temp, BL
            mov bx, MAX
            mov dx, offset temp
            mov cx, 01h
            int 21h
            POP DX   
            POP cx
            POP BX
            
            RET
            
WRITE_FILE ENDP 
;///////////////////////////
 PRINT:       
          
            
            
            PUSH CX 
            PUSH BX
            CALL DISPLAY_NUMBER     
        
            mov ah, 40h   
            MOV temp, 32d
            mov bx, MAX
            mov dx, offset temp
            mov cx, 01h
            int 21h   
            POP BX
            POP CX
            
           
            MOV AH,9
            LEA DX,space
            INT 21h           
NEXT:             
            INC BX 
            
            LOOP LOOP_PRINT
              
               
EXIT:  
            mov      ah, 4ch                  
            int      21h     
            RET         
 ;/////////////////////////////////
END  MAIN        
        
        
        
        
                       

    
     
        
                                 