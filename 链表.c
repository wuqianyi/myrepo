#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;

//建立单链表
void Creat(Linklist L)//头插法创建单链表La
{
    Linklist p;
    int X,i,N;
	printf("注意：采用尾插法数据读入顺序于逻辑顺序相反\n");
    printf("请输入链表结点个数N:");
    scanf("%d",&N);
	printf("请输入有序链表的数据：\n") ;
    for(i=1;i<=N;i++){
    	scanf("%d",&X);
    	p=(Linklist)malloc(sizeof(LNode));
        p->data=X; 
        p->next=L->next;
        L->next=p;
	}
}
void Print(Linklist L)
{

    Linklist p=L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void Common(Linklist A,Linklist B,Linklist C)//两个单链表合并排序 
{
    Linklist pa,pb,pc;
    pa=A->next;
    pb=B->next;
    C=pc=A;  //合并排序后结果至于A链表 
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;                       //类似尾插法创建链表
            pa=pa->next;
        }
        else 
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    while(pa!=NULL)
    {
        pc->next=pa;
        pc=pa;
        pa=pa->next;
    }
    while(pb!=NULL)
    {
        pc->next=pb;
        pc=pb;
        pb=pb->next;
    }
    pc->next=NULL;
    printf("两个有序链表合并后为：\n");
    Print(C);
}
int main(){

	Linklist A,B,C;
	Creat(A);
 	Creat(B);
 	printf("链表A的内容为：\n");
 	Print(A);
 	printf("链表B的内容为：\n");
 	Print(B);
 	Common(A,B,C);
 	return 0;
 }

