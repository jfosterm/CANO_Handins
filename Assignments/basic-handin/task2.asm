ZERO R0
INC R0
INC R0
INC R0
ZERO R1
INC R1
INC R1
INC R1 
INC R1

SUB R6, R1, R0      ; R6 = R1 - R0
SUB R7, R0, R1      ; R7 = R0 - R1
INC R7              ; R7 + 1
INC R6              ; R6 + 1
AND R7, R7, R6      ; 
