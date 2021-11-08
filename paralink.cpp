#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node*next;
}
*top=NULL;
int main()
{
	void push(char);
	void pop();
	char *s;
	int i;
	s=(char*)malloc(1000*sizeof(struct node));
	printf("enter a equation with paranthiss to check");
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='('|| s[i]=='{' || s[i]=='[')
		{
			push(s[i]);
		}
		if(s[i]==')'|| s[i]=='}' || s[i]==']')
		{
			pop();
		}
	}
	if(top==NULL)
	{
		printf("\n parathereisis is balanced");
	}
	else
	printf("\n parathereisis isnt balanced");
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
		top=top->next;
		free(temp);
	}
}
void push(char x)
{
	struct node*nnode;
	nnode=(struct node*)malloc(sizeof(struct node));
	if(nnode==NULL)
	{
		printf("\nstack is full");
	}
	else
	{
		nnode->next=top;
		nnode->data=x;
		top=nnode;
	}
}
