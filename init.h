#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;

typedef struct Node
{
    Item data;
    struct Node *next;
}Node,*ListNode;

ListNode InitLinkList(ListNode *List)
{
*List = (ListNode)malloc(sizeof(struct Node)); 
(*List)->next = NULL;
} 
 
ListNode CreatListTail(int len)
{
    int i;
    ListNode p;
    srand(time(0));//�������������
    ListNode List = (ListNode)malloc(sizeof(struct Node));

    ListNode Tail = List;
    for(i = 0; i < len; i ++)
    {
        p = (ListNode)malloc(sizeof(struct Node));
        p->data = rand() % len + 1;//��������� 
        Tail->next = p;
        Tail  = p;
    }
    Tail->next = NULL;
    return List;
}


void dispLinkList( ListNode List)
{
int i=0;
    while(List != NULL)
    {
        printf("%d ",List->data);
        List = List->next;
        i++;
    }
    printf("\n");
    printf("�ܹ�%d���ڵ�",i);
}


void InsLinkList(ListNode List,int i,int e) //�����iλ�õ�Ԫ��Ϊe 
{
Node *pre,*s;
int k;
pre = List;
k=0;
while(pre !=NULL && k < i-1)
{
pre = pre->next;
k=k+1;
}
if(pre == NULL)
{
	printf("����λ�ò�����");
	 
	}	
s=(ListNode)malloc(sizeof(struct Node));
s->data=e;
s->next=pre->next;
pre->next=s;
}

void DelLinkList(ListNode List,int i)//ɾ��iλ��Ԫ�أ�����ɾ����Ԫ�ر��浽*e��  
{
Node *pre,*r;
int k;
pre = List;
k=0;
while(pre !=NULL && k < i-1)
{
pre = pre->next;
k=k+1;
}
if(pre->next == NULL)
{
	printf("ɾ���ڵ㲻����");
	 
	}	
r=pre->next;
pre->next=r->next;
//*e = r->data;//����ɾ����Ԫ�ر��浽*e��   
free(r);
//return 1;
}

int LocLinkList(ListNode List,int e)//����ֵΪe�Ľڵ�λ�� 
{
Node *p ;
int i=1;
p = List->next;
while(p != NULL)
{
	if(p->data != e)
	{
p = p->next;
	i++;}
	else break;
}
 return i;
} 

