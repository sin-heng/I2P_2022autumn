/*#include <stdio.h>

void move_hanoi(int n, int from, int to, int temp);

int main(void) {
    move_hanoi(3, 1, 3, 2);
    return 0;
}
void move_hanoi(int n, int from, int to, int temp) {
    if (n == 1)
        // If there are only one disk to move,
        // Move the disk directly to the target rod.
        printf("Move disk %d from %d to %d\n", 1, from, to);
    else {
        // If there are multiple disks to move,
        // Keep the largest disk below and move the upper disks to the temporary rod.
        move_hanoi(n - 1, from, temp, to);
        // Move the largest disk to the target destination.
        printf("Move disk %d from %d to %d\n", n, from, to);
        // Stack the upper disks above the largest disk.
        move_hanoi(n - 1, temp, to, from);
    }
}*/
#include <stdio.h>
#define MAX 10000

typedef struct {
    int n, from, to, temp;
} Record;
Record stack[MAX];
int top = -1;

void move_hanoi(int n, int from, int to, int temp);

int main(void) {
    move_hanoi(3, 1, 3, 2);
    return 0;
}

void move_hanoi(int n, int from, int to, int temp) { 
    stack[++top] = (Record) {n, from, to, temp};
    while (top != -1) {
        Record record = stack[top--];
        if (record.n == 1 || record.temp == -1) {
            printf("Move disk %d from %d to %d\n", record.n, record.from, record.to);
            continue;
        }
        stack[++top] = (Record) {record.n - 1, record.temp, record.to, record.from};
        printf("stack[%d]:%d %d %d %d\n",top,record.n-1,record.temp,record.to,record.from);
        stack[++top] = (Record) {record.n, record.from, record.to, -1};
        printf("stack[%d]:%d %d %d %d\n",top,record.n,record.from,record.to,-1);
        stack[++top] = (Record) {record.n - 1, record.from, record.temp, record.to};
        printf("stack[%d]:%d %d %d %d\n",top,record.n-1,record.from,record.temp,record.to);
    }
}
