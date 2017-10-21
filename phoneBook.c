#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int n;
  
  scanf("%d", &n);
  if(n < 1 || n > 100000) return 0;
  char name[n];
  char phoneNumber[n];  
  
  for(int i=0; i<n; i++) {
    scanf("%s", name[i]);
    scanf("%s", phoneNumber[i]);
  }

  char query[128];
  bool contactExists;
  int queryCounter = 0;
  int end;

  while(1) {
    if(queryCounter > 100000) return 0;
    contactExists = false;

    end = scanf("%s", query);
    if(end != 1) return 0;
    queryCounter++;
    
    for(int i=0; i<n; i++) {
      if(strncmp(name[i], query, sizeof(query)) == 0) {
        contactExists = true;
        printf("%s=%s\r\n", name[i], phoneNumber[i]);
      }
    }
    if(!contactExists) printf("Not found\r\n");
    memset(query, 0, sizeof(query));
  }

  return 0;
}