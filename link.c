#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;               
    struct LNode *next;      
} LNode; 
typedef LNode*List;//LNode*这个指针类型别名List
List newNode(int data)
{
    List node=(List)malloc(sizeof(LNode));
    node->data=data;
    node->next=NULL;
    return node;
}//新节点
List newList() 
{
    List head=newNode(0);//创建头结点
    return head;
}//新链表 
List insert_h(List head,int data)
{
    List node=newNode(data);
    node->next=head->next;
    head->next=node;
    return head;
}//头插
List insert_t(List head,int data)
{
    List node=newNode(data);
    List p=head;
    while(p->next!=NULL)
        {p=p->next;}
    p->next=node;
    return head;
}//尾插 
List FindKth(int i,List head)
{
    List p=head;
    int j=1;
    while(p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}//查找
List insert( List head, int i, int data)
{
    List p, s;
    if (i == 1)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = data;
        s->next = head;
        return s;
    }
    p = FindKth(i-1, head); //查找第i-1个结点是否存在
    if (p == NULL)
    {
        printf("没有哦搞错了吧\n");
        return NULL;
    }
    else
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = data;
        s->next = p->next;
        p->next = s;
    }
    return head;
}//随便插

// 4.删除
List Delete(int i,List head)
{
    List p, s;
    if (i == 1)//删除头结点
    {
        s = head;
        if (head != NULL)//如果链表不为空
            head = head->next; 
        else
            return NULL; 
        free(s); //释放!!!
        return head; //太好了是全新头指针！！
    }
    p = FindKth(i-1, head); //喂喂喂i-1在吗(不能找i,i-1才能定位删除)
    if (p == NULL)
    {
        printf("第%d个结点不存在\n", i-1);
        return NULL;
    }
    else if (p->next == NULL)
    {
        printf("第%d个结点不存在\n", i);
        return NULL;
    }
    else
    {
        s = p->next;
        p->next = s->next;
        free(s) ;
    }
    return head;
}