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
void print_list(List head)
{
     List p=head;
     while(p->next!=NULL)
     {
        p=p->next;
        printf("%d\n",p->data);
     }
}//遍历打印
bool findit(List head, int n)
{
    List p = head->next;
    int count = 1;
    while(p != NULL)
    {
        if(p->data == n)
        {
            printf("we find it bro，是第%d个节点\n", count);
            return true;
        }
        p = p->next;
        count++;
    }
    printf("找不到，你搞错了吧，false\n");
    return false;
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

List change(int i,int data,List head)//写到这搞忘有的要求返回false和true了....
{
    List p=FindKth(i,head);
    if(p==NULL)
    {
        printf("第%d个结点不存在\n",i);
        return NULL;
    }
    else
    {
        p->data=data;
    }
    return head;
}//随便改

List delete(int i,List head)
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
        return head; //太好了是全新头指针！！我们有救了
    }
    p = FindKth(i-1, head); //喂喂喂i-1在吗(不能找i,要找i-1才能定位删除)
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
}//随便删

List reverse(List head)//反转的英文reverse吗
{   if(head == NULL || head->next == NULL)
    {
        printf("你刚刚干了一件浪费时间的事");
        return head;
    }
    List before = NULL;
    List now = head;
    List after;
    while(now != NULL)
    {
        after = now->next; 
        now->next = before;      // 反向
        before = now;
        now = after;
    }
    return before; // before成为老大
}//反转链表，when无头节点
List reverse(List head)//反转的英文reverse!
{
    List before = NULL;
    List now = head->next;  // now从第一个有效节点开始，跳过头结点
    List after;
    while(now != NULL)
    {
        after = now->next; 
        now->next = before;      // 反向
        before = now;
        now = after;
    }
    head->next = before;     // 头结点接上反转后的链表
    return head; // 头结点不变，返回原head
}//反转链表，when有头节点(好像确实要方便一点)
