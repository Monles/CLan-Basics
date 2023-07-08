#include <stdio.h>
int factorial(int x);
int main() {
  /* testing code */
  printf("0! = %i\n", factorial(0));
  printf("1! = %i\n", factorial(1));
  printf("3! = %i\n", factorial(3));
  printf("5! = %i\n", factorial(5));
}

/* define your function here (don't forget to declare it) */
int factorial(int x) {

  int temp = 1;
  if (x > 1) {
    for (int i = 1; i <= x; i++) {
      temp *= i;
    }
    return temp;

  } else {
    return 1;
  }
}