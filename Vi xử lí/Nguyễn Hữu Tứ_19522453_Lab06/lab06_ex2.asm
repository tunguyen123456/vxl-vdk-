.MODEL SMALL
org 100h 
.STACK 100H
.DATA
 ARRAY DB 15 DUP(?) 
 tb1 db "Nhap so luong phan tu cua mang: $"  
 tb2 db "Nhap phan tu cua mang: $" 
 tb3 db "Mang sau khi duoc sap xep la: $"  
 tb4 db ", $"
 under_line DB 0AH,0DH,"$" 
 
 SIZE DW ?  
 temp DW ?
    
.CODE 
MAIN PROC
        
            MOV AX,@DATA
            MOV DS,AX
            MOV AL , ARRAY
       OUTPUT_TB1:
            
            MOV AH,9
            LEA DX,tb1
            INT 21h

            MOV AH,01H
            CALL INPUT_NUMBER
            MOV SIZE,BX
                      
       OUTPUT_TB2:   
            MOV BX ,00H              
           
            MOV AH,9
            LEA DX,under_line
            INT 21h 
            
            MOV AH,9
            LEA DX,tb2
            INT 21h 
            
           
            MOV AH,9
            LEA DX,under_line
            INT 21h
             
       INPUT_ARRAY:
            
            MOV AH,9
            LEA DX,under_line
            INT 21h  
            
            PUSH CX
            CMP BX, CX
            JE OUTPUT_SORT
            PUSH BX      
            CALL INPUT_NUMBER                                
                                 
                                 
       STOP_INPUT:  
            POP BX       
            MOV SI, BX 
            MOV ARRAY[SI], CL
            INC BX
            POP CX    
            JMP INPUT_ARRAY                
        
       OUTPUT_SORT:        
            CALL SORTING 
           
            MOV AH,9
            LEA DX,tb3
            INT 21h
            MOV AX , 00H  
       
       
       CALL OUTPUT
            
      
                 
MAIN ENDP 
;////////////////////////////
 
INPUT_NUMBER PROC   
MOV BX,0h
MOV CX, 0h
next_digit:
MOV AH, 00h
INT 16h
MOV AH, 0Eh
INT 10h
CMP AL, 13  
JNE next
JMP STOPINPUT_NUMBER
next:
MOV BL,AL  
cmp BX,'0' 
JB not_minus
CMP BX, '9'
JA not_minus   
SUB BX,30h
MOV AX, CX
MOV CX, 0AH
MUL CX
MOV CX, AX
ADD CX, BX
JMP next_digit
not_minus:
MOV AH,4CH
INT 21h
RET
STOPINPUT_NUMBER:
RET
INPUT_NUMBER ENDP          
;////////////////////////////                  
SORTING PROC                               
PUSHA   
MOV CX,CS:SIZE
MOV BX,CX
SUB BX,1
MOV SI,1 
FOR_LOOP:
MOV DL,ARRAY[SI]
MOV DI,SI
SUB DI,1
WHILE_LOOP:
CMP DL,ARRAY[DI]
JGE EXIT_WHILE_LOOP
MOV AL,ARRAY[DI]
MOV ARRAY[DI+1],AL
SUB DI,1
CMP DI,0
JGE WHILE_LOOP
EXIT_WHILE_LOOP:
MOV ARRAY[DI+1],DL
ADD SI,1
DEC CX
CMP CX,1
JNE FOR_LOOP
SORT_DONE:
POPA
RET 4
    
SORTING ENDP
;///////////////////////////        
OUTPUT_C PROC 
MOV CS:temp, SI 
POP SI
PUSH AX
nextchar:
MOV AL, CS:[SI]
INC SI 
CMP AL, 0
JZ print
MOV AH, 0Eh
INT 10h
JMP nextchar
print:
POP AX
PUSH SI
MOV SI, CS:temp
RET 
;/////////////////////
OUTPUT PROC   
      
            CMP AX, CX  
            JE not_minus   
            
            MOV SI , AX           
            MOV BX, 00H
            MOV BL , ARRAY[SI]    
            PUSH CX 
            PUSH AX
           
            CMP BX, 0AH
            JNB OUTPUT_NEXT
            ADD BX ,30h
            MOV DX, BX
            MOV AH, 02H
            INT 21H
            JMP OUT_1 
       OUTPUT_NEXT:   
            MOV CX, 00H 
            MOV AX, BX
       DISPLAY:   
            MOV BX, 10D  
            MOV DX, 00H
            DIV BX 
            ADD DX, 30H   
            PUSH DX  
            INC CX 
            CMP AX, 0  
            JE END_DISPLAY      
            JMP DISPLAY                                                        
            
       END_DISPLAY:  
            POP DX
            MOV AH, 02H
            INT 21H     
            LOOP END_DISPLAY
                   
       OUT_1:   
            POP AX
            POP CX 
            INC AX 
            CMP AX, CX             
            JE not_minus 
            CALL OUTPUT_C
            DB ",",0    
           
           
        JMP OUTPUT    
        RET
OUTPUT ENDP  
;/////////////////////
                  
END MAIN        
        
        
        
        
                       

    
     
        
                                 