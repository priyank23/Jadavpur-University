%{
    int yyerror ();
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>
   
%}
%union {float num;}
%token <num> ID
%type <num> T E factor
%start S

%%

S   : E '\n'        {printf ("Result: %f\n",(float)$1);exit(0);}
       ;
E    : T                           {$$ = (float)$1;}
       | E '+' T                   {$$ = $1 + $3;}
       | E '-' T                   {$$ = $1 - $3;}
       ;
T   : factor                         {$$ = (float)$1;}
       | T '*' factor                {$$ = $1 * $3;}
       | T '/' factor                {$$ = $1 / $3;}
       | T '%' factor                {$$ = fmod($1,$3);}
       | T '^' factor                {$$ = pow($1,$3);}
       ;
factor : ID                         {$$ = $1;}
       | '(' E ')'                    {$$ = $2;}
       ;

%%



int main()
{
    printf("Enter the Expression: ");
    yyparse();
}

int yyerror ()
{
    printf("Syntax Error!\n");
    exit(1);
}


