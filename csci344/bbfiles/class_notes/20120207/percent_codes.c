#include <stdio.h>

int main()
{
  int x=99;
  float fl=6.54;

  printf("Todd\nGibson\nWas here\n");
  /* output:
  Todd
  Gibson
  Was here
  */
  printf("Todd\nGib%dson\nW%fas here\n",x,fl);
  /* output:
  Todd
  Gib99son
  W6.540000as here
  */
}
