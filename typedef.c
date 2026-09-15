#include <stdio.h>
typedef struct Person{
    char name[20];
    int age;
    char sex;
    double height;
} Person;
int main()
{
    printf("结构体大小：%zu\n", sizeof(Person));
    return 0;
}