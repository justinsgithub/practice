// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen
// by writing 'black' in every pixel;
// the screen should remain fully black as long as the key is pressed.
// When no key is pressed, the program clears the screen by writing
// 'white' in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Draw a single black dot at the screen's top left corner:
// @SCREEN // Set the A register to point to the memory
// word that is mapped to the 16 left-most
// pixels of the top row of the screen.
// M=1 // Blacken the left-most pixel.

@512
D=A
@columns
M=D
@tempcolumns
M=D
@256
D=A
@rows
M=D
@temprows
M=D
@wordsperrow
M=0
@8192
D=A
@totalwords
M=D
@temptotalwords
M=0
@doreset
M=1

// calculate total words, tested successfully. Manually entering or takes too long to test.
//(DIVIDECOLUMNS)
//@tempcolumns
//D=M
//@TOTALWORDS
//D;JEQ
//
//@wordsperrow
//M=M+1
//@16
//D=A
//@tempcolumns
//M=M-D
//@DIVIDECOLUMNS
//0;JMP
//
//(TOTALWORDS)
//@temprows
//D=M
//@END
//D;JEQ
//
//@temprows
//M=M-1
//@wordsperrow
//D=M
//@totalwords
//M=M+D
//@TOTALWORDS
//0;JMP
//
// reset values to fill or clear screen

(LISTENKEYS)
@SCREEN
D=A
@currentword // current memory word being filled or cleared
M=D
@totalwords
D=M
@temptotalwords // reset total words for next screen fill
M=D
@KBD
D=M
@CLEAR
D;JEQ
@FILL
0;JMP

(FILL)
// test to see if all screen pixels have been filled
@temptotalwords
D=M
@LISTENKEYS
D;JEQ
 
@0
D=A-1
@currentword
A=M // set address to value at currentword (SCREEN start)
M=D // set address / word to 1s
@currentword
M=M+1 // increase memory word by 1 for next loop
@temptotalwords
M=M-1
@FILL
0;JMP

(CLEAR)
// test to see if all screen pixels have been filled
@temptotalwords
D=M
@LISTENKEYS
D;JEQ
 
@0
D=A
@currentword
A=M // set address to value at currentword (SCREEN start)
M=D // set address / word to 0s
@currentword
M=M+1 // increase memory word by 1 for next loop
@temptotalwords
M=M-1
@CLEAR
0;JMP

(END) // (LABEL) labels the memory address for this instruction for convenience
@END
0;JMP // Infinite loop
