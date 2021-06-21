#include <stdio.h>

//declaring a buffer for user input of size 2048
static char input[2048];

int main(int argc, char **argv){
    
    /* Print Version and Exit Information */
    puts("Typhon Version 1.0.0");
    puts("Press ctrl+c to exit");

    /* In a never ending loop */
    while(1){

        /* Output our prompt */
        fputs("Typhon> ", stdout);

        /* Read a line of user input of maximun sizze 2048 */
        fgets(input, 2048, stdin);

        /* Echo input back to the user */
        printf("You just typed %s", input);
    }
    return 0;
}