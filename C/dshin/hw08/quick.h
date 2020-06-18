// ==============================================================

#define MAX_LIST_LENGTH     9
#define SWAP(x, y, t)       ( (t)=(x), (x)=(y), (y)=(t) )

// ==============================================================

void quick_sort_log(int list[], int left, int right);
void quick_sort(int list[], int left, int right);
int partition(int list[], int left, int right);

// ==============================================================