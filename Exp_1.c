#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
void create();
void search();
void display();
struct node
{
	char data[500];
	struct node *nxt;
}*start,q;
void main()
{
	int ch;
	while(1)
	{
		printf("Enter the Operation\n1.create\n2.display\n3.search\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
			    goto halt;
			default:
			    printf("Enter the valid choice");
				break;	
		}
	}halt:printf("Terminated");
}
void create()
{
	struct node *temp,*q;
	temp=malloc(sizeof(struct node) );
	printf("Enter the data");
	scanf("%s",temp->data);
	temp->nxt=NULL;
	if(start==NULL)
	         start=temp;
    else
    {
    	q=start;
    	while(q->nxt!=NULL)
    	        q=q->nxt;
    	        q->nxt=temp;
	}
}
void display()
{
	struct node *q;
	q=start;
	if(start==NULL)
	{
		printf("\nSymbol tabl is empty\n");
	}
	else
	{
		printf("\ndata\taddress\n");
		while(q!=NULL){
			printf("%s\t%p\n",q->data,q);
			q=q->nxt;
		}
	}
}
void search()
{
	struct node *q;
	char x[50];
	int count=1,flag=0;
	printf("Enter the data to be searched");
	scanf("%s",x);
	q=start;
	while(q!=NULL)
	{
		if(strcmp(q->data,x)==0)
		{
			printf("Element fount in %p address\n",q);
			flag=1;
			break;
		}
		q=q->nxt;
		count =count+1;
	}
	if(flag==0)
	      printf("The element is not fount in the list\n");
	
}
