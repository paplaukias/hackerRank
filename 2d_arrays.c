#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int print_hourglass(int len, int array[][len], int x, int y) {
  int sum = 0;
  if(x > 3 || y > 3) {
    printf("too large x, y\r\n");
    return 0;
  }
  for(int i=x; i<x+3; i++) {
    for(int j=y; j<y+3; j++) {
      if(i != x+1) {
        printf("%d ", array[i][j]);
        sum += array[i][j];
      } else {
        if(j == y+1) {
          sum += array[i][j];
          printf("%d ", array[i][j]);
        } else {
          printf("  ");
        }
      }
    }
    printf("\r\n");
  }
  return sum;
}

void print_array(int len, int array[][len]) {
  for(int i=0; i<len; i++) {
    for(int j=0; j<len; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\r\n");
  }
}

int main(){
  int arr[6][6];
  for(int arr_i = 0; arr_i < 6; arr_i++){
    for(int arr_j = 0; arr_j < 6; arr_j++){
      scanf("%d",&arr[arr_i][arr_j]);
      if(arr[arr_i][arr_j] < -9 || arr[arr_i][arr_j] > 9) return 0;
    }
  }
  // printf("\r\n** RESULT **\r\n");
  // print_array(6, arr);

  int max, sum;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      sum = print_hourglass(6, arr, i, j);
      if(i==0 && j==0) max = sum;
      else {
        if(sum > max) max = sum;
      }
      printf("%d sum\r\n\n", sum);
    }
  }
  printf("%d\r\n", max);
  return 0;
}