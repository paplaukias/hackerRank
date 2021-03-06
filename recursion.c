#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int factorial(int n) {
  if(n > 1) {
    return n * factorial(n-1); 
  } else {
    return n;
  }
}

int main() {
  int n; 
  scanf("%i", &n);
  if(n < 2 || n > 12) return 0;
  int result = factorial(n);
  printf("%d\n", result);
  return 0;
}