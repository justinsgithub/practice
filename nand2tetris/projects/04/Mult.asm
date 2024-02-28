// a program to set R2 = R0 * R1

// @VALUE sets A register which can be used as data (D=VALUE) or memory address (M = RAM[VALUE])
@R2 // sets M to R2
M=0 // set value at R2 to 0

(LOOP)
@R1 // set memory address to the multiplier
D=M // sets D to value stored at R1
@END
D;JEQ // If R1 = 0 we are done multiplying, end program

@R1
M=M-1 // decrement multiplier
@R0
D=M // set D to number being multiplied
@R2
M=M+D // add number being multiplied to R2
@LOOP // repeat until R1 = 0
0;JMP // no need to test, we do that at beginning of the loop


(END) // (LABEL) labels the memory address for this instruction for convenience
@END
0;JMP // Infinite loop


