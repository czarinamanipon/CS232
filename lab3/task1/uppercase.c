#include <stdio.h>

int main(int argc, char *argv[]) {
   char str[10090];
   int ch, n = 0;
   printf("Enter characters...\n");
   while ((ch = getchar()) != EOF && n < 1000) {
      str[n] = ch;
      //printf("Ch = %i, n = %i\n", ch, n);
      ++n;
   }
   for (int i = 0; i < n; ++i){
       if((str[i] >= 97) && (str[i] <= 122)){
           putchar(str[i] - 32);
       } else{
           putchar(str[i]);
       }
   }

    return 0;
}