#include<stdio.h>
int main(){
int i,size;
//Student,is used to store student details- USN, Name, Mobile Number
struct Student{
    char USN[10];
    char Name[40];
    int Number[10];
};
struct Student student[50];
printf("\n Enter the number of students:");
scanf("%d",&size);
printf("\nWELCOME TO STUDENT REGISTARTION PORTAL");
for (i=0;i<size;i++)
{
    printf("\nSTUDENT: %d",i+1);
    printf("\nEnter your 10 digit USN:");
    scanf("%s",student[i].USN);
    printf("Enter your Name");
    getchar();
    gets(student[i].Name);
    printf("Enter your 10 digit Mobile Number");
    scanf("%d",&student[i].Number);
}
}
