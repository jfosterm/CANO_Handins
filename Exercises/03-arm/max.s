.data                   // start of data section
m:      .quad 5         // Stores "5" using 8 bytes of precision
.syntax unified         // Switch to unified syntax

smallermsg: .ascii "It was smaller.\n" // some messages for printing stuff 
largermsg:  .ascii "It was larger.\n"
endmsg:

.section .text          // start of text section
        
.global  _start         // make _start symbol visible
_start: 
        ldr r0, =m      // Store the address of variable "m" into
        ldr r0,[r0]     // Store the value "m" into r0
        mov r1,10       // store "10" in r1 
        cmp r0, r1      // compare r1 and r0
        bpl larger      // if (m > 10) jump to larger.
        b    smaller    // else jump to smaller.

larger:
        ldr r1, =largermsg             // Address of the message to write
        ldr r2, =(endmsg-largermsg)    // Size of the message
        b print

smaller:
        ldr r1, =smallermsg            // Address of the message to write
        ldr r2, =(largermsg-smallermsg)// Size of the message
        b print

print:
        mov r0,1        // file descriptor: 1 for standard output 
        mov r7,4        // Write system call  
        swi 0           // System call!
        // now we exit
        mov r0,0        // exit code 0; standard for 'no error' exit
        mov r7,1        // sys_exit 
        swi 0           // System call
