#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
}
*top=NULL;
void push(int x)
{
	struct node*nnode;
	nnode=(struct node*)malloc(sizeof(struct node));
	if(nnode==NULL)
	{
		printf("\nstack is full");
		top=(struct node*)malloc(sizeof(struct node));
		top->next=NULL;
		top->data=x;
	}
	else
	{
		nnode->next=top;
		nnode->data=x;
		top=nnode;
	}
}
void display()
{
	struct node*temp;
	temp=top;
	if(temp==NULL)
	{
		printf("\nstack is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void pop()
{
	struct node*temp;
	if(top==NULL)
	{
		printf("\nstack is empty");
	}
	else
	{
		temp=top;
		printf("%d is popped",temp->data);
		top=top->next;
		free(temp);
	}
}
int main()
{
	void push(int);
	void display();
	void pop();
	int choice,sno;
	while(1)
	{
		printf("\n1.push");
		printf("\n2.pop");
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
				    	push(sno);
				    }
                    break;
			case 2: pop();
					break;
			case 3:	display();
			        break;
			case 4: exit(1);
			        break;
		}
	}
}
