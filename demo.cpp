#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"init.h"
void Split_List(ListNode List, ListNode *List_A, ListNode *List_B)
{
    ListNode fast_list;
    ListNode low_list;

    if(List == NULL || List->next == NULL)
    {
        *List_A = List;
        *List_B = NULL;
    }

    else
    {
        low_list  = List;
        fast_list = List->next;

        while(fast_list != NULL)
        {
            fast_list = fast_list->next;
            if(fast_list != NULL)
            {
                low_list  = low_list->next;
                fast_list = fast_list->next;
            }
        }

        *List_A = List;
        *List_B = low_list->next;
        low_list->next = NULL;
    }
}

ListNode Merge_List(ListNode List_A, ListNode List_B)
{
    ListNode List_Result = NULL;
    if(List_A == NULL)
        return List_B;
    if(List_B == NULL)
        return List_A;

    if(List_A->data <= List_B->data)
    {
        List_Result = List_A;
        List_A = List_A->next;
    }

    else
    {
        List_Result = List_B;
        List_B = List_B->next;
    }

    List_Result->next = Merge_List(List_A,List_B);

    return List_Result;
}


void Mergesort(ListNode *List)
{
    ListNode Head = *List;
    ListNode List_A;
    ListNode List_B;

    if(Head == NULL || Head->next == NULL)
        return;

    Split_List(Head, &List_A, &List_B);

    Mergesort(&List_A);
    Mergesort(&List_B);

    *List = Merge_List(List_A,List_B);
}
void BubbleSort(ListNode List)
{
    Node * p, * q, * tail;
 
    tail = NULL;
 
    while((List->next->next) != tail)
    {
        p = List;
        q = List->next;
        while(q->next != tail)
        {
            if((q->data) > (q->next->data))
            {
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
                q = p->next;
            }
            q = q->next;
            p = p->next;
        }
        tail = q;
    }
}
void swap(int &a, int &b) //�������ͷ�ʽ
{
	int temp; //��������
	temp = a;
	a = b;
	b = temp;	
}
void quickSort(Node* start, Node* end=NULL)
{
    if (start == NULL || start == end) return;

    Node* p1 = start;
    Node* p2 = start->next; 

    while (p2 != end) {
        if (p2->data < start->data) {
            p1 = p1->next;
            swap(p1->data, p2->data);
        }
        p2 = p2->next;
    }
    swap(p1->data, start->data);

    quickSort(start, p1);
    quickSort(p1->next, end);
}



int main()
{

   clock_t start, finish;;//��ʼ ����ʱ�� 
	double duration;//�ܼ�ʱ�� 
    ListNode Head;
    ListNode List;
printf("\n\n\n");
  printf("-------------����ѡ��-----------\n");
  printf("1:���ز˵� \n");
  printf("2:�˳����� \n");
  printf("3:���Ի������������ \n");
  printf("4:��ӡ������ \n");
  printf("5:����Ԫ�� \n");
  printf("6:ɾ��jλ�õ�Ԫ�� \n");
  printf("7:����ֵΪk�Ľڵ�λ�� \n");
  printf("8:���������ð������ \n");
  printf("9:��������п������� \n");
  printf("10:��������кϲ����� \n");
  printf("--------------------------------\n");
 int x,n,i,e,k,j;
 while (1)
 {  
  printf("�����ּ�ѡ��Ҫִ�еĲ���: ");
  scanf("%d",&x);
  printf("\n");
 
  //����2����ѭ�����˳�����
  if(x==2)
      break;
   
  switch(x)
  {
  case 1:  break;   //����1������switch��䣬������һ��ѭ��
  case 3:  {
printf("����������n���������n��������");
scanf("%d",&n);
  Head=CreatListTail(n);
  List = Head -> next;
   break;   
   }
   case 4:{
   	dispLinkList(List);
	break;
   } 
    case 5:{
   	printf("�����iλ�õ�Ԫ��Ϊe \n");
   	printf("������i��e(�м��ÿո����)\n"); 
   	scanf("%d %d",&i,&e);
   	InsLinkList(List,i,e);
   	break;
   } 
      case 6:{
    printf("ɾ��jλ�õ�Ԫ�� \n");
    scanf("%d",&j);
   	DelLinkList(List,j);
	break;
   } 
     case 7:{
    printf("����ֵΪk�Ľڵ�λ��  \n");
    printf("������k\n"); 
    scanf("%d",&k);
   	//LocLinkList(List,k);
   	printf("%d",LocLinkList(List,k)) ;
	break;
   } 
   case 8:{
    printf("���������ð������  \n");
    
   start = clock();
   BubbleSort(List);
   finish = clock(); 
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "ʱ��Ϊ %f seconds\n", duration );
	break;
   } 
    case 9:{
    printf("��������п�������  \n");
    start = clock();
    quickSort(List);
    finish = clock(); 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "ʱ��Ϊ %f seconds\n", duration );
	break;
   }    
   case 10:{
    printf("��������кϲ�����  \n");
   
       start = clock();
    Mergesort(&List);
    
   finish = clock(); 
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf("ʱ��Ϊ %f seconds\n", duration );

	break;
   } 
   
  default:  //���������������siwtch��䣬������һ��ѭ��
      printf("��������ֲ���ȷ\n");
      break;
  }
 }
 return 0;}
