# include<stdio.h>
# define MAX 5

int cq[MAX];
int f = -1;
int r = -1;
void insert(int x)
{
	if((f == 0 && r == MAX-1) || (f == r+1))
	{
		printf("Queue Overflow \n");
		return;
	}
	if (f == -1)  /*If queue is empty */
	{
		f = 0;
		r = 0;
	}
	else
	{
		if(r == MAX-1)	/*r is at last position of queue */
			r = 0;
		else
			r = r+1;
	}
	cq[r] = x ;
}

void del()
{
	if (f == -1)
	{
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted from queue is : %d\n",cq[f]);
	if(f == r) /* queue has only one element */
	{
		f = -1;
		r=-1;
	}
	else
	{	
		if(f == MAX-1)
			f = 0;
		else
			f = f+1;
	}
}
/*End of del() */


void display()
{
	int fp = f,rp = r;
	if(f == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	if( fp <= rp )
		while(fp <= rp)
		{
			printf("%d ",cq[fp]);
			fp++;
		}
	else
	{
		while(fp <= MAX-1)
		{
			printf("%d ",cq[fp]);
			fp++;
		}
		fp = 0;
		while(fp <= rp)
		{
			printf("%d ",cq[fp]);
			fp++;
		}
	}
	printf("\n");
}



int main()
{
	int choice,x;
	while(choice!=4)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				printf("Input the element for insertion in queue : ");
				scanf("%d", &x);

				insert(x);
				break;
			case 2 :
				del();
				break;
			case 3:
				display();
				break;
			case 4:	break;
		}
	}
	
	return 0;
}
