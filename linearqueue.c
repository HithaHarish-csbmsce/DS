#include<stdio.h>
#include<stdlib.h>
#define size 3
int queue[size];
int front=-1;
int rear=-1;
void enqueue(int);
void dequeue();
void display();

void main(){
int ch,item;
while(1)
{
    printf("\n1.ENQUEUE\n");
    printf("\n2.DEQUEUE\n");
    printf("\n3.DISPLAY\n");
    printf("\n4.EXIT\n");
    printf("ENTER YOUR CHOICE:");
    scanf("%d",&ch);
switch(ch){
case 1:printf("Enter value to be inserted:");
       scanf("%d",&item);
       enqueue(item);
       break;
case 2:
       dequeue();
       break;
case 3:
       display();
       break;
case 4:
       exit(0);
       break;
default:printf("INVALID CHOICE");
        break;
}
}
}
void enqueue(int item){
if (rear==size-1){
printf("QUEUE IS FULL");}
else if (front==-1 && rear==-1){
front =rear=0;}
else{
rear=rear+1;}
queue[rear]=item;
}
void dequeue(){
if (front==-1 && rear==-1){
printf("QUEUE IS EMPTY");}
else if (front==rear){
front=rear=-1;
}
else{
printf("Deleted element is:");
printf("%d",queue[front]);
front++;
}
}

void display(){
    if (front==-1 &&rear==-1){
        printf("QUEUE IS EMPTY");}
    else{
        int i;
        printf("Queue elements are:\n");
        for (i=front;i<rear+1;i++){
                printf("%d",queue[i]);}
    }
}

