#include<stdio.h>
#include<stdlib.h>
#include <time.h>
struct Node
{
	int data,level;
	struct Node **next;
};

struct Node** search_list_for_insert(struct Node **head,int data,int level)
{
	struct Node* temp = *head;
	struct Node **store_Prev_add = (struct Node**)malloc((temp->level)*sizeof(struct Node*));
	for(int i = level-1;i>=0;i--)
	{
		while(temp->next[i] != NULL && data > temp->next[i]->data)
		{
				temp =temp->next[i];
		}
		store_Prev_add[i] = temp;
	}
	if(store_Prev_add[0] != NULL) return store_Prev_add;
	else return NULL;
}

struct Node** search_list_for_delete(struct Node **head,int data)
{
	struct Node* temp = *head;
	struct Node **store_Prev_add = (struct Node**)malloc((temp->level)*sizeof(struct Node*));
	for(int i = temp->level-1;i>=0;i--)
	{
		while(temp->next[i] != NULL && data > temp->next[i]->data)
		{
				temp =temp->next[i];
		}
		store_Prev_add[i] = temp;
	}
	temp = temp->next[0];
	if(temp != NULL && temp->data == data && store_Prev_add[0] != NULL) 
		return store_Prev_add;
	else return NULL;
}

int random1()
{
	srand(time(0)+rand());
	int r = rand()%3;
	return r;
}

void insert_skiplist(struct Node** head,int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->level = 0;
	for(int i=0;i<(*head)->level;i++)
	{
		if(random1()) (newnode->level)++;
	}
	if(newnode->level == 0) newnode->level = 1;
	newnode->next = (struct Node**)malloc((newnode->level) * sizeof(struct Node*));
	for(int i=0;i<newnode->level;i++) newnode->next[i] = NULL;
	if((*head)->next[0] == NULL)
	{
		for(int i=0;i<newnode->level;i++)
			(*head)->next[i] = newnode;
	}
	else
	{
		struct Node **store_Prev_add = search_list_for_insert(head,data,newnode->level);
		if(store_Prev_add == NULL)
		{
			for(int i=0;i<newnode->level;i++)
				(*head)->next[i] = newnode;
		}
		else{
			for(int i=newnode->level - 1;i>=0;i--)
			{
				newnode->next[i] = store_Prev_add[i]->next[i];
				store_Prev_add[i]->next[i] = newnode;
			}
		}	
	}
	printf("Inserted Successfully!\n");
}

void delete_skiplist(struct Node **head,int data)
{
	if((*head)->next[0] == NULL)
		printf("Skip List is Empty!");
	else
	{
		struct Node **store_Prev_add = search_list_for_delete(head,data);
		if(store_Prev_add == NULL)
		{
			printf("Element not found!");
			return;
		}
		struct Node **freeUP = (struct Node**)malloc((*head)->level*sizeof(struct Node*));
		int c=0;
		for(int i=0; i<(*head)->level; i++)
		{
			if(store_Prev_add[i]->next[i] != NULL && store_Prev_add[i]->next[i]->data == data)
			{
				freeUP[c++] = store_Prev_add[i]->next[i];
				store_Prev_add[i]->next[i] = store_Prev_add[i]->next[i]->next[i];
			}
		}
		for(int i=0;i<c;i++) if(freeUP[i] != NULL) free(freeUP[i]);
		printf("\nDeleted Successfully!\n");
	}
}

void display_SkipList(struct Node *head)
{
    for (int i=head->level - 1;i>=0;i--)
    {
        struct Node *temp = head->next[i];
        printf("\nLevel %d :",i);
        while (temp != NULL)
        {
            printf(" %d -> ",temp->data);
            temp = temp->next[i];
        }
        printf("NULL");
    }
}

int main()
{
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	//struct Node *Nil = (struct Node*)malloc(sizeof(struct Node));
	head->level = 4;
	head->next = (struct Node**)malloc((head->level) * sizeof(struct Node*));
	for(int i=0;i<head->level;i++) head->next[i] = NULL;
	int data,choice;
	while(1)
	{
		printf("\n-----------------a----\n");
		printf("1.) Insert");
		printf("\n2.) Delete");
		printf("\n3.) Display");
		printf("\n4.) Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("Enter Data: ");
			scanf("%d",&data);
			insert_skiplist(&head,data);
		}
		else if(choice == 2)
		{
			printf("Enter Data to be Deleted: ");
			scanf("%d",&data);
			delete_skiplist(&head,data);
		}
		else if(choice == 3)
		{
			printf("------:SKIP LIST:------\n");
			display_SkipList(head);
		}
		else return 0;
	}
}