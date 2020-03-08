%{
    int yyerror();
    #include<stdio.h>
    #include<stdlib.h>
%}
%token A B
%start s
%%
s: A c B '\n' {return 0;}  
c: A c B | ;
%%

int main(void) {
    printf("Input: ");
    yyparse();
    printf("Valid!!\n");
    return 0;
}
int yyerror() {
    printf("Invalid!!\n");
    exit(1);
}
