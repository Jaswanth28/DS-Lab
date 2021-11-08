#include<stdio.h>
#include<stdlib.h>
struct polynode
{
    int coeff,expn;
    struct polynode *next;
}*poly1=NULL,*poly2=NULL,*poly3=NULL;
struct polynode* addterm(struct polynode *,int,int);
void polyaddition(struct polynode*,struct polynode*);
void displaypoly(struct polynode*);
int main()
{
    int ef,ex;
    printf("Enter polynomial 1 - coef and exp of each term,enter 0 0 to stop");
    while(1)
    {
        scanf("%d %d",&ef,&ex);
        if(ef==0 && ex==0)
           break;
        else
        {
            poly1=addterm(poly1,ef,ex);
        }
    }
    printf("Enter polynomial 2 - coef and exp of each term,enter 0 0 to stop");
    while(1)
    {
        scanf("%d %d",&ef,&ex);
        if(ef==0 && ex==0)
           break;
        else
        {
            poly2=addterm(poly2,ef,ex);
        }
    }
    displaypoly(poly1);
    printf("\n");
    displaypoly(poly2);
    printf("\nResult of addition of the given polynomials\n");
    polyaddition(poly1,poly2);
    displaypoly(poly3);
    return 0;
}
struct polynode* addterm(struct polynode *hptr,int f,int x)
{
    struct polynode *newnode,*temp,*prev;
    newnode=(struct polynode *) malloc(sizeof(struct polynode));
    newnode->coeff=f;
    newnode->expn=x;
    newnode->next=NULL;
    if(hptr==NULL)
        return newnode;
    temp=hptr;
    while(temp!=NULL && temp->expn>x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==hptr)
    {
        newnode->next=hptr;
        hptr=newnode;
    }
    else
    {
        prev->next=newnode;
        newnode->next=temp;
    }
    return hptr;
}
void displaypoly(struct polynode *hptr)
{
    struct polynode *temp;
    if(hptr==NULL)
    {
        printf("No polynomial at this address");
        return;
    }
    temp=hptr;
    while(temp!=NULL)
    {
        printf("%dx^%d ",temp->coeff,temp->expn);
        temp=temp->next;
    }
    
}
void polyaddition(struct polynode* hptr1,struct polynode* hptr2)
{
    struct polynode *temp1,*temp2;
    if(hptr1==NULL || hptr2==NULL)
    {
        printf("No addition to perform");
        return;
    }
    temp1=hptr1;
    temp2=hptr2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->expn==temp2->expn)
        {
           poly3=addterm(poly3,temp1->coeff+temp2->coeff,temp1->expn);
           temp1=temp1->next;
           temp2=temp2->next;
        }
        else if(temp1->expn>temp2->expn)
        {
           poly3=addterm(poly3,temp1->coeff,temp1->expn); 
           temp1=temp1->next;
        }
        else
        {
           poly3=addterm(poly3,temp2->coeff,temp2->expn); 
           temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
           poly3=addterm(poly3,temp1->coeff,temp1->expn); 
           temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
           poly3=addterm(poly3,temp2->coeff,temp2->expn); 
           temp2=temp2->next;
    }
}
