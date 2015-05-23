#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i = 0, j = 0, k = 0;
  char *a, *b, *c;
  a = (char*) malloc(100);
  b = (char*) malloc(100);
  printf("Digite a primeira string:");
  scanf("%s", a);
  printf("Digite a segunda string:");
  scanf("%s", b);
  c = (char*) malloc(strlen(a) + strlen(b));
  while (i < (strlen(a) + strlen(b))) {
    if (j < strlen(a)) {
      c[i] = a[j];
      i += 1;
      j += 1;
    }
    if (k < strlen(b)) {
      c[i] = b[k];
      i += 1;
      k += 1;
    }
  }
  c[i] = '\0';
  printf("%s\n", c);
  free(a);
  free(b);
  free(c);
  system("PAUSE");	
  return 0;
}
