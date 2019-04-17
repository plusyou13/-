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
void swap(int &a, int &b) //引用类型方式
{
	int temp; //辅助变量
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

   clock_t start, finish;;//起始 结束时间 
	double duration;//总计时间 
    ListNode Head;
    ListNode List;
printf("\n\n\n");
  printf("-------------操作选项-----------\n");
  printf("1:返回菜单 \n");
  printf("2:退出程序 \n");
  printf("3:初试化，产生随机数 \n");
  printf("4:打印单链表 \n");
  printf("5:插入元素 \n");
  printf("6:删除j位置的元素 \n");
  printf("7:查找值为k的节点位置 \n");
  printf("8:对链表进行冒泡排序 \n");
  printf("9:对链表进行快速排序 \n");
  printf("10:对链表进行合并排序 \n");
  printf("--------------------------------\n");
 int x,n,i,e,k,j;
 while (1)
 {  
  printf("按数字键选择要执行的操作: ");
  scanf("%d",&x);
  printf("\n");
 
  //输入2跳出循环，退出程序
  if(x==2)
      break;
   
  switch(x)
  {
  case 1:  break;   //输入1，跳出switch语句，进入下一次循环
  case 3:  {
printf("请输入数字n（随机产生n个数）：");
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
   	printf("插入给i位置的元素为e \n");
   	printf("请输入i和e(中间用空格隔开)\n"); 
   	scanf("%d %d",&i,&e);
   	InsLinkList(List,i,e);
   	break;
   } 
      case 6:{
    printf("删除j位置的元素 \n");
    scanf("%d",&j);
   	DelLinkList(List,j);
	break;
   } 
     case 7:{
    printf("查找值为k的节点位置  \n");
    printf("请输入k\n"); 
    scanf("%d",&k);
   	//LocLinkList(List,k);
   	printf("%d",LocLinkList(List,k)) ;
	break;
   } 
   case 8:{
    printf("对链表进行冒泡排序  \n");
    
   start = clock();
   BubbleSort(List);
   finish = clock(); 
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "时间为 %f seconds\n", duration );
	break;
   } 
    case 9:{
    printf("对链表进行快速排序  \n");
    start = clock();
    quickSort(List);
    finish = clock(); 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "时间为 %f seconds\n", duration );
	break;
   }    
   case 10:{
    printf("对链表进行合并排序  \n");
   
       start = clock();
    Mergesort(&List);
    
   finish = clock(); 
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf("时间为 %f seconds\n", duration );

	break;
   } 
   
  default:  //数字输入错误，跳出siwtch语句，进入下一次循环
      printf("输入的数字不正确\n");
      break;
  }
 }
 return 0;}
