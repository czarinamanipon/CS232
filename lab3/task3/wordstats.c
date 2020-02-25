#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len = 0, i, j = 0, x = 0, letterIndex;
  char buf[MAX_BUF], n;
  
  printf("Enter a string...\n");
  fgets(buf, MAX_BUF, stdin);
  len = strlen(buf);
  if(len > MAX_BUF){
      printf("Error: String exceed maximum length.");
      return 0;
  }
      
  do {
      n = buf[x];
      if((n >= 97) && (n <= 122)){
          letter_frequency[n - (32 + 65)]++;
      } else if ((n >= 65) && (n <= 90)){
          letter_frequency[n - 65]++;
      }
      x++;
      len--;
  } while (len > 1);

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}