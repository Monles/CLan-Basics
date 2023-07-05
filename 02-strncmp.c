#include <stdio.h>
#include <string.h>
int main() {
  char *name = "Alice";

  if (strncmp(name, "Alice", 7) == 0) {
    printf("Alice!\n");
  } else {
    printf("Not Alice!\n");
  }
}