#include <stdarg.h>
#include <stdio.h>
void myprintf(char *, ...);



void prints(char *s) {
    while(*s){
        putchar(*s);
        s++;
    }
}

//Given: The following printu() function prints an unsigned integer.

typedef unsigned int u32;

char *ctable = "0123456789ABCDEF";

void rpu(u32 x, int BASE)
{  
    char c;
    if (x){
       c = ctable[x % BASE];
       rpu(x / BASE,BASE);
       putchar(c);
    }
}

void print_generic(u32 x, char * p, int base)
{
   prints(p);
   (x==0)? putchar('0') : rpu(x,base);
}

void printd(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    print_generic(x,"",10);
}

void printu(u32 x){
    print_generic(x,"",10);
}

void printx(u32 x){
    print_generic(x,"0x",16);
}

void printo(u32 x){
    print_generic(x,"0",8);
}

void myprintf(char *fmt, ...)      // C compiler requires the 3 DOTs
{
	va_list va;
	va_start(va,fmt);
    while(*fmt)
	{
		if(*fmt == '%')
		{
			fmt++;
			switch(*fmt)
			{
				case 'c': putchar(va_arg(va,int));
					break;
				case 's': prints(va_arg(va, char *));
					break;
				case 'u': printu(va_arg(va, u32));
					break;
				case 'd': printd(va_arg(va, int));
					break;
				case 'o': printo(va_arg(va, u32));
					break;
				case 'x': printx(va_arg(va, u32));
					break;
				default:
					return;
			}
		}

		else if(*fmt == '\n')
		{
			prints("\r\n");
		}

		else
		{
			putchar(*fmt);
		}
        fmt++;
	}
	va_end(va);
}



