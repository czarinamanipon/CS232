/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdio.h>
#include <string.h>
void CS232(char* src) {
     char *srcptr, *replaceptr;
     int srcLength = sizeof(src);
     char replacement[15] = "232 is awesome!";
     replaceptr = replacement;
     srcptr = src;
     if (srcLength <= 15) {
         for (int i = 0; i < 15; i++){
              *(srcptr++) = *(replaceptr++);
         }
         src = srcptr;
     }
}

char * replace_string() {
    char str[15];
    char * strptr;
    CS232(str);
    strptr = str;
    return strptr;

}

int main(int argc, char ** argv) {
    char * ret = replace_string();
    printf("replaced string = %s\n", ret);
    return 0;
}
