#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max 5
struct CircularQueue
{
    int data;
};

struct CircularQueue queue[max];
int front=-1,rear=-1;
int ele,value;

void insert(int ele);
void delete();
void display();

int main()
{
    int c;
    while(1)
    {
        printf("Enter choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&c);
        
        switch(c)
        {
            case 1:
            printf("Enter value to be inserted: ");
            scanf("%d",&value);
            insert(value);
            break;
            
            case 2:
            delete();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            exit(0);
            
            default:
            printf("Invalid choice");
            break;
            
            
        }
    }
    return 0;
}

void insert(ele)
{
    if ((front==0 && rear == max-1) || front==rear+1)
    {
        printf("OVERFLOW!");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%max;
    queue[rear].data=ele;
}

void delete()
{
    if(front==-1)
    {
        printf("UNDERFLOW!");
        return;
    }
    printf("Deleted item : %d",queue[front].data);
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%max;
    }
}

void display()
{
    int i;
    if (front==-1)
    {
        printf("Empty");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%max)
        {
            printf("%d\n",queue[i].data);
        }
        printf("%d\n",queue[i].data);
    }
    
}




