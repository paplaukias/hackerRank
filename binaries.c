#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

static int one_counter = 0, max = 0;

int recursive_division(int in) {
  int result, remainder = in % 2;
  if(in > 1) {
    result = recursive_division(in / 2);
  } else {
    result = in;
  }
  if(remainder == 1) {
    one_counter++;
    if(one_counter > max) max = one_counter;
  } else {
    one_counter = 0;
  }
  // printf("%d", remainder);
  return result;
}

int main() {
  int n;
  int result;
  scanf("%d",&n);
  if(n < 1 || n > 1000000) return 0;
  recursive_division(n);
  printf("\r\n%d\r\n", max);
  return 0;
}