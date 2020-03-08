%{
    int yyerror();
    #include<stdio.h>
    #include<stdlib.h>
%}
%token A B
%start s
%%
s: a b '\n' {return 0;}
a: A a | ;
b: B b | ;
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
