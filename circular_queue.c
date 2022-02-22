#include<stdio.h>

int rear = -1, front = -1;
void enqueue(int queue[], int data, int size) {
  if ((rear+1)%size == front)
    printf("Queue is full!!");
  else {
    if (rear == -1) {
      front = (front + 1);
      rear = (rear + 1);
    } else rear = (rear + 1)%size;
    queue[rear] = data;
    printf("enqueued succesfully!!");
  }
}
void dequeue(int size) {
  if ((front == -1 && rear == -1))
    printf("queue is empty!!");
  else if(front == rear){
  front = rear = -1;
  printf("dequeued successfully!!");
  }
    else{
    front = (front + 1)%size;
    printf("dequeued successfully!!");
    }

 }
void display(int queue[], int size) {
  if ((front == -1 && rear == -1))
    printf("queue is empty!!");
  else {
    printf("Elements in queue is : ");
    int i = front;
    while(i!=rear)
    {
    printf(" %d",queue[i]);
    i = (i+1)%size;
    }
    printf(" %d",queue[i]);
  }
}
void peek_front(int queue[],int size) {
  if ((front == -1 && rear == -1))
    printf("queue is empty!!");
  else
    printf("Front element is : %d", queue[front]);
}
void peek_rear(int queue[], int size) {
if ((front == -1 && rear == -1))
    printf("queue is empty!!");
  else
    printf("Rear element is : %d", queue[rear]);
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
      printf("1.enqueue\n2.dequeue\n3.DISPLAY\n4.front element\n5.rear element\n6.EXIT");
      printf("\nenter your choice : ");
      scanf("%d", & choice);
      switch (choice) {
      case 1:
        printf("enter the element : ");
        scanf("%d", & input);
        enqueue(queue, input, n);
        break;
      case 2:
        dequeue(n);
        break;
      case 3:
        display(queue,n);
        break;
      case 4:
        peek_front(queue,n);
        break;
      case 5:
        peek_rear(queue,n);
        break;
      case 6:
        return 0;
        break;
      default:
        printf("Invalid operation!!");
        break;
      }
    }
  }
}
