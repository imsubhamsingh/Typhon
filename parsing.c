#include <stdio.h>
#include <stdlib.h>

#include <editline.h>
#include "mpc.h"
/* 
for editline install libedit-dev
in linux and compile using -ledit flag.
*/


int main(int argc, char** argv){
  

    /* Create some parsers */
    mpc_parser_t* Number   = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr     = mpc_new("expr");
    mpc_parser_t* Typhon    = mpc_new("typhon");

    
    /* Define them with following lnaguage */
    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
      number   : /-?[0-9]+/ ;                             \
      operator : '+' | '-' | '*' | '/' ;                  \
      expr     : <number> | '(' <operator> <expr>+ ')' ;  \
      typhon    : /^/ <operator> <expr>+ /$/ ;             \
    ",
    Number, Operator, Expr, Typhon);
  
    
    /* Print Version and Exit Information */
    puts("Typhon Version 1.1.0");
    puts("Press ctrl+c to exit");

      /* In a never ending loop */
      while(1){
        
        /* Output our prompt and get input */
        char* input = readline("Typhon> ");

        /* Add input to history */
        add_history(input);

        /* Attempt to parse the user input */
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Typhon, &r)){
          /* On success print and delete AST */
          mpc_ast_print(r.output);
          mpc_ast_delete(r.output);
        }
        else{
          /* Otherwise print and delete the Error */
          mpc_err_print(r.error);
          mpc_err_delete(r.error);
        }
        /* Echo input back to user */
        printf("You just said %s\n", input);

        /* Free retrived input */
        free(input);
      }
      /* Undefined and delete our parsers */
      mpc_cleanup(4, Number, Operator, Expr, Typhon);
  return 0;
}
