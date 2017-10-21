#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  char name[32];
  char phoneNumber[10];
} PhoneBook;

int main() {
  int n;
  
  scanf("%d", &n);
  if(n < 1 || n > 100000) return 0;
  PhoneBook phoneBook[n];
  
  for(int i=0; i<n; i++) {
    scanf("%s", phoneBook[i].name);
    scanf("%s", phoneBook[i].phoneNumber);
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
      if(strncmp(phoneBook[i].name, query, sizeof(query)) == 0) {
        contactExists = true;
        printf("%s=%s\r\n", phoneBook[i].name, phoneBook[i].phoneNumber);
      }
    }
    if(!contactExists) printf("Not found\r\n");
    memset(query, 0, sizeof(query));
  }

  return 0;
}