#include <stdio.h>
#define MAX 10
#define swap(a, b) if (a != b) {(*a)^=(*b); (*b)^=(*a); (*a)^=(*b);}

//void selection_sort(int start, int end);
void selection_sort(int*a ,int size);
int Min_index(int*a ,int size);
int a[MAX] = {3, 7, 9, 1, 4, 0, 8, 6, 2, 5};

int main(void) {
    //selection_sort(0, MAX);
    selection_sort(a,MAX);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
/*
void selection_sort(int* a, int size) {
    int i, j, min_idx;
    // Put the i-th smallest number in a[i].
    for (i = 0; i < size - 1; i++) {
        // Scan through the remaining array and pick the smallest element.
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (a[min_idx] > a[j])
                min_idx = j;
        }
        // Swap the smallest number to the left.
        swap(&a[i], &a[min_idx]);
    }
}
*/
int Min_index(int*a ,int size){
    if(size==1)
        return 0;
    int min_index=0;
    for(int j=1;j<size;j++)
        if(a[min_index]>a[j])
            min_index=j;
    return min_index;
}
void selection_sort(int*a ,int size){
    if(size==1)
        return;
    int min_index = Min_index(a,size);
    swap(&a[0],&a[min_index]);
    selection_sort(a+1,size-1);
}