#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len, i, n, j = 0, x = 0;
  char buf[MAX_BUF];
  
  printf("Enter a string...\n");
  for(j = 0; j < MAX_BUF; j++){
      buf[j] = fgets(buf, MAX_BUF, stdin);
      if (buf[j] == "\n")
        break;
  }
 
  len = strlen(buf);

  do {
      n = buf[x];
      printf("n = %c\n", n);
      if((n >= 'a') && (n <= 'z')){
          letter_frequency[n] = letter_frequency[n] + 1;
      } else if ((n >= 'A') && (n <= 'Z')){
          letter_frequency[n - 32] = letter_frequency[n - 32] + 1;
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