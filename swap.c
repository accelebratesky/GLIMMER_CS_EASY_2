#include <stdio.h>

//这里我前几次试着运行每回都报错winmain有问题，研究半天没搞懂是哪里出问题，后来随便点点突然又可以了，好奇怪
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    int a=3;
    int b=5;
    swap(&a,&b);//C语言中&是取地址符号，表示取变量的地址；C++中&是引用符号，表示引用变量
    printf("a=%d,b=%d",a,b);
    return 0;
}