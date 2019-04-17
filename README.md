① 输入的形式和输入值的范围：插入元素时需要输入插入的位置和元素的值；删除元素时输入删除元素的位置；查找操作时需要输入元素的值。在所有输入中，元素的值都是整数。
② 输出的形式：在所有三种操作中都显示操作是否正确以及操作后单链表的内容。其中删除操作后显示删除的元素的值，查找操作后显示要查找元素的位置。
③ 程序所能达到的功能：完成单链表的生成（通过插入操作）、插入、删除、查找操作。


###1.定义单链表结构
```c
typedef struct Node
{
    Item data;
    struct Node *next;
}Node,*ListNode;
```
###2.初始化单链表
```c
ListNode InitLinkList(ListNode *List)
{
*List = (ListNode)malloc(sizeof(struct Node)); 
(*List)->next = NULL;
} 
```
###3.创建随机数的单链表 
```c
ListNode CreatListTail(int len)//len为单链表长度
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
```
###4.打印单链表
```c
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
```
###5.单链表的插入操作
```c
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
```
###6.删除单链表的节点i
```c
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
}
```
###7.查找元素的位置
```c
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
```
###8.对单链表进行归并排序
```c
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
```
###9.对单链表进行冒泡排序
```c
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
```
###10.对单链表进行快速排序
```c
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
```
###主函数
```c

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
```
