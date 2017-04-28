#include <stdio.h>
#include <stdlib.h>
#include "Func.h"


//不带头结点的单链表初始化
void Init_NoHead(LinkList *L)
{
    *L = NULL;
}
//带头结点的单链表初始化
void Init_Head(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        printf("%s内存分配失败！\n", __FUNCTION__);
    (*L) -> next = NULL;
}

//头插建立单链表(不带头结点）
void Insert_Head_NoHead(LinkList *L, Elemtype *A, int n)
{
    int i;
    LNode *p;
    for(i=0; i<n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        if(!p)
            printf("%s内存分配失败！\n", __FUNCTION__);
        p->data = A[i];
        p->next = *L;
        *L = p;
    }
}
//头插建立单链表（带头结点）
void Insert_Head_Head(LinkList L, Elemtype *A, int n)
{
    int i;
    LNode *p;
    for(i=0; i<n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        if(!p)
            printf("%s内存分配失败！\n", __FUNCTION__);
        p->data = A[i];
        p->next = L->next;
        L->next = p;
    }
}

//尾插建立单链表（不带头结点）
void Insert_Tail_NoHead(LinkList *L, Elemtype *A, int n)
{
    int i;
    LNode *tail, *p;
    tail = *L;
    p = (LNode*)malloc(sizeof(LNode));
    p->data = A[0];
    *L = p;
    tail = *L;
    for(i=1; i<n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        if(!p)
            printf("%s内存分配失败!\n", __FUNCTION__);
        p->data = A[i];
        tail->next = p;
        tail = p;
    }
    tail -> next = NULL;
}
//尾插建立单链表（带头结点）
void Insert_Tail_Head(LinkList L, Elemtype *A, int n)
{
    int i;
    LNode *p, *tail;
    tail = L->next;
    for(i=0; i<n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        if(!p)
            printf("%s内存分配失败!\n", __FUNCTION__);
        p->data = A[i];
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;
}

//在第i个位置插入X(不带头结点)
void Insert_iX_NoHead(LinkList L, int i, Elemtype X)
{
    int j;
    LNode *p, *pre;
    pre = L;
    p = (LNode *)malloc(sizeof(LNode));
    if(!p)
        printf("%s内存分配失败\n", __FUNCTION__);
    for(j=1; j<i-1; j++)
        pre = pre -> next;
    p->data = X;
    p->next = pre->next;
    pre->next = p;
}
//在第i个位置插入X(带头结点)
void Insert_iX_Head(LinkList L, int i, Elemtype X)
{
    int j;
    LNode *p, *pre;
    pre = L->next;
    p = (LNode*)malloc(sizeof(LNode));
    if(!p)
        printf("%s内存分配失败！\n", __FUNCTION__);
    for(j=0; j<i-1; j++)
        pre = pre->next;
    p->data = X;
    p->next = pre->next;
    pre->next = p;
}

//查找目标元素X(不带头结点)
LNode* Find_NoHead(LinkList L, Elemtype X)
{
    LNode *p = L;
    int location = 1;
    while(p != NULL)
    {
        if(p->data == X)
        {
            printf("Find %d in location %d\n", p->data, location);
            return p;
        }
        p = p->next;
        location++;
    }
    printf("Can't find this Element!\n");
    return NULL;

}
//查找目标元素X(带头结点)
LNode* Find_Head(LinkList L, Elemtype X)
{
    LNode *p = L->next;
    int location=1;
    while(p != NULL)
    {
        if(p->data == X)
        {
            printf("Find %d in location %d\n", p->data, location);
            return p;
        }
        p = p->next;
        location++;
    }
    return NULL;
}

//删除值为X的元素(不带头结点)
void Delete_X_NoHead(LinkList *L, Elemtype X)
{
    LNode *p, *pre;
    p = *L, pre = *L;
    if(p->data == X)
    {
        *L = p->next;
        free(p);
    }
    else
    {   pre = p;
        p = p -> next;
        while(p != NULL)
            if(p->data == X)
            {
                pre->next = p->next;
                free(p);
                break;
            }
            else
            {
                pre = p;
                p = p->next;
            }
    }
}
//删除值为X的元素(带头结点)
void Delete_X_Head(LinkList L, Elemtype X)
{
    LNode *p, *pre;
    pre = L, p = pre->next;
    while(p != NULL)
    {
        if(p->data == X)
        {
            pre->next = p->next;
            free(p);
            break;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

//求单链表的长度(不带头结点)
void Length_NoHead(LinkList L)
{
    LNode *p = L;
    int length = 0;
    while(p != NULL)
    {
        length++;
        p = p->next;
    }
    printf("The length of Linklist is %d\n", length);
}
//求单链表的长度(带头结点)
void Length_Head(LinkList L)
{
    LNode *p = L;
    int length = 0;
    while(p->next != NULL)
    {
        p = p->next;
        length++;
    }
    printf("The length of Linklist is %d\n", length);
}

//遍历打印单链表(不带头结点)
void Traver_NoHead(LinkList L)
{
    LNode *p;
    p = L;
    while(p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}
//遍历打印单链表(带头结点)
void Traver_Head(LinkList L)
{
    LNode *p;
    p = L->next;
    while(p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");printf("\n");
}

//销毁单链表(不带头结点)
void Destroy_NoHead(LinkList *L)
{
    LNode *p, *q;
    p = *L;
    while(p != NULL)
    {
        q = p;
        p =p->next;
        free(q);
    }
    *L = NULL;
}
//销毁单链表(带头结点)
void Destroy_Head(LinkList *L)
{
    LNode *p, *q;
    p = *L;
    while(p->next != NULL)
    {
        q = p;
        p =p->next;
        free(q);
    }
}
