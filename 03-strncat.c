#include <stdio.h>
#include <string.h>
int main() {
  char a[20] = "Hello";
  char b[20] = "Alice";
  strncat(a, b, 3);
  printf("%s\n",a);
  strncat(a,b, 20);
  printf("%s\n", b);
}