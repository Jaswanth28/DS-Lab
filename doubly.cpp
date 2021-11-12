#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
	struct node*p;
};
struct node*top=NULL;
void create(int x)
{
	struct node*nnode;
	nnode=(struct node*)malloc(sizeof(struct node));
	if(nnode==NULL)
	{
		printf("\nstack is full");
		top=(struct node*)malloc(sizeof(struct node));
		top->p=NULL;
		top->next=NULL;
		top->data=x;
	}
	else
	{
		nnode->next=top;
		nnode->data=x;
		nnode->p=NULL;
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
void del()
{
	int sno,choice;
	struct node*lptr,*rptr,*temp;
	while(1)
	{
		printf("\n 1-delete first node");
		printf("\n 2-delete last  node");
		printf("\n 3-delete any node except 1st and last node");
		printf("\n 4-back to  main menu");
		printf("\n\n enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: temp=top;
					top=top->next;
					top->p=NULL;
					printf("\n%d is deleted",temp->data);
					free(temp);
					break;
			case 2:	rptr=top;
					while(rptr->next!=NULL)
					{
						lptr=rptr;
						rptr=rptr->next;
					}
					free(rptr);
					lptr->next=NULL;
					lptr->p=rptr;
				
			case 3: printf("\n enter the sno need to be deleted");
					scanf("%d",&sno);
					// bring rptr to first node
					rptr=top;
					while(rptr->data!=sno && rptr->next!=NULL)
					{
						lptr=rptr;
						rptr=rptr->next;
					}
					if(rptr->data==sno)
					{
						lptr->next=rptr->next;
                                                rptr->p=lptr;
						printf("%d is deleted",sno);
						free(rptr);
					}
					else
					{
						printf("%d isnt found",sno);
					}
			case 4: return;
			
			
		}
	}
}
void insert()
{
	struct node*f,*l,*temp,*lptr,*rptr;
	int sno,c;
	while(1)
	{
		printf("\n1-insert as first node");
		printf("\n2-insert as last  node");
		printf("\n3-insert anywhere in node");
		printf("\n4-return to main menu");
		printf("\n\n enter your choice");
		scanf("%d",&c);
		switch(c)
		{
			case 1:temp=(struct node*)malloc(sizeof(struct node*));
					printf("\n enter your sno");
					scanf("%d",&temp->data);
					//establish link b/w hptr and link
					temp->next=top;
					temp->p=NULL;
					top=temp;
					break;
			
			case 2:lptr=top;
					while(lptr->next!=NULL)
					{
						lptr=lptr->next;
					}
					temp=(struct node*)malloc(sizeof(struct node));
					printf("\n enter your sno");
					scanf("\n%d",&temp->data);
					temp->next=NULL;
					//establish a link b/w lptr and temp
					lptr->next=temp;
					temp->p=lptr;
					printf("\n node inserted is %d",temp->data);
					break;
			
			case 3:printf("enter the data wher the node must be inserted");
					scanf("%d",&sno);
					//bring lptr to the first node
					lptr=top;
					while(lptr->data!=sno && lptr->next!=NULL)
					{
						lptr=lptr->next;
					}
					if(lptr->data==sno)
					{
						rptr=lptr->next;
						//allocation of memory for temp
						temp=(struct node*)malloc(sizeof(struct node));
						printf("enter the node to insert");
						scanf("%d",&temp->data);
						//establish link b/w lptr and temp
						lptr->next=temp;
						//establish link b/w rptr and temp
						temp->next=rptr;
						printf("\n %d is inserted",sno);
					}
					else
					{
						printf("\n\n %d is not found ",temp->data);
					}
			case 4: return;
		}
		
	}
}
int main()
{
	void create(int);
	void insert();
	void display();
	void del();
	int choice,sno;
	while(1)
	{
		printf("\n1.create");
		printf("\n2.insert");
		printf("\n3.del");
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
				    	create(sno);
				    }
                    break;
            case 2: insert();
                    break;
			case 3: del();
					break;
			case 4:	display();
			        break;
			case 5: exit(1);
			        break;
		}
	}
}
