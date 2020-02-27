%{

#include <stdio.h>

int p_names   = 0;
int acronyms  = 0;

%}
PName [A-Z].*
AC    [A-Z]*
%%

{AC}    {printf("Acronyms:    %s\n",yytext);acronyms++;}
{PName} {printf("Proper Name: %s\n",yytext);p_names++;}
%%


int main(void) {
    yyin= fopen("PriyankA.txt","r");
    yylex();
    printf("\nTotal Proper Names:  %3d\n", p_names);
    printf("Total Acronyms:  %3d\n", acronyms); 
    return 0;
}

int yywrap() {
    return 1;
}
