ZERO R0
INC R0
ZERO R1
NOT R1

ZERO R6
NOT R6
SHR R6, 1
INC R6

Start:
    AND R3, R6, R0 
    AND R4, R6, R1 
    OR R5, R3, R4 
    JZ NoCarry
    XOR R5, R3, R4 
    JZ IsCarry      
    SHL R1, 1
    SHL R0, 1
    J Start

IsCarry:
    ZERO R7
    INC R7 
    J Continue

NoCarry:
    ZERO R7

Continue:

