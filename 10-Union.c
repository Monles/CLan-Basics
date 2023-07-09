#include <stdio.h>
#include <stdlib.h>

union intParts {
  int theInt;
  char bytes[sizeof(int)];
};

int main() {

  union intParts parts;
  parts.theInt = 5968145; // arbitrary number > 255 (1 byte)

  printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", parts.theInt,
         parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

  // vs

  int theInt = parts.theInt;
  printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", theInt,
         *((char *)&theInt + 0), *((char *)&theInt + 1), *((char *)&theInt + 2),
         *((char *)&theInt + 3));

  // or with array syntax which can be a tiny bit nicer sometimes

  printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", theInt,
         ((char *)&theInt)[0], ((char *)&theInt)[1], ((char *)&theInt)[2],
         ((char *)&theInt)[3]);

         return 0;
}