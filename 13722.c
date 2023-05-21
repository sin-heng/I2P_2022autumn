#include<stdio.h>
void recur(int ti,int a,int b,int c,int d,int e);
int max_1(int i,int j);
int max_2(int i,int j,int k,int m);
int L,H,max;
int brick[20];
int main(void){

    int T;
    int a=0,b=0,c=0,d=0,e=0;

    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&L,&H);
        for(int j=0;j<L;j++)
            scanf("%d",&brick[j]);
        recur(0,0,0,0,0,0);
        if(max == L)
            printf("Win\n");
        else
            printf("Lose at %d\n",max);
        max=0;
    }
}
void recur(int ti,int a,int b,int c,int d,int e){

    int val;
    if(ti==L){
        printf("return first\n");
        max = ti;
        return;
    }
    if( a>H || b>H || c>H || d>H || e>H ){
        printf("return second\n");
        if(ti>max){
            max=ti;
        }
        return;
    }
    else if(brick[ti]==1){
        printf("recur 1\n");
        //[]
        //[]
        //[]
        //[]
        recur(ti+1,a+4,b,c,d,e);
        recur(ti+1,a,b+4,c,d,e);
        recur(ti+1,a,b,c+4,d,e);
        recur(ti+1,a,b,c,d+4,e);
        recur(ti+1,a,b,c,d,e+4);
        // [][][][]
        val = max_2(a,b,c,d);
        recur(ti+1,val+1,val+1,val+1,val+1,e);
        val = max_2(b,c,d,e);
        recur(ti+1,a,val+1,val+1,val+1,val+1);
    }
    else if(brick[ti]==2){
        printf("recur 2\n");
        val = max_1(a,b);
        recur(ti+1,val,val,c,d,e);
        val = max_1(b,c);
        recur(ti+1,a,val,val,d,e);
        val = max_1(c,d);
        recur(ti+1,a,b,val,val,e);
        val = max_1(d,e);
        recur(ti+1,a,b,c,val,val);
    }
    else if(brick[ti]==3){
        printf("recur 3\n");
        val = max_1(a,c);
        if(b<a || b<c)
            recur(ti+1,val+1,val+2,val+1,d,e);
        val = max_1(b,d);
        if(c<b || c<d)
            recur(ti+1,a,val+1,val+2,val+1,e);
        val = max_1(c,e);
        if(d<c || d<e)
            recur(ti+1,a,b,val+1,val+2,val+1);
    }
    else if(brick[ti]==4){
        printf("recur 4\n");
        val = max_1(a,b);
        if(c>val)
            recur(ti+1,c,c+1,c+1,d,e);
        else    
            recur(ti+1,val+1,val+2,val+2,d,e);
        //a,b
        if(a>b)
            recur(ti+1,a+2,a+1,c,d,e);
        else
            recur(ti+1,a+3,b+2,c,d,e);
        //b,c
        if(b>c)
            recur(ti+1,a,b+2,b+1,d,e);
        else
            recur(ti+1,a,b+3,c+2,d,e);
        //c,d
        if(c>d)
            recur(ti+1,a,b,c+2,c+1,e);
        else
            recur(ti+1,a,b,c+2,d+2,e);
        //d,e
        if(d>e)
            recur(ti+1,a,b,c,d+2,d+1);
        else
            recur(ti+1,a,b,c,d+3,e+2);
    }
}
int max_1(int i,int j){
    return i>j?i:j;
}
int max_2(int i,int j,int k,int m){
    int max=i;
    if(j>max)
        max=j;
    if(k>max)
        max=k;
    if(m>max)
        max=m;
    return max;
}