## Learning Lex tool

# The repository contains 2 folders.

 1. This folder contains 3 lex files.
	a. The lex file "1.a.l" that takes input from file PriyankA.txt and parses the file for finding the proper names and Acronyms in the file.

	b. The lex file "1.b.l" that takes input from file PriyankB.txt and parses the file for finding the number of lines, words and characters in the file.

	c. The lex file "1.c.l" that takes input from file PriyankC.txt and parses the file for finding the number of integers and floating point numbers in the file.

 2. This folder contains a lex file "2.l" that takes input from file Priyank.txt and parses the file for generating tokens and distinguishing the type of token as "Literal", "Assignment Operator", "Relational Operator", "Arithmetic Operator", "Keyword", "Identifiers" and "Special Symbols".

# Steps of executing the program.

 1. lex <fileName.l>
 2. cc lex.yy.c
 3. ./a.out

You can check the results in the corresponding output file as well.

