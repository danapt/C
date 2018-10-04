/*Create a simple IT assets inventory that performs the following functions:
Add new item 
Delete old item 
Edit item 
Find item 
Record inventory
Sample list item:
Quantity Model              Cost
5            Dell 12345      2390.00
This program is to be implemented using an array. The code should use functions where appropriate and effective error checking.
Select an appropriate unique identifier (key
For the fifth function ‘Record inventory’ implement an appropriate sorting algorithm based 
on the design of max 2002 inventory items and create a file called ITinventory that is used to store the sorted items for reference. 
An additional variable within the file or filename argument will be required to date the inventory file.
In addition to the required user functions, create an additional display() in order to demonstrate your code after each addition, deletion or alteration. 
When the inventory is full send an alert to the user that no further items may be added. In order to demonstrate use an array of 5 with 3 pre-initialised contacts. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STRSIZE 21
#define SIZE 5

struct inv
{
    int quantity;
    char model[STRSIZE];
    float cost;
};

//prototype
void add(struct inv[]);
void del(struct inv[]);
void edit(struct inv[]);
void find(struct inv[]);
void record(struct inv[]);
void display(struct inv[]);


int main()
{
    struct inv array[SIZE]= {
                                {3, "imac",1234.12},
                                {10,"asus",700.1},
                                {9,"lenovo",999.99}
                            };
    char option;
   
    //int i;
    
    /*
    printf("enter data for the first 3 items\n");
    
    for (i=0; i<SIZE; i++)
    {
        if (i<3)
        {
            printf("enter how many items are:\n");
            scanf("%d",&array[i].quantity);
            printf("enter the model\n");
            scanf("%s",array[i].model);
            printf("enter the cost of the model:\n");
            scanf("%f",&array[i].cost);
        }

    }//end for loop
    */

    do
    {
        printf("\n");
        printf( "1. Add new item\n"
                "2. Delete old item\n"
                "3. Edit item\n"
                "4. Find item\n"
                "5. Record contacts\n"
                "6. Display\n"
                "7. Exit\n");
        
        printf("\nselect one of the options from the menu\n");
        option = getchar();
        flushall();
        
        switch(option)
        {
            case '1':
            {
                //function to add new item in the array
                add(array);
                break;
            }
            case '2':
            {
                 //function to delete old item by replacing with 0
                del(array);
                break;
            }
            case '3':
            {
                //function to rewrite the data in the structure
                edit(array);
                break;
            }
            case '4':
            {
                //function to find the item
                find(array);
                break;
            }
            case '5':
            {
                //function to read all the data in a file sorted by the model of the items
                record(array);
                break;
            }
            case '6':
            {
                //function to dipslay the items in the inventory
                display(array);
                break;
            }
            case '7':
            {
                return 0;
            }
            default:
            {
                printf("you enter a wrong oprion, please try again\n");
            }
            
        }//end switch

        
    }while(option != 7);
   
    
   
  flushall();  
  getchar();  
    
}//end main

//function to add new item 
void add(struct inv ar[])
{
    int i;
    
    
    //add data to the structure
    for (i=0; i<SIZE; i++)
    {
        if (i > 2)
        {
            printf("enter the quantity of the item :\n");
            scanf("%d",&ar[i].quantity);
            printf("enter the model\n");
            scanf("%s",ar[i].model);
            printf("enter the cost of the model:\n");
            scanf("%f",&ar[i].cost);
            flushall();
        }
    
        if (i == SIZE-1)
        {
            printf("\nthe inventory is full\n");
        }
        
        
    }
}//end add()

void del(struct inv arr[])
{
    // if the data in the structure will be marked with 0 it means that items in the inventory will be place as deleted
    int i;
    int c;
    
    printf("enter what item you want to delete\n");
    scanf("%d",&c);
    
    for (i = 0; i<SIZE; i++)
    {
        if(i == c-1)
        {
            arr[c-1].quantity = 0;
            strcpy(arr[c-1].model,"0");
            arr[c-1].cost = 0;
            flushall();
        }
    }//end for
    
}//end del()

//function to edit one of the items in the invenotry
void edit(struct inv a[])
{
    int pos;
    int i;
    int c=0;
    
    printf("enter the position of the item you want to change\n");
    scanf("%d",&pos);
    flushall();
    
    printf("if you want to change the quatity press 1 \n"
            "if you want to change the model press 2 \n"
            "if you want to change the cost press 3 \n");
    scanf("%d",&c);
    flushall();
    
    for (i=0;i<SIZE; i++)
    {
        if (i == pos-1)
        {
            if (c == 1)
            {
                printf("enter the new quantity of the item\n");
                scanf("%d",&a[pos-1].quantity);
                flushall();
            }
            else if (c == 2 )
            {
                printf("enter the new model of the item\n");
                scanf("%.20s",a[pos-1].model);
                flushall();
            }
            else if (c == 3 )
            {
                printf("enter the new cost of the item\n");
                scanf("%f",&a[pos-1].cost);
                flushall();
            }
            else
            {
                printf("you enter the wrong option \n");
            }
            
        }//end if
        
    }
    
}//end edit()

void display(struct inv a[])
{
    int i;
    
    for (i=0; i<SIZE; i++)
    {
        printf("for the item number %d the quantity is: %d \\,the model is: %s \\and the cost is:%.2f\n",i,a[i].quantity,a[i].model,a[i].cost);
    }
}//end diplay() 


//function to write the data in a file sorted
void record(struct inv a[])
{
    FILE *fp;
    struct inv temp;
    
    //use a sorting algorithm to sort the data in the inventory before to write it in the file
    for (int i =0; i<SIZE; i++)
    {
        for (int j = 0; j<SIZE; j++)
        {
            if (strcmp(a[j].model,a[j+1].model) > 0)
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    fp = fopen("ITinventory.txt", "w");
    
    //checking if the file was open and created
    if (fp == NULL)
    {
        printf("ERROR: file can't be open\n");
    }
    else
    {
        time_t t;
        time(&t);
        
        fprintf(fp,"Today's date and time: %s\n",ctime(&t));
        
        
        for (int i = 0 ; i < SIZE ; i++)
        {
            fprintf(fp, "Quantity of the item is: %d\n",a[i].quantity);
            fprintf(fp, "Model of the item is:    %s\n",a[i].model);
            fprintf(fp, "Cost of the item is:     %.2f\n",a[i].cost);
        }
    }//end if
    
    fclose(fp);
    
}//end record()

//function to find a item in the inventory
void find(struct inv a[])
{
    int i;
    char pos[STRSIZE];
    
    printf ("enter the model of the item you want to find in the inventory\n");
    gets(pos);
    flushall();
    
    for (i=0; i<SIZE; i++)
    {
        if (strcmp(a[i].model,pos)==0)
        {
            printf("item found\n");
            printf("the item you looking for is: %s\n",a[i].model);
        }
        else
        {
            printf("item is not in the inventory\n");    
        }
    }
  
    
    
}//end find 