#include<stdio.h> c
#include<ctype.h>
#define SIZE 50

char Stack[SIZE];
int top=-1;

push(char elem){
Stack[++top]=elem;
}

char pop(){
return (Stack[top--]);
}

int pr(char symbol){
if (symbol=="^"){
    return (3);}
else if (symbol=="*" || symbol=="/"){
    return (2);}
else if (symbol=="+" || symbol=="-"){
    return (1);}
else {
    return (0);}
}

void main(){
char infix[50],postfix[50],ch,elem;
int i=0,k=0;
printf("Enter Infix Expression:");
scanf("%s",infix);
push("#");
while((ch==infix[i++])!='\0'){
    if (ch=="("){
        push(ch);
    }
    else if (isalnum(ch)){
        postfix[k++]=ch;
    }
    else if (ch==")"){
        while (Stack[top]!="("){
            postfix[k++]=pop();
        }
    elem=pop();
    }
    else
    {
        while (pr(Stack[top])>=(pr(ch))){
            postfix[k++]=pop();
        push(ch);
    }
    }
}
while(Stack[top]!="#"){
    postfix[k++]=pop();
}
postfix[k]='\0';
printf("Postfix Expression is:%s\n",postfix);
}

