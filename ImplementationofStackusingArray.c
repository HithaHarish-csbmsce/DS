#include<stdio.h>
#define SIZE 10
int Stack[SIZE];
int top=-1;
void isFull(){
    if (top==SIZE-1){
        printf("The Stack is full\n");
    }
    else{
        printf("The Stack has space,it is not full\n\n");
    }
}
void isEmpty(){
    if (top==-1){
        printf("The Stack is empty\n\n");
    }
    else{
        printf("The Stack has elements,it is not empty\n\n");
    }
}
int push(int element){
    if (top!=SIZE-1){
        top=top+1;
        Stack[top]=element;
        printf("%d is pushed to the stack\n\n",element);
    }
}
int pop(){
    if (top!=-1){
        int x=Stack[top];
        top--;
        printf("%d is popped\n\n",x);
    }
    else{
        isEmpty();
    }
}
int display(){
    printf("There are %d elements in the stack\n",top+1);
    if (top==-1){
        isEmpty();
    }
    else{
    printf("The elements in the Stack are:\n");
    for(int i=0;i<=top;i++){
        printf("%d\n",Stack[i]);
    }
}
}
int main(){
    int ip,element;
    while(1){
    printf("STACK OPERATIONS:\n\n");
    printf("1.Push\n2.Pop\n3.Display\n4.isFull\n5.isEmpty\n6.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ip);
    switch(ip){
        case 1:printf("Enter the element to push to the stack:");
               scanf("%d",&element);
               push(element);
               break;
        case 2:pop();
               break;
        case 3:display();
               break;
        case 4:isFull();
               break;
        case 5:isEmpty();
               break;
        case 6:exit(0);
    }

    }
}
