#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	struct node*p;
}*front=NULL,*rear=NULL,*temp;
void enq(int x)
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
void enqueue()
{
	int sno,c;
		printf("\n enter the sno. 0 to quit");
		scanf("%d",&sno);
		if(sno==0)
		{
			exit(1);
		}
	else
		printf("\n1-insert as first node");
		printf("\n2-insert as last  node");
		printf("\n3-return to main menu");
		printf("\n\n enter your choice");
		scanf("%d",&c);
		switch(c)
		{
			case 1: temp=(struct node*)malloc(sizeof(struct node));
					if(front->p==NULL)
					{
						temp->data=sno;
						temp->next=front;
						temp->p=NULL;
						front=temp;
					}
					break;
			case 2:	struct node*nnode;
					nnode=(struct node*)malloc(sizeof(struct node));
					if(nnode!=NULL)
					{
						nnode->data=sno;
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
					break;
			case 3: return;
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
	void enq(int);
	void enqueue();
	void display();
	void dqueue();
	int choice,sno;
	while(1)
	{
		printf("\n1.enqueue");
		printf("\n2.deenqueue");
		printf("\n3.dequeue");
		printf("\n4.display");
		printf("\n5.exit");
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
				    	enq(sno);
				    }
                    break;
            case 2: enqueue();
                	break;
			case 3: dqueue();
					break;
			case 4:	display();
			        break;
			case 5: exit(1);
			        break;
		}
	}
}
