// ======================================================================

#include <stdio.h> 
#include <stdlib.h> 
#include "quick.h"

// ======================================================================

int grade[MAX_LIST_LENGTH] = { 
    5, 3, 8, 4, 9, 1, 6, 2, 7
};

int main() {
    quick_sort_log(grade, 0, MAX_LIST_LENGTH-1);

    return EXIT_SUCCESS;
}

void quick_sort_log(int list[], int left, int right) {
    static int recursion = 0;
    int i;

    recursion = recursion + 1; 
    for (i = 0; i < recursion; i++) 
        printf("|");
    printf("+ ");   
    for (i = left; i <= right; i++) {
        printf("[%d:%d]", i, list[i]);                
    }  
    printf("\n");   


    quick_sort(list, left, right); 

    for (i = 0; i < recursion; i++) 
        printf("|");      
    printf("- "); 
    for (i = left; i <= right; i++) { 
        printf("[%d:%d]", i, list[i]);
    } 
    printf("\n");   
      
    recursion = recursion - 1;        
}

// ======================================================================

void quick_sort(int list[], int left, int right) {
    if (left < right) { 
        int q = partition(list, left, right);
        printf("pivot [%d:%d]->[%d:%d]\n", left, list[q], q, list[q]); 
        quick_sort_log(list, left, q - 1); 
        quick_sort_log(list, q + 1, right); 
    }  
}    

// ======================================================================
                                                                                                                                                                                 // ======================================================================   