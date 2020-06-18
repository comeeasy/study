// ======================================================================

    #include <stdio.h>
    #include <stdlib.h>
    #include "merge.h"

// ====================================================================== 

// ====================================================================== 

int grade[MAX_LIST_LENGTH] = {  
    27, 10, 12, 20, 25, 13, 15, 22 
};                 

// ======================================================================

int main(void) {
    merge_sort_log(grade, 0, MAX_LIST_LENGTH - 1);
    return EXIT_SUCCESS;
    }

// ====================================================================== 

void merge_sort_log(int list[], int left, int right) {                                                                                                              
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
    merge_sort(list, left, right);     
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

void merge_sort(int list[], int left, int right) {                   
    int mid;                                                         
    if (left < right) {                                              
        mid = (left + right) / 2;                                    
        merge_sort_log(list, left, mid);                             
        merge_sort_log(list, mid + 1, right);                        
        merge(list, left, mid, right);                               
    }                                                                
}                                                                    
                                                                     
// ====================================================================== 