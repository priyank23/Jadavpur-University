#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<string.h>
#include <X11/XKBlib.h>


#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdbool.h>


struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  //raw.c_cc[VMIN]=0;
  //raw.c_cc[VTIME]=1;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
void get_bangali_lower(char c)
{
	
	if(c=='a'||c=='A') printf("\u09CB ");
	if(c=='b'|| c=='B') printf("\u09AC ");
	if(c=='c'|| c=='C') printf("\u09AE ");
	if(c=='d'||c=='D') printf("\u0985 ");
	if(c=='e'|| c=='E') printf("\u0986 ");
	if(c=='f' ||c=='F') printf("\u0987 ");
	if(c=='g'||c=='G') printf("\u098A ");
	if(c=='h'|| c=='H') printf("\u09AA ");
	if(c=='i'|| c=='I') printf("\u0997");
	if(c=='j'|| c=='J') printf("\u09B0 ");
	if(c=='k'|| c=='K') printf("\u0995 ");
	if(c=='l'|| c=='L') printf("\u09A4 ");
	if(c=='m'|| c=='M') printf("\u09B8 ");
	if(c=='n'|| c=='N') printf("\u09B2 ");
	if(c=='o'|| c=='O') printf("\u09A6 ");
	if(c=='p'|| c=='P') printf("\u099C ");
	if(c=='q'|| c=='Q') printf("\u0994 ");
	if(c=='s'||c=='S') printf("\u098F ");
	if(c=='r'||c=='R') printf("\u09C0 ");
	if(c=='t'||c=='T') printf("\u0989 ");
	if(c=='u'|| c=='U') printf("\u09B9 ");
	if(c=='v'|| c=='V') printf("\u09A8 ");
	if(c=='w'|| c=='W') printf("\u0990 ");
	if(c=='y'|| c=='Y') printf("\u09AC ");
	if(c=='[')printf("\u09A1 ");
	if(c==']')printf("\u099E ");
	if(c==';') printf("\u099A ");
	if(c=='\'')printf("\u099F ");
	if(c=='/') printf("\u09AF ");	
	if(c=='1') printf("\u09E7 ");
	if(c=='2') printf("\u09E8 ");
	if(c=='3') printf("\u09E9 ");
	if(c=='4') printf("\u09EA ");
	if(c=='5') printf("\u09EB ");
	if(c=='6') printf("\u09EC ");
	if(c=='7') printf("\u09ED ");
	if(c=='8') printf("\u09EE ");
	if(c=='9') printf("\u09EF");
	if(c=='\\') printf("|");
	//if(c==' ') printf(" ");
	//if(c=='\r') printf("\n");
	printf("\n");
}
void get_bangali_higher(char c)
{
	if(c=='a'||c=='A') printf("\u0993 ");	
	if(c=='y'|| c=='Y') printf("\u09AD ");
	if(c=='u'|| c=='U') printf("\u0999 ");
	if(c=='i'|| c=='I') printf("\u0998 ");
	if(c=='o'|| c=='O') printf("\u09A7 ");
	if(c=='p'|| c=='P') printf("\u099D ");
	if(c=='r'||c=='R') printf("\u0998 ");
	if(c=='{'|| c=='[') printf("\u09A2 ");
	//if(c==']'|| c==']') printf("\u");
	if(c=='h'|| c=='H') printf("\u09AB ");
	if(c=='k'|| c=='K') printf("\u0996 ");
	if(c=='l'|| c=='L') printf("\u09A5 ");
	if(c==':'|| c==';') printf("\u099B ");
	if(c=='\"'|| c=='\'') printf("\u09A0 ");
	if(c=='c'|| c=='C') printf("\u09A3 ");
	if(c=='m'|| c=='M') printf("\u09BD ");
	if(c=='?'|| c=='/') printf("\u09DF ");
	if(c=='v'|| c=='V') printf("\u09DC ");//EXTRA 'ড়'
	if(c=='B'|| c=='b') printf("\u09DD ");//EXTRA 'ঢ়'
	//if(c==' ') printf(" ");
	//if(c=='\r') printf("\n");
	printf("\n");
}
int main(){
    enableRawMode();
    char c;
    while (read(STDIN_FILENO, &c, 1) ==1)
	{
		
    Display* dpy = XOpenDisplay(NULL);
    char keys_return[32];
    XQueryKeymap( dpy, keys_return );
    KeyCode kc2 = XKeysymToKeycode( dpy, XK_Shift_L );
    bool bShiftPressed = !!( keys_return[ kc2>>3 ] & ( 1<<(kc2&7) ) );	
	if(bShiftPressed==true) {
		printf("");    		
		get_bangali_higher(c);
	} else {
    		get_bangali_lower(c);
	}
}
}

  
