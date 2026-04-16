#include<stdio.h>
#include<stdlib.h>
struct node * getnode();
void display(struct node *);
struct node* createlist();
struct node * insertion(struct node *);
struct node * deletion(struct node *);
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
	int ch;
	struct node * head=NULL;
	//printf("enter your choice");
	//scanf("%d",&ch);
	while(1)
	{
		printf("\n1.create\n2.display\n3.insertion\n4.deletion\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					head=createlist();
					break;
			case 2:
					display(head);
					break;
			case 3:
					head=insertion(head);
					break;
			case 4:
					head=deletion(head);
					break;
			default:
					exit(0);
					
					break;
		}
	}
	
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
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
struct node * insertion(struct node * head)
{
	int ch,i,pos;
	struct node * newnode,* temp;
	if(head!=NULL)
	{	
		printf("\n1.beginning\n2.ending\n3.at the required position\n");
		scanf("%d",&ch);
		newnode=getnode();
		printf("enter the value to insert");
		scanf("%d",&newnode->data);
		switch(ch)
		{
			case 1:
					newnode->next=head;
					head=newnode;
					
					
					break;
			case 2:
					temp=head;
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=newnode;
					
					
					break;
			case 3: 
					temp=head;
					printf("enter the position");
					scanf("%d",&pos);
					for(i=1;i<pos-1;i++)
					{
						temp=temp->next;
					}
					newnode->next=temp->next;
					temp->next=newnode;
					
					
					
					break;
			default:
					printf("invalid list");
					
					
					break;
		}
	}
	
	return head;

}
struct node * deletion(struct node * head)
{
	int ch,i,pos;
	struct node * newnode,* temp;
	if(head!=NULL)
	{	
		printf("\n1.beginning\n2.ending\n3.at the required position\n");
		scanf("%d",&ch);
		temp=head;
		switch(ch)
		{
			case 1:
					head=head->next;
					temp->next=NULL;
					
					break;
			case 2:
					while(temp->next->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=NULL;
					
					
					break;
			case 3: 
					printf("enter position value");
					scanf("%d",&pos);
					if(pos==1)
					{
						head=head->next;
						temp->next=NULL;
					}
					else
					{
						for(i=1;i<pos-1;i++)
						{
							temp=temp->next;
						}
						temp->next=temp->next->next;
					}
					
					break;
			default:
					printf("invalid list");
		}
	}
	
	return head;
}
