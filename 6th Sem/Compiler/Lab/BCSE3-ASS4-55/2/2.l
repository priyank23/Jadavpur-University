%{
	#include "y.tab.h"
%}

DIGIT [0-9]\.?[0-9]*


%%

[ \t]
{DIGIT} {yylval.num = (float)atof(yytext); return ID;} // atof works ???
[-+*/%^()\n] {return yytext[0];}

%%

int yywrap (void) {return 1;}
