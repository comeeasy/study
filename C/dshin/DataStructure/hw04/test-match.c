// =======================================================

#include <stdio.h>
#include <stdlib.h>
#include "match.h"

// =======================================================

char* expr1 = "[{()}]";
char* expr2 = "[{(]}]";
char* expr3 = "[({}()[])]{{([]{()}())}}";
char* expr4 = "[({}()[]}]";
char* expr5 = "[[({}()[])]";

// =======================================================

int main() {
    printf("expr1=%s\n", expr1);
    match(expr1);

    printf("expr1=%s\n", expr2);
    match(expr2);
    
    printf("expr1=%s\n", expr3);
    match(expr3);

    printf("expr1=%s\n", expr4);
    match(expr4);

    printf("expr1=%s\n", expr5);
    match(expr5);    

    return EXIT_SUCCESS;
}