#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;

};

int main()
{
    int i,ch=0;
    struct node *head=0 , *newnode , *temp ;
    
    while (ch==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data in the linked list\n");
        scanf("%d",&newnode->data);


        if (head==0)
        {
            head=newnode;
            temp=newnode;

        }

        else
        {
           temp->next=newnode;
           temp=newnode;

        }
        printf("Do you want to continue (0/1)\n");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }

    temp=head;
    while(temp!=0)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    
}

struct node insertbeg( struct node *head)
{
    int newdata;
    struct node *ptr ;
    ptr= (struct node*)malloc(sizeof(struct node));
    
    printf("enter the data that you want to enter");
    scanf("%d",&ptr->data);

    ptr->next=head;
    head=ptr;

   return *head;

}
