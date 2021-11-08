#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	struct node*p;
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
	struct node*nnode;
	nnode=(struct node*)malloc(sizeof(struct node));
	if(nnode!=NULL)
	{
		nnode->data=x;
		nnode->next=NULL;
		nnode->p=NULL;
	}
	if(front==NULL)
	{
		rear=front=nnode;
	}
	else
	{
		rear->next=nnode;
		rear->p=NULL;
		rear=nnode;
	}
}
void dqueue()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		printf("\n q is empty");
	}
	else
	{
		temp=front;
		printf("%d is dequeued",temp->data);
		front=front->next;
		free(temp);
	}
}
void display()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(front==NULL)
	{
		printf("\nq is  empty");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	void enqueue(int);
	void display();
	void dqueue();
	int choice,sno;
	while(1)
	{
		printf("\n1.enqueue");
		printf("\n2.dequeue");
		printf("\n3.display");
		printf("\n4.exit");
		printf("\nenter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				    while(1)
				    {
				    	printf("\n enter the sno. 0 to quit");
				    	scanf("%d",&sno);
				    	if(sno==0)
				    	{
				    	    break;
				    	}
				    	enqueue(sno);
				    }
                    break;
			case 2: dqueue();
					break;
			case 3:	display();
			        break;
			case 4: exit(1);
			        break;
		}
	}
}
