// void fact(unsigned start, unsigned end);

.globl fact
fact:
    push    {r4}
    /* r0 = "fact(%d)=%d\n"     */
    /* r1 = iterator            */
    /* r2 = result              */
    /* r3 = start               */
    /* r4 = end                 */
    mov     r3, r0      
    mov     r4, r1      
    ldr     r0, =string 
    mov     r1, #0      // iterator = 0
    mov     r2, #1      // result   = 1

    .WhileEnd:
        add     r1, r1, #1  // ++iterator
        mul     r2, r2, r1  // result *= iterator

        // if(iterator > end) return
        cmp     r1, r4
        bgt     .Return
        
        //if(iterator >= start) print
        cmp     r1, r3
        bge     .Print
        // else goto .WhileEnd
        b       .WhileEnd
        
    .Print:
        push    {lr}
        bl      printf
        pop     {pc}
        b       .WhileEnd

    .Return:
        pop     {r4}
        bx      lr

////////////////////////////////////////////////
    .string:
        .asciz  "fact(%d)=%d\n"
////////////////////////////////////////////////


    