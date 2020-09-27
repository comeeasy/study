//====================================================================== 

#define MAX_LIST_LENGTH         6 
#define SWAP(x, y, t)           ((t)=(x), (x)=(y), (y)=(t))

//======================================================================

void selection_sort(int list[], int n); 
void print_array(int list[], int n);
void selection_sort_recur(int list[], int start, int end);

//======================================================================