#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len = 0, i, x = 0;
  char buf[MAX_BUF], n;
  int up = 0, lo = 0, charsum = 0, wordsum = 0, numsum =0;
  
  printf("Enter a string...\n");
  fgets(buf, MAX_BUF, stdin);
  len = strlen(buf);
  if(len > MAX_BUF){
      printf("Error: String exceed maximum length.");
      return 0;
  }
      
  //counts letter frequency
  do {
      n = buf[x];
      if((n >= 97) && (n <= 122)){
          letter_frequency[n - (32 + 65)]++;
          lo++;
          charsum++;
      } else if ((n >= 65) && (n <= 90)){
          letter_frequency[n - 65]++;
          up++;
          charsum++;          
      } else if((n >= 48) && (n <= 57)){
          numsum++;
          charsum++;
      } else if(((n >= 0) && (n <= 12)) || (n == 32)){
          wordsum++;
      }
      x++;
      len--;
  } while (len > 1);

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
  printf("Number of characters: %i\n", charsum);
  printf("Number of words: %i\n", wordsum);
  printf("Number of uppercase letters: %i \t Number of lowercase letters: %i\n", up, lo);
  printf("Number of numbers: %i\n", numsum);

}
