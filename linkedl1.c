#include <stdio.h>
 #include <stdlib.h>

 struct node 
 {
     int data;
     struct node *next;
 };
 
  struct node *insert(struct node *head);


 int main() 
 {
     struct node *head;
     head=0;
     struct node *temp;
     struct node *newnode;
 int choice;
     while(1) 
     {
     newnode = (struct node*)malloc(sizeof(struct node));
     printf("enter the data :");
     scanf("%d",&newnode->data);
     newnode->next=0;

 if(head==0) 
 {
     head=newnode;
     temp=newnode;
 }
 else 
 {
    temp->next=newnode;
    temp=newnode;
                                                                                                                                           
 }
 printf("do u want to continue (0,1)?\n");
 scanf("%d",&choice);
 if(choice==0) 
 {
     break;
 }
}
 
printf("Thank you \n");
printf("Your list- \n");


 temp=head;
 while(temp !=0) 
 {
     printf("%d",&temp->data);
     temp=temp->next;
 }


    return 0;
}