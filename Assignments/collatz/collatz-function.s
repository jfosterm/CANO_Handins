.section .text  # specifies the beginning of the 'text' or code section
.global collatz # makes the name 'collatz' visible to the linker

collatz:        # This is the label we jump to, when the collatz function
                # is called in the C program
                
movq $0, %r8      # init counter
    
loop: 
cmpq $1, %rcx    # Check if input n is equal 1
je retu          # if rcx = 1, we return

movq %rcx, %rax    # We store the value of rcx in rax reg 

shlq $63, %rax
cmpq $0, %rax
jne noteven     # if remainder is 0, then we continue, else jump to noteven

shrq $1, %rcx     # even (n/2) 
jmp con         # now we continue

noteven:        # (3n + 1)
movq %rcx, %rax    # store value of rcx to rax
shlq $1, %rcx
addq %rax, %rcx
incq %rcx         # +1 to result 

con:
incq %r8          # increment counter
jmp loop        # loop it back

retu:
movq %r8, %rax     # We write our counter to rax (return value)
                    # Jump back to the c-file where collatz was called
ret             