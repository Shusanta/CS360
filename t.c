/************* t.c file ********************/
#include <stdio.h>
#include <stdlib.h>
#include "shusanta_printing.h"

int *FP;

int main(int argc, char *argv[ ], char *env[ ])
{
  int a,b,c;
  printf("enter main\n");
  
  printf("&argc=%x argv=%x env=%x\n", &argc, argv, env);
  printf("&a=%8x &b=%8x &c=%8x\n", &a, &b, &c);

//(1). Write C code to print values of argc and argv[] entries

for(int i = 0; i<argc; i++){
    myprintf("argv[%d]=%s\n",i,argv[i]);
}


//part 3. print the env values
for(int i = 0; env[i] != 0; i++)
    myprintf("env[%d]=%s\n", i, env[i]);


  a=1; b=2; c=3;
  A(a,b);
  printf("exit main\n");
}

int A(int x, int y)
{
  int d,e,f;
  printf("enter A\n");
  // PRINT ADDRESS OF d, e, f
  printf("&d=%p &e=%p &f=%p\n",&d,&e,&f);
  d=4; e=5; f=6;
  B(d,e);
  printf("exit A\n");
}

int B(int x, int y)
{
  int g,h,i;
  printf("enter B\n");
  printf("&g=%p &h=%p &i=%p\n",&g,&h,&i);
  g=7; h=8; i=9;
  C(g,h);
  printf("exit B\n");
}

int C(int x, int y)
{
  int u, v, w, i, *p;

  printf("enter C\n");
  // PRINT ADDRESS OF u,v,w,i,p;

  printf("&u=%p &v=%p &w=%p &i=%p &p=%p\n",(void*)&u,(void*)&v,(void*)&w,(void*)&i,(void*)&p);

  u=10; v=11; w=12; i=13;

  FP = (int *)getebp();

//(2). Write C code to print the stack frame link list.

   printf("\nSTACK FRAME LINKED LIST\n");

   while(FP){
     printf("%p ->", (void*)FP);
     FP = (int *)*FP;
   }
   printf("0\n");
   p = (int *)&p;

//(3). Print the stack contents from p to the frame of main()
//YOU MAY JUST PRINT 128 entries of the stack contents.
  FP = (int *)getebp();
  while(*FP != 0)
    FP = (int *)*FP;
  printf("\nSTACK CONTENTS\n");
  for(int * i = p; i <= FP; i++)
    printf("%p: %x\n", (void*)i, *i);

//(4). On a hard copy of the print out, identify the stack contents
     //as LOCAL VARIABLES, PARAMETERS, stack frame pointer of each function.
}



