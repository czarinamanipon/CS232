#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len = 0, i, n, j = 0, x = 0;
  char buf[MAX_BUF];
  
  printf("Enter a string...\n");
  for(j = 0; j < MAX_BUF; j++){
      buf[j] = fgets(buf, MAX_BUF, stdin);
      len++;
      if (buf[j] == "\n")
        break;
  }
      
  do {
      n = buf[x];
      printf("length = %i \n", len);
      printf("buf[%i] = %c\n", x, buf[x]);
      if((n >= 97) && (n <= 122)){
          letter_frequency[n]++;
      } else if ((n >= 65) && (n <= 90)){
          letter_frequency[n - 32]++;
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