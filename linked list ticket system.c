/*Using a linked list dynamic data structure implement a queue structure IT services ticketing system. 
daniel apetri
win 10
borland
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

struct node
{
    char name[SIZE];
    char contact[SIZE];
    char description[SIZE];
    char time[5];
    struct node *next;
}*head = NULL,*tail = NULL;

//prototype
void enqueue(char *,char *,char *,char *);
void dequeue();
void display();

int main ()
{
    //create variables
    char option;
    char n[SIZE];
    char c[SIZE];
    char d[SIZE];
    char t[SIZE];
    
    
    do
    {
        printf("MENU\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\n");
        printf("enter your option\n");
        scanf("%c",&option);
        flushall();
        
        switch(option)
        {
            case '1':
            {
                printf("enter the name of the client\n");
                //scanf("%s",n);
                gets(n);
                flushall();
                printf("enter the contact number of the client\n");
                //scanf("%s",c);
                gets(c);
                flushall();
                printf("enter the description of the product\n");
                //scanf("%s",d);
                gets(d);
                flushall();
                printf("enter the time of the phone call\n");
                //scanf("%s",t);
                gets(t);
                flushall();
                //function to enqueue
                enqueue(n,c,d,t);
                break;
            }
            case '2':
            {
                dequeue();
                break;
            }
            case '3':
            {
                display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                printf("wrong entry \\ try again\n");
            }
        }
    }while (option != 4);
        
    getchar();
    
}//end main

//function to enqueue the data 
void enqueue(char *a, char *b, char *c, char *d)
{
    struct node *newnode;
    
    //allocate memory to he new code
    newnode = (struct node*)malloc(sizeof(struct node));
    
   //check if the memory was allocated
    if (newnode == NULL)
    {
        printf("the memory fail to be allocated!\n");
    }
    else
    {
        //give data to the new pointer
        strcpy(newnode->name ,a);
        strcpy(newnode->contact , b);
        strcpy(newnode->description , c);
        strcpy(newnode->time , d);
        newnode->next = NULL;
    }
    
    //printf("am ajuns aici\n");
    if (head == NULL)
    {
        //if head equals to null the head ,tail and newnode have the same address
        head = tail = newnode;
    }
    else
    {
        //pointer tail points to the next pointer and is equal to the newnode address
        tail->next = newnode;
        tail = newnode;
    }
    printf("success!\n");
    
}//end enqueue()

//function to dequeue()
void dequeue()
{
    struct node *temp;
    
    //check if the queue is full else dispplay the deleted node
    if (head == NULL)
    {
        printf("queue is empty!\n");
    }
    else
    {
        //local pointer temp is equal to the head
        temp = head;
        //to make dequeue go to the next pointer and dequeu from the head
        head = head ->next;
        
        //print the deleted data in the list
        printf("deleted name: %s\n",temp->name);
        printf("deleted contact number: %s\n",temp->contact);
        printf("deleted item description: %s\n",temp->description);
        printf("deleted time: %s\n",temp->time);
        free(temp);
    }
}//end function dequeue

//function to display()
void display()
{
    struct node *temp;
        
    if (head == NULL)
    {
          printf("queue is empty!\n");
    }
    else
    {
        //the address of the temp = with the address of the head
        temp = head;
        //if the pointer is not equal to NULL print the data until is NULL
        while (temp->next != NULL)
        {
            printf("name: %s ,contact: %s, description: %s, time %s\n",temp->name,temp->contact,temp->description,temp->time);
            temp = temp ->next;
        }
        
        //print the data in the first element in the list
        printf("name: %s ,contact: %s ,description: %s, time %s\n",temp->name,temp->contact,temp->description,temp->time);
        
    }
    
}//end display()