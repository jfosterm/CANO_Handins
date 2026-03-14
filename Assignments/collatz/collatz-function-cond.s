.section .text  # specifies the beginning of the 'text' or code section
.global collatz # makes the name 'collatz' visible to the linker

collatz:        # This is the label we jump to, when the collatz function
                # is called in the C program
                
movq $0, %r8      # init counter
cmpq $1, %rcx
je retu

loop: 
    # Even
    movq %rcx, %r9
    shrq $1, %r9           

    # Uneven
    movq %rcx, %rax
    movq %rcx, %rdx    
    shlq $1, %rdx
    addq %rax, %rdx
    incq %rdx          

    movq %rcx, %rax    # Compare 
    shlq $63, %rax
    cmpq $0, %rax

    cmoveq %r9, %rcx
    cmovneq %rdx , %rcx
    
    incq %r8       
    cmpq $1, %rcx    # Check if input n is equal 1
    jne loop         # if rcx = 1, we return

retu:
    movq %r8, %rax     # We write our counter to rax (return value)
                        # Jump back to the c-file where collatz was called
    ret             