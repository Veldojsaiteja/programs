#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};
int count(struct Node* head)
{
	int n=0;
	struct Node* temp=head;
	do
	{
		temp = temp->next;
		n++;
	}
	while(temp != NULL);
	return n;
}
void insertionAtBeg(struct Node** head,int data,struct Node** tail)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if((*head) == NULL)
	{
		newnode->data = data;
		newnode->next = newnode;
		newnode->prev = newnode;
		(*head) = newnode;
		(*tail) = newnode;
		printf("Inserted Successfully! \n");
	}
	else
	{
		newnode->data = data;
		newnode->next = *head;
		newnode->prev = *tail;
		(*tail)->next = newnode;
		*head = newnode;
		printf("Inserted Successfully! \n");
	}
}
void insertionAtEnd(struct Node** head,int data,struct Node** tail)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if(*head == NULL)
	{
		newnode->data = data;
		newnode->next = newnode;
		newnode->prev = newnode;
		*head = newnode;
		*tail = newnode;
		printf("Inserted Successfully! \n");
	}
	else
	{
		newnode->data = data;
		newnode->next = *head;
		newnode->prev = (*tail);
		(*tail)->next = newnode;
		(*tail) = newnode;
		(*head)->prev = newnode;
		printf("Inserted Successfully! \n");
	}
}
void insertionAtMiddle(struct Node** head,int data,int pos)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if(pos<1 ||(pos>count(*head)+1 && pos!=count(*head)+1))
	{
		printf("Wrong position!");
		return;
	}
	else
	{
		struct Node* temp = *head,*prev;
		int i=1;
		do
		{
			prev = temp;
			temp= temp->next;
			i++;
		}
		while(temp->next != NULL && i<pos);

		newnode->data = data;
		newnode->next = temp;
		prev->next = newnode;
		newnode->prev = prev;
		temp->prev = newnode;
		printf("Inserted Successfully! \n");
	}
}
void insertion(struct Node** head,struct Node**tail)
{
	int ch=0,pos=-1,data;
	system("cls");
	while(1)
	{
		printf("\n------------------------------\n");
		printf("1.) Insertion At begining.\n");
		printf("2.) Insertion At End.\n");
		printf("3.) Insertion In The Middle.\n");
		printf("4.) Back \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		printf("\n------------------------------\n");
		if(ch ==1 || ch==2 || ch==3)
		{
			printf("Enter data to be inserted :");
			scanf("%d",&data);
		}
		switch(ch)
		{
			case 1:
				insertionAtBeg(head,data,tail);
				break;
			case 2:
				insertionAtEnd(head,data,tail);
				break;
			case 3:
				printf("Enter Position : ");
				scanf("%d",&pos);
				printf("nodes :%d\n",count(*head)+1);
				if(pos == 1)insertionAtBeg(head,data,tail);
				else if(pos == count(*head)+1){
				   insertionAtEnd(head,data,tail);
				}
				else insertionAtMiddle(head,data,pos);
				break;
			default:
				return;
		}
	}
	system("cls");
}

void deletionAtBeg(struct Node** head,struct Node** tail)
{
	if(*head == NULL)
	{
		printf("List is empty!");
		return;
	}
	else if(count(*head) == 1)
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		struct Node *temp = *head;
		*head = (*head)->next;
		(*head)->prev = *tail;
		(*tail)->next = *head;

		free(temp);
		printf("deleted Successfully! \n");
	}
}
void deletionAtEnd(struct Node** head,struct Node** tail)
{
	if(*head == NULL)
	{
		printf("List is empty!");
		return;
	}
	else if(count(*head) == 1)
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		struct Node *temp = *tail;
		*tail = (*tail)->prev;
		(*head)->prev = *tail;
		(*tail)->next = *head;

		free(temp);
		printf("deleted Successfully! \n");
	}
}
void deletionAtMiddle(struct Node** head,int pos)
{
	if(pos<1 || pos>count(*head))
	{
		printf("Wrong position!");
		return;
	}
	else
	{
		int i=1;
		struct Node* temp = *head,*prev;
		do
		{
			prev = temp;
			temp= temp->next;
			i++;
		}while(temp->next != NULL && i<pos);
		prev->next = temp->next;
		temp->next->prev = prev;
		free(temp);
		printf("deleted Successfully! \n");
	}
}


void deletion(struct Node** head,struct Node** tail)
{
	int ch=0,pos=0;
	system("cls");
	while(1)
	{
		printf("\n------------------------------\n");
		printf("1.) Deletion At begining.\n");
		printf("2.) Deletion At End.\n");
		printf("3.) Deletion In The Middle.\n");
		printf("4.) Back \n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		printf("\n------------------------------\n");
		switch(ch)
		{
			case 1:
				deletionAtBeg(head,tail);
				break;
			case 2:
				deletionAtEnd(head,tail);
				break;
			case 3:
				printf("Enter Position : ");
				scanf("%d",&pos);
				if(pos == 1) deletionAtBeg(head,tail);
				else  if(pos == count(*head)) deletionAtEnd(head,tail);
				else deletionAtMiddle(head,pos);
				break;
			default:
				return;
		}
	}
	system("cls");
}


void display(struct Node* head)
{
	struct Node* temp = head;
	do
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	while(temp != head);
}
void search(struct Node* head,int element)
{
	int c=0,i=1;
	struct Node* temp = head;
	do
	{
		if(element == temp->data)
		{
			printf("Element found at %d position.",i);
			c++;
			break;
		}
		temp=temp->next;
		i++;
	}
	while(temp != NULL);
	if(c==0) printf("Element Not Found!");
}

int main()
{
	struct Node *head=NULL,*tail=NULL;
	int ch=0,data=0;
	while(1)
	{

		printf("\n------------------------------\n");
		printf("1.) Insertion \n");
		printf("2.) Deletion \n");
		printf("3.) Display \n");
		printf("4.) Search \n");
		printf("5.) Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		printf("\n------------------------------\n");
		switch(ch)
		{
			case 1:
				insertion(&head,&tail);
				break;
			case 2:
				if(head != NULL)
				  deletion(&head,&tail);
				else printf("List is Empty!.");
				break;
			case 3:
				if(head != NULL)
				{
					printf("Elements are : ");
					display(head);
				}
				else printf("List is empty\n");
				break;
			case 4:
				if(head != NULL)
				{
					printf("Enter data to be searched :");
					scanf("%d",&data);
					search(head,data);
				}
				else printf("List is empty!");
				break;
			case 5:
				exit(0);
			default:
				printf("Wrong input!");
				break;
		}
	}
	return 0;
}
