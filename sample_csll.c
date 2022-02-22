#include<stdio.h>
#include<stdlib.h>

#define clear() printf("\033[H\033[J")
struct Node
{
	int data;
	struct Node *next;
};
int count(struct Node* head)
{
	int n=0;
	struct Node* temp = head;
	do
	{
		temp = temp->next;
		n++;
	}while(temp != head);
	return n;
}
struct Node* insertionAtBeg(struct Node** head,int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if((*head) == NULL)
	{
		newnode->data = data;
		newnode->next = newnode;
		(*head) = newnode;
		printf("Inserted Successfully! \n");
	}
	else
	{
		newnode->data = data;
		newnode->next = *head;
		struct Node *temp = *head;
		do
		{
			temp = temp->next;
		}
		while(temp->next != *head);
		temp->next = newnode;
		(*head) = newnode;
		printf("Inserted Successfully! \n");
	}
}
void insertionAtEnd(struct Node** head,int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if(*head == NULL)
	{
		newnode->data = data;
		newnode->next = newnode;
		*head = newnode;
		printf("Inserted Successfully! \n");
	}
	else
	{
		struct Node* temp = *head;
		do
		{
			temp = temp->next;
		}
		while(temp->next != *head);

		newnode->data = data;
		newnode->next = *head;
		temp->next = newnode;
		printf("Inserted Successfully! \n");
	}
}
void insertionAtMiddle(struct Node** head,int data,int pos)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if(pos<1 || (pos>count(*head)+1 && pos!=count(*head)+1))
	{
		printf("Wrong position!");
		return;
	}
	else
	{
		struct Node* temp = *head,*prev;
		int i;
		do
		{
			prev = temp;
			temp = temp->next;
		}
		while(temp->next != *head);

		newnode->data = data;
		newnode->next = temp;
		prev->next = newnode;
		printf("Inserted Successfully! \n");
	}
}
void insertion(struct Node** head)
{
	int ch=0,pos=-1,data;
	clear();
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
				insertionAtBeg(head,data);
				break;
			case 2:
				insertionAtEnd(head,data);
				break;
			case 3:
				printf("Enter Position : ");
				scanf("%d",&pos);
				if(pos == 1) insertionAtBeg(head,data);
				else if(pos == count(*head)+1) insertionAtEnd(head,data);
				else insertionAtMiddle(head,data,pos);
				break;
			default:
				return;
		}
	}
	clear();
}

void deletionAtBeg(struct Node** head)
{
	if(*head == NULL)
	{
		printf("List is empty!");
		return;
	}
	else if(count(*head) == 1)
	{
		//struct Node* temp = *head;
		*head = NULL;
		free(*head);
		printf("Deleted Successfully! \n");
	}
	else
	{
		struct Node*temp = *head;
		do
		{
			temp = temp->next;
		}
		while(temp->next != *head);
		struct Node* p = temp->next;
		temp->next = (*head)->next;
		(*head) = (*head)->next;
		free(p);
		printf("deleted Successfully! \n");
	}
}
void deletionAtEnd(struct Node** head)
{
	if(*head == NULL)
	{
		printf("List is empty!");
		return;
	}
	else if(*head == (*head)->next)
	{
		//struct Node* temp = *head;
		*head = NULL;
		free(*head);
		printf("Deleted Successfully! \n");
	}
	else
	{
		struct Node* temp = *head,*prev;
		do
		{
			prev = temp;
			temp = temp->next;
		}
		while(temp->next != *head);
		prev->next = temp->next;
		free(temp);
		printf("deleted Successfully! \n");
	}
}
void deletionAtMiddle(struct Node** head,int pos)
{
	if(*head == NULL)
	{
		printf("list is empty");
		return;
	}
	if(pos<1 || (pos>count(*head)))
	{
		printf("Wrong position!");
		return;
	}
	else
	{
		int i;
		struct Node* temp,*prev;
		temp = *head;
		i=1;
		do
		{
			prev = temp;
			temp= temp->next;
			i++;
		}
		while(temp->next != *head && i<pos);
		prev->next = temp->next;
		free(temp);
		printf("deleted Successfully! \n");
	}
}


void deletion(struct Node** head)
{
	int ch=0,pos=0;
	clear();
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
				deletionAtBeg(head);
				break;
			case 2:
				deletionAtEnd(head);
				break;
			case 3:
				printf("Enter Position : ");
				scanf("%d",&pos);
				if(pos == 1) deletionAtBeg(head);
				else if(pos == count(*head)) deletionAtEnd(head);
				else deletionAtMiddle(head,pos);
				break;
			default:
				return;
		}
	}
	clear();
}



void display(struct Node* head)
{
	struct Node* temp = head;
	do
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	while(temp!=head);
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
	while(temp!=head);
	if(c==0) printf("Element Not Found!");
}

int main()
{
	struct Node *head=NULL;
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
				insertion(&head);
				break;
			case 2:
				if(head != NULL)
					deletion(&head);
				else printf("list is empty!");
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
