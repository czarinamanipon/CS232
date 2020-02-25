/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int main()
{
  char Strings[NUM][LEN];
  int i, j;

  printf("Please enter %d strings, one per line:\n", NUM);

  /* Write a for loop here to read NUM strings.
     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */
  
  for(i = 0; i < NUM; i++){
      fgets(Strings[i], LEN - 2, stdin);
  }

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */
  for(i = 0; i < NUM; i++){
      printf("%c", Strings[i]);
  }
  
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order
     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) The swap of two strings must be done by copying them 
            (using a temp variable of your choice) one character at a time,
            without using any C string library functions.
            That is, write your own while/for loop to do this.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */
  char temp;
  for(i = 1; i < NUM; i++){
      if(Strings[i][j] > Strings[i + 1][j]){
          temp = Strings[i + 1];
          Strings[i + 1] = Strings[i];
          Strings[i] = temp;
          
      } else if(Strings[i][j] == Strings[i + 1][j]){
          for(j = 0; j < strlen(Strings[i]); j++){
              if(Strings[i][j + 1] > Strings[i + 1][j + 1]){
                  temp = Strings[i + 1];
                  Strings[i + 1] = Strings[i];
                  Strings[i] = temp;
                  break;
              }
          }
      }else if(Strings[i][j] < Strings[i + 1][j]){
          temp = Strings[i];
          Strings[i] = Strings[i + 1];
          Strings[i] = temp;
      }
  }
  
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  for(i = 0; i < NUM; i++){
      puts(Strings[i]);
  }

}