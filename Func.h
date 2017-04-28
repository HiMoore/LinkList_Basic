#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED


#define true 1
#define ok 1
#define false 0
#define error -1
#define underflow -1
#define overflow -1
typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
}LNode, *LinkList;


void Init_NoHead(LinkList *L); //OK
void Init_Head(LinkList *L);
void Insert_Head_NoHead(LinkList *L, Elemtype *A, int n); //OK
void Insert_Head_Head(LinkList L, Elemtype *A, int n);
void Insert_Tail_NoHead(LinkList *L, Elemtype *A, int n); //OK
void Insert_Tail_Head(LinkList L, Elemtype *A, int n);
void Insert_iX_NoHead(LinkList L, int i, Elemtype X);  //OK
void Insert_iX_Head(LinkList L, int i, Elemtype X);
LNode* Find_NoHead(LinkList L, Elemtype X);  //OK
LNode* Find_Head(LinkList L, Elemtype X);
void Delete_X_NoHead(LinkList *L, Elemtype X);  //OK
void Delete_X_Head(LinkList L, Elemtype X);
void Length_NoHead(LinkList L);  //OK
void Length_Head(LinkList L);
void Traver_NoHead(LinkList L);  //OK
void Traver_Head(LinkList L);
void Destroy_NoHead(LinkList *L);  //OK
void Destroy_Head(LinkList *L);

#endif // FUNC_H_INCLUDED
