# YACC Example Programs

 1. Parsing an input for an expression [A*B*]
 2. Parsing an input for an expression [AsB|e] (equal number of A's and B's)
 3. Parsing an input to build a basic calculator.

*How to Compile*

 1. lex <lex_file>.l
 2. yacc <yacc_file>.y -d
 3. cc lex.yy.c y.tab.c -lm

*How to execute*

 1. ./a.out

*Checking results*

 1. Enter the input. Program responds with "Valid!" or "Invalid!".
 2. For Q2, enter the arithmetic expression. If the syntax is correct, the program generates expression output; else prints "Syntax Error". 































