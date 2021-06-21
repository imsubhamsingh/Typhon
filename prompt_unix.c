#include <stdio.h>
#include <stdlib.h>

#include <editline.h>
/* 
for editline install libedit-dev
in linux and compile using -ledit flag.
*/


int main(int argc, char** argv){

    /* Print Version and Exit Information */
    puts("Typhon Version 1.1.0");
    puts("Press ctrl+c to exit");

      /* In a never ending loop */
      while(1){
        
        /* Output our prompt and get input */
        char* input = readline("Typhon> ");

        /* Add input to history */
        add_history(input);

        /* Echo input back to user */
        printf("You just said %s\n", input);

        /* Free retrived input */
        free(input);
      }   
    return 0;
}
