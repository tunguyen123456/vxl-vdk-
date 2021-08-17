.MODEL SMALL
.STACK 100H
.DATA
temp DW ?   
tb1 db "Nhap N :$"     
under_line DB 0AH,0DH,"$" 
.CODE
MAIN PROC  
    MOV AX,@DATA
    MOV DS,AX
    MOV AH,9
    LEA DX,tb1
    INT 21h
    MOV AH,01H
    CALL INPUT_NUMBER
    MOV AH,9
    LEA DX,under_line
    INT 21h 
    DB 13,10,0   
    CALL OUTPUT
            
MAIN ENDP 
;////////////////////////
DISPLAY_ PROC
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
DISPLAY_ ENDP
;/////////////////////////   
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
JMP STOP_INPUT_NUMBER
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
STOP_INPUT_NUMBER:
RET
INPUT_NUMBER ENDP 

;////////////////////////
FIBO PROC
CMP CX,0H
JE OUT_FIBO
CMP CX,01H
JE OUT_FIBO
PUSH CX
DEC CX
CALL FIBO
MOV AX,BX
DEC CX
PUSH AX
CALL FIBO
POP AX
ADD BX,AX
POP CX
RET
OUT_FIBO:
MOV BX,01H
RET 
FIBO ENDP    
;////////////////////////

DISPLAY_OUT PROC
            CMP BX, 0AH
            JNB OUTPUT_NEXT
            ADD BX,30h
            MOV DX,BX  
            MOV AH,02H
            INT 21H     
            RET
       OUTPUT_NEXT:   
            MOV CX, 0H 
            MOV AX, BX
       DISPLAY:   
            MOV BX, 10D  
            MOV DX, 00H
            DIV BX 
            ADD DX, 30H   
            PUSH DX  
            INC CX 
            CMP AX, 0H  
            JE END_DISPLAY      
            JMP DISPLAY                                                        
            
       END_DISPLAY:  
            POP DX
            MOV AH, 02H
            INT 21H     
            LOOP END_DISPLAY  
            RET
DISPLAY_OUT ENDP 
;////////////////////////
OUTPUT PROC

            DEC CX
            PUSH CX                     
            CALL FIBO
            CALL DISPLAY_OUT
            POP CX
            CMP CX,01H
            JA OUT_SP
            JMP PRINT_1
            OUT_SP:  
            CALL DISPLAY_
            DB ", ",0           
            JMP OUTPUT
            PRINT_1:
            CALL DISPLAY_
            DB ", 1",0
            MOV      AH, 4CH                   
            INT      21H      
                               
OUTPUT ENDP
;///////////////////////           
END MAIN
