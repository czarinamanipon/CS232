/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdio.h>
#include <string.h>
void CS232(char* src, int srcLength) {
     char *srcptr, *replaceptr;
     int srcLength = sizeof(src);
     printf("This is what src points to %c\n", src);
     printf("Size of src is %i\n", srcLength);
     char replacement[15] = "232 is awesome!";
     src = strcpy;
     replaceptr = &replacement;
     if (srcLength >= 15) {
         for (int i = 0; i < 15; i++){
             printf("srcptr = %c and replaceptr = %c\n", *srcptr, *replaceptr);
              *src++ = *replaceptr++;
              //strcpy(src, replacement);
         }
     }
}

char * replace_string() {
    char *strptr;
    char str[15];
    strptr = &str;
    CS232(strptr, str);
    return strptr;

}

int main(int argc, char ** argv) {
    char *ret = (int *)
 replace_string();
    printf("replaced string = %s\n", *ret);
    return 0;
}
