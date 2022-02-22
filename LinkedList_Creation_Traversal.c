#include <stdio.h>
struct Node
{
  int data;
  struct Node * next;
};
void LinkedListData(struct Node * head)
{
  struct Node * ptr = head;
  while(ptr != NULL)
  {
    printf("%d ",ptr->data);
    ptr = ptr -> next;
  }
  printf("\n");
}
int main()
{
  int a = 0;
  struct Node * first = (struct Node *)malloc(sizeof(struct Node));
  struct Node * middle = (struct Node *)malloc(sizeof(struct Node));
  struct Node * end = (struct Node *)malloc(sizeof(struct Node));
  struct Node *head, *tail;
  //assigning values
  first->data = 10;
  first->next = middle;
  head = first;
  middle->data = 20;
  middle->next = end;
  end->data = 30;
  end->next = NULL;
  tail = end;
  LinkedListData(head);
  struct Node * p = (struct Node *)malloc(sizeof(struct Node));
  p->data = 20;
  p->next = first;
  head = p;
  LinkedListData(head);
  // printf("%s\n", "\n1 . insertion of node at beginning\n2 . insertion in between\n3 . insertion at the end");
  // scanf("%d",&a);
  // if(a == 1)
  // {
  //   struct Node * p;
  //   int x = 0;
  //   printf("enter the number : ");
  //   scanf("%d",&x);
  //   p->data = x;
  //   p->next = head;
  //   head = p;
  //   printf("%d  %u",p->data,p->next);
  //   //LinkedListData(head);
  // }
  // if(a == 2)
  // {
  //   int d = 0,x = 0;
  //   struct Node * ptr = head;
  //   scanf("enter the number to add : %d\n",&d);
  //   scanf("enter the number you wanna add after it : %d\n",&x);
  //   while(ptr->data == x)
  //   {
  //     struct Node * between;
  //     between->next = ptr->next;
  //     ptr->next = between;
  //     between->data = d;
  //     break;
  //   }
  //   LinkedListData(head);
  // }
return 0;
}
