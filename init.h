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
    srand(time(0));//启动随机种子数
    ListNode List = (ListNode)malloc(sizeof(struct Node));

    ListNode Tail = List;
    for(i = 0; i < len; i ++)
    {
        p = (ListNode)malloc(sizeof(struct Node));
        p->data = rand() % len + 1;//产生随机数 
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
    printf("总共%d个节点",i);
}


void InsLinkList(ListNode List,int i,int e) //插入给i位置的元素为e 
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
	printf("插入位置不合理");
	 
	}	
s=(ListNode)malloc(sizeof(struct Node));
s->data=e;
s->next=pre->next;
pre->next=s;
}

void DelLinkList(ListNode List,int i)//删除i位置元素，并将删除的元素保存到*e中  
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
	printf("删除节点不合理");
	 
	}	
r=pre->next;
pre->next=r->next;
//*e = r->data;//并将删除的元素保存到*e中   
free(r);
//return 1;
}

int LocLinkList(ListNode List,int e)//查找值为e的节点位置 
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

