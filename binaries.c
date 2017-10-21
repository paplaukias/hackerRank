#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int count_binary_ones(int dec) {
  return dec;
}

int main() {
  int n;
  int result;
  scanf("%d",&n);
  if(n < 1 || n > 1000000) return 0;
  printf("%d\r\n", count_binary_ones(n));
  return 0;
}