#include <stdio.h>

int main() {
  int a = 1;
  int *pointer_to_a = &a;
  printf("The value a is %d\n", a);
  printf("The value of a is also %d\n", *pointer_to_a);

  a += 5;

/* we just changed the variable again! */
*pointer_to_a += 1;

/* will print out 3 */
printf("The value of a is now %d\n", a);
  printf("The value of a is also now %d\n", *pointer_to_a);
  return 0;
}