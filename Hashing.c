#include<stdio.h>
#include <stdlib.h>

struct Hash
{
    int *hashTable;
    int *empty;
    int size;
}H;
    
void createHash(int size)
{
    H.size = size;
    H.hashTable = (int*)malloc(size*sizeof(int));
    H.empty = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < size; i++)
    {
        H.hashTable[i] = 0;
        H.empty[i] = 1;
    }
}

void insert(int data)
{
    int i = data % H.size;
    if (H.empty[i])
    {
        H.hashTable[i] = data;
        H.empty[i] = 0;
        printf("Inserted!\n");
    }
    else
    {
        int j = (i + 1) % H.size;
        do
        {
            if (H.empty[j])
            {
                H.hashTable[j] = data;
                H.empty[j] = 0;
                printf("Inserted!\n");
                return;
            }
            j = (j + 1) % H.size;
        } while (j != i);
        printf("Hash Table is full\n");
    }
}
int search(int data)
{
    int i = data % H.size;
    int j = i;
    do
    {
        if (H.hashTable[i] == data && !H.empty[i]) return i;
        i = (i + 1) % H.size;
    } while (i != j);
    return -1;
}

void Delete(int data)
{
    int i = search(data);
    if (i != -1)
    {
        H.hashTable[i] = 0;
        H.empty[i] = 1;
        printf("Deleted element is : %d\n",data);
    }
    else printf("Element does not exist\n");
}

void display()
{
    printf("Hash Table: ");
    for (int i = 0; i < H.size; i++)
        if (H.hashTable[i] == 0) continue;
        else printf("%d ",H.hashTable[i]);
    printf("\n");
}

int main()
{
    createHash(11);
    int choice, data;
    while (1)
    {
        printf("1.) Insert\n");
        printf("2.) Delete\n");
        printf("3.) Search\n");
        printf("4.) Display\n");
        printf("5.) Exit\n");
        printf("Enter option : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter data: ");
                    scanf("%d",&data);
                    insert(data);
                    break;
            case 2:
                    printf("Enter data to be deleted: ");
                    scanf("%d",&data);
                    Delete(data);
                    break;
            case 3:
                    printf("Enter Data to be Searched: ");
                    scanf("%d",&data);
                    if(search(data) == -1) printf("Data Not found in Hash Table\n");
                    else printf("Data Found in Hash Table\n");
                    break;
            case 4:
                    display();
                    break;
            case 5: return 0;
        }
    }
}