#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;

//����������
void Creat(Linklist L)//ͷ�巨����������La
{
    Linklist p;
    int X,i,N;
	printf("ע�⣺����β�巨���ݶ���˳�����߼�˳���෴\n");
    printf("���������������N:");
    scanf("%d",&N);
	printf("������������������ݣ�\n") ;
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
void Common(Linklist A,Linklist B,Linklist C)//����������ϲ����� 
{
    Linklist pa,pb,pc;
    pa=A->next;
    pb=B->next;
    C=pc=A;  //�ϲ������������A���� 
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;                       //����β�巨��������
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
    printf("������������ϲ���Ϊ��\n");
    Print(C);
}
int main(){

	Linklist A,B,C;
	Creat(A);
 	Creat(B);
 	printf("����A������Ϊ��\n");
 	Print(A);
 	printf("����B������Ϊ��\n");
 	Print(B);
 	Common(A,B,C);
 	return 0;
 }

