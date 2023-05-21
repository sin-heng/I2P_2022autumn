#include <stdio.h>
#define MAX 10
#define swap(a, b) if (a != b) {(*a)^=(*b); (*b)^=(*a); (*a)^=(*b);}

void selection_sort(int start, int end);
int a[MAX] = {3, 7, 9, 1, 4, 0, 8, 6, 2, 5};

int main(void) {
    selection_sort(0, MAX-1);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void selection_sort(int start, int end) {
    
    if(start==end-1)
        return;
    selection_sort(start+1,end);
    if(a[start]>a[start+1])
        swap(&a[start],&a[start+1]);
}