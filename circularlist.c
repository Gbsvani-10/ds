#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* getnode();
struct node* createlist();
void display(struct node *);
struct node *insertion(struct node *);
struct node *deletion(struct node *);
struct node * getnode()
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    np->data=0;
    np->next =NULL;
    return np;
}
struct node * createlist()
{
    struct node *head,*first,*newnode;
    first=getnode();
    head=first;
    newnode = getnode();
    printf("Enter the -1 to stop list");
    printf("Enter value");
    scanf("%d",&newnode->data);
    while (newnode->data!=-1)
    {
        first->next = newnode;
        first=newnode;
        newnode=getnode();
        printf("Enter value");
        scanf("%d",&newnode->data);
        newnode->next = head->next;

    }
    
    return head->next;
}
int main()
{
    int ch;
    struct node *head;
    while (1)
    {
        printf("\n1.create\n2.display\n3.insert\n4.Delete\n5.Exit\n");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
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
}
struct node * insertion(struct node *head)
{
    struct node * temp, * newnode;
    int ch,pos,i;
    temp = head;
    newnode = getnode();
    printf("enter value:");
    scanf("%d",&newnode->data);
    while(1)
    {
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
		{
            case 1:
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    newnode->next=head;
                    temp->next = newnode;
                    head=newnode;
                    return head;
                    break;
            case 2:
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    newnode->next=head;
                    temp->next = newnode;
                    return head;
                    break;
            case 3: 
                    printf("enter which position");
                    scanf("%d",&pos);
                    if(pos==1){
                        while(temp->next!=head)
                        {
                            temp=temp->next;
                        }
                        newnode->next=head;
                        temp->next = newnode;
                        head=newnode;
                        return head;
                    }
                    else {
                        for(i=1;i<pos-1;i++)
                        {
                            temp=temp->next;
                        }
                        newnode->next=temp->next;
                        temp->next=newnode;
                        return head;
                    }
            default:printf("Invalid Choice");
     }

    }
}
void display(struct node *head)
{
    struct node *temp;
    temp=head;   
    while (temp!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }    
     printf("%d->",temp->data);
}
struct node *deletion(struct node *head)
{
    int ch,pos,i;
    struct node *temp,*secondtemp;
    temp = head;

    if (temp==NULL)
	{
        printf("list is empty");
    }
    else
	{
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            /*case 1:
                if(temp->next==head)
                {
                    head=NULL;
                    return head;
                }
                else
                {
                   //secondtemp=head->next;
                   while(temp->next->next!=head)
                   {
                       temp=temp->next;
                   }
                    temp->next=head; 
                    //head->next=NULL;
                    //head=secondtemp;
                    return head;
                }
                break;*/
            case 2:
                    if(temp->next==head)
                    {
                        head=NULL;
                        return head;
                    }
                    else
                    {
                        while(temp->next->next!=head)
                        {
                            temp=temp->next;
                        }
                        temp->next=head;
                        return head;
                    }
                break;
            case 3 :
                printf("enter which position");
                scanf("%d",&pos);
                if(pos==1)
                {
                    if(temp->next==head)
                    {
                        head=NULL;
                        return head;
                    }
                    else
                    {
                        while(temp->next!=head)
                        {
                            temp=temp->next;
                        }
                            secondtemp=head->next;
                            temp->next = secondtemp;
                            head->next=NULL;
                            return secondtemp;
                    }
                }
                else{
                    for(i=1;i<pos-1;i++)
                    {
                        temp=temp->next;

                    }
                    temp->next=temp->next->next;
                    return head;
                }
                break;
        }       
    }
}
