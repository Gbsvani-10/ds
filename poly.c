#include<stdio.h>
#include<stdlib.h>
struct node * getnode();
void display(struct node *);
struct node * createlist();
struct node * insertion(struct node *,int ,int);
struct node
{
	int cof,exp;
	struct node * next;
};
struct node * getnode()
{
	struct node * newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->cof=0;
	newnode->exp=0;
	newnode->next=NULL;
	return newnode;
}
int main()
{
	struct node * phead;
	phead=createlist();
	display(phead);
	
	return 0;
}
struct node * createlist()
{
	struct node * phead=NULL;
	int cof,exp,i,n;
	printf("\nenter number of terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter %d term coff and exp",i+1);
		scanf("%d%d",&cof,&exp);
		phead=insertion(phead,cof,exp);
	}
	
	return phead;
}
void display(struct node * phead)
{
	struct node * temp;
	temp=phead;
	while(temp!=NULL)
	{
		printf("%dx%d+",temp->cof,temp->exp);
		temp=temp->next;
	}
}
struct node * insertion(struct node * phead,int cof,int exp)
{
	struct node * newnode,* temp;
	newnode=getnode();
	newnode->exp=exp;
	newnode->cof=cof;
	if(phead==NULL||exp>phead->exp)
	{	
		newnode->next=phead;
		phead=newnode;
	}
	else
	{
		temp=phead;
		while(temp->next!=NULL&&temp->next->exp>exp)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	
	return phead;

}
