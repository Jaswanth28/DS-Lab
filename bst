#include<stdlib.h>
#include<stdio.h>
struct node
{
	int d;
	struct node*l,*r;
};
struct node*create(int x)
{
	struct node*j=(struct node*)malloc(sizeof(struct node));
	j->d=x;
	j->r=NULL;
	j->l=NULL;
}
struct node*insert(struct node*p,int w)
{
	if(p==NULL)
	{
		return create(w);
	}
	if(w>p->d)
	{
		p->r=insert(p->r,w);
	}
	else
	{
		p->l=insert(p->l,w);;
	}
	return p;
}
struct node *del(struct node *p,int b)
{
	if(p==NULL)
	{
		return NULL;
	}
	else if(b>p->d)
	{
		p->r=del(p->r,b);
	}
	else if(b<p->d)
	{
		p->l=del(p->l,b);
	}
	else
	{
		if(p->l==NULL && p->r==NULL)
		{
			free(p);
			return NULL;
		}
		else if(p->l==NULL || p->r==NULL)
		{
			struct node*temp;
			if(p->l==NULL)
			{
				temp=p->r;
			}
			else
			{
				temp=p->l;
			}
			free(p);
			return temp;
		}
	}
}
struct node *fmin(struct node *p)
{
	if(p==NULL)
	    return NULL;
	else if(p->l!=NULL)
	    return fmin(p->l);
	return p;	    
}
int preorder(struct node*p)
{
	if(p!=NULL){
	printf("%d->",p->d);
	preorder(p->l);
	preorder(p->r);
}
else
{
	return NULL;
}
}
int inorder(struct node*p)
{
	if(p!=NULL){
	preorder(p->l);
	printf("%d->",p->d);
	preorder(p->r);
}
else
{
	return NULL;
}
}
int postorder(struct node*p)
{
	if(p!=NULL){
	preorder(p->l);
	preorder(p->r);
	printf("%d->",p->d);
}
else
{
	return NULL;
}
}
int menu()
{
	return 0;
}
int main()
{
	struct node * p;
	struct node*create(int);
	struct node*insert(struct node*,int);
	struct node * del(struct node*,int);	
		while(1)
		{
			s:printf("1.create\n");
			printf("2.insert\n");
			printf("3.delete\n");
			printf("4.display\n");
			printf("5.exit\n");
			printf("enter your choice\t");
			int q;
			scanf("%d",&q);
			switch(q)
			{
				case 1: printf("enter the root node of the tree or -1 to exit");
						static int x;
						scanf("%d",&x);
						if(x==-1)
						{
							break;
						}
						else
						{
							p=create(x);
						}
						break;
				case 2: printf("enter the value of node or -1 to exit");
						static int a;
						scanf("%d",&a);
						if(a==-1)
						{
							break;
						}	
						else
						{
							insert(p,a);
						}
						break;
				case 3: printf("enter the value to be deleted or -1 to exit");
						static int b;
						struct node * u;
						scanf("%d",&b);
						if(b==-1)
						{
							break;
						}
						else
						{
							u=del(p,b);
						}
						break;
				case 4: while(1)
						{
							printf("1.preorder\n");
							printf("2.inorder\n");
							printf("3.postorder\n");
							printf("4.exit\n");
							printf("enter your choice \t");
							int l;
							scanf("%d",&l);
							switch(l)
							{
								case 1: int preorder(struct node*);
										preorder(p);
										printf("\n");
										break;
								case 2: int inorder(struct node*);
										inorder(p);
										printf("\n");
										break;
								case 3: int postorder(struct node*);
										postorder(p);
										printf("\n");
										break;
								case 4: goto s;
							}
						}
						break;
						
				case 5: exit(1);
					
			}
		}

}
