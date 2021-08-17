.MODEL SMALL
.STACK 100H
.DATA
KQ db 8 dup('0')  
temp DW ?   
minus DB ? 
ten DW 10 
two DB 2      
tb db "Nhap so can chuyen: $ "
tb1 db "So sau khi chuyen la: $"

MAIN PROC 
mov ax,@data
mov ds,ax 
mov ah,9
lea dx,tb
int 21h
CALL INPUT
CALL PRINT_ARRAY
db 13, 10, 0       

CALL CONVERT_BIN   
mov ah,9
lea dx,tb1
int 21h

LEA SI, KQ
ADD SI, 7 
MOV AH, 0Eh
MOV CX, 8  

print_bin:
MOV AL, [SI]
INT 10h
DEC SI
LOOP print_bin  

MAIN ENDP  
;----------------------   

CONVERT_BIN PROC 
PUSH AX
PUSH DI
LEA DI, KQ
MOV AX, CX
MOV AH, 0 
next_step:
DIV CS:two
MOV [DI], AH
ADD [DI], 30h
INC DI
MOV AH, 0
CMP AX, 0
JNE next_step
do_reset:
CMP DI, OFFSET KQ + 8
JAE done
MOV [DI], '0'
INC DI
JMP do_reset
done:
POP DI
POP AX
RET
CONVERT_BIN ENDP 


;--------------------- 
INPUT PROC   
PUSH DX
PUSH AX
PUSH SI
MOV CX, 0
MOV CS:minus, 0
next:
MOV AH, 00h
INT 16h
MOV AH, 0Eh
INT 10h
CMP AL, 13 
JNE not_cr
JMP stop_input  
not_cr:
CMP AL, 8 
JNE checked
MOV AX, CX 
DIV CS:ten 
MOV CX, AX 
JMP next
checked:
CMP AL, '9'
JBE digit
JMP next 
digit:
PUSH AX
MOV AX, CX
MUL CS:ten
MOV CX, AX
POP AX
CMP DX, 0
SUB AL, 30h
MOV AH, 0
MOV DX, CX 
ADD CX, AX
JMP next

stop_input:
CMP CS:minus, 0
JE not_minus
NEG CX
not_minus:
POP SI
POP AX
POP DX
RET
INPUT ENDP
;----------------------------- 
PRINT_ARRAY PROC 
MOV CS:temp, SI 
POP SI
PUSH AX
next_char:
MOV AL, CS:[SI]
INC SI 
CMP AL, 0
JZ printed
MOV AH, 0Eh
INT 10h
JMP next_char
printed:
POP AX
PUSH SI
MOV SI, CS:temp
RET
PRINT_ARRAY ENDP
 
END MAIN