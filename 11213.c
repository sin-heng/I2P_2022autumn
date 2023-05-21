//NTHU Online Judge
//Yang HW8 11213 permutations
#include <stdio.h>
char list[10];
int num;
void show(int n)
{
    int i;
    printf("(%c", list[0]);
    for (i=1; i<n; i++) {
        printf(",%c", list[i]);
    }
    printf(")\n");
}
void Swap(int k, int i)
{
    int temp=list[k];
    list[k]=list[i];
    list[i]=temp;
}
void Perm(int k, int n)
{
    if(k==(n-1)){
        show(n);
    }
    else
    {
        for(int i=k;i<n;i++){
            Swap(k,i);
            Perm(k+1,n); // 1,4 2,4 3,4
            Swap(k,i);
        }
    }
}
int main(void)
{
    int i;
    scanf("%d", &num);
    for(i=0; i<num; i++)
        list[i] = '1'+i;
    Perm(0, num);
    return 0;
}