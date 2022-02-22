#include<stdio.h>

// sorting
void selection_sort(int *a, int n)
{
  int temp = 0, index = 0, min = 0;
  for(int i = 0; i<n; i++)
  {
    min = a[i];
    for(int j = i; j<n; j++)
    {
      if(min >= a[j])
      {
        min = a[j];
        index = j;
      }
    }
    temp = a[i];
    a[i] = min;
    a[index] = temp;
  }
}

int rear = -1, front = -1, tar;
void enqueue(int queue[], int data, int size) {
  if (front == size - 1 || rear == size - 1)
    printf("Queue is full!!");
  else {
    if (rear == -1) {
      front++;
      rear++;
    } else rear++;
    queue[rear] = data;
    printf("Inserted succesfully!!");
  }
}
void dequeue(int queue[], int size) {
  if ((front == -1 && rear == -1) || front == rear + 1)
    printf("queue is empty!!");
  else {
    // sorting the Queue
    selection_sort(queue, size);
    printf("enter the target element : "); scanf("%d",&tar);
    printf("the minimum marks is : %d",queue[front]);
    for (int i = front; i <= rear; i++) {
    if(queue[i]!=tar) front++;
    }
    display(queue);
    printf("dequeued successfully!!");
  }
}
void display(int queue[]) {
  if ((front == -1 && rear == -1) || front == rear + 1)
    printf("queue is empty!!");
  else {
    printf("Elements in queue is : ");
    for (int i = front; i <= rear; i++) {
      printf(" %d", queue[i]);
    }
  }
}
int main() {
  int n, choice, input;
  printf("enter the size of queue : ");
  scanf("%d", & n);
  if (n <= 0) {
    printf("Invalid size !!\n");
  } else {
    int queue[n];
    while (1) {
      printf("\n---------------------------\n");
      printf("1.Insert marks\n2.delete based on target\n3.EXIT");
      printf("\nenter your choice : ");
      scanf("%d", & choice);
      switch (choice) {
      case 1:
        printf("enter the marks : ");
        scanf("%d", & input);
        enqueue(queue, input, n);
        break;
      case 2:
        dequeue(queue,n);
        break;
      case 3:
        return 0;
        break;
      default:
        printf("Invalid operation!!");
        break;
      }
    }
  }
}
