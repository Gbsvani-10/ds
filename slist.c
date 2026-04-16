#include<stdio.h>
#include<stdlib.h>
struct node * getnode();
void display(struct node *);
struct node * createlist();
struct node
{
	int data;
	struct node * next;
};
struct node * getnode()
{
	struct node * newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=0;
	newnode->next=NULL;
	return newnode;
}
int main()
{
	/*struct node * newnode;
	printf("hallo");
	newnode=getnode();
	printf("\n%d",newnode->data);
	printf("\n%p",newnode->next);*/
	struct node * head;
	head=createlist();
	display(head);
	
	return 0;
}
struct node * createlist()
{
	struct node * head,* first,* newnode;
	first=getnode();
	head=first;
	newnode=getnode();
	printf("enter the value -1 to stop");
	scanf("%d",&newnode->data);
	while(newnode->data!=-1)
	{
		first->next=newnode;
		first=newnode;
		newnode=getnode();
		printf("enter value");
		scanf("%d",&newnode->data);
	}
	return head->next;
}
void display(struct node * head)
{
	struct node * temp;
	temp=head;
	while(temp->next!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
