#include <stdio.h>


void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    int a=3;
    int b=5;
    swap(&a,&b);
    printf("a=%d,b=%d",a,b);
    return 0;
}