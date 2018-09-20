/*develop a program that will perform security authorisation based on access codes.
the access code is a 4 single-integer number and compare it to an authorised access code.
should allow user to decrypt and encrypt code.
default access code is 4523 thos must be stored in a 1-d array called access_code and should not be change
You should use a diffrent 1-d array to read the code entered by the user.
Daniel Apetri
win 10
Borland c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 5


//prototype
void display(void);
void enter_code(char *,int *);
void encryption_algorithm(char *,char *,int* ,int* ,int*);
void swap(char* ,char*);
void decryption_algorithm(char * ,int *);
void verify(char * ,char *,int * ,int *);
void count(int* ,int* ,int*);
void end(int *);



int main()
{
    //create variables and store data in them
    char access_code[SIZE] = "4523";//default code
    char ent_code[SIZE]={'\0'};// code you enter to 
    char option;//variable to select the one option in the menu
    int g=0,j=0;//counter to count how many times the enter correct or incorrect
    int nu =0;//variable to check if the options were entered in the correct order
    int ok = 0;
    
    do
    {
        //function to display the menu
        display();
    
        //display the mesage to the user to choose a option from the menu
        printf("\nEnter one of the options in the menu \n");
        option = getchar();
        flushall();
        
        //use a switch statement to choose an option given in the menu
        switch (option)
        {
            case '1':
            {  
                //function to enter the code
                enter_code(ent_code ,&nu);
                
                break;
            }
            case '2':
            {
                //function to encrypt the code 
                encryption_algorithm(ent_code, access_code, &g,&j,&nu);
                
                break;
            }
            case '3':
            {
                //function to decypt the entered code
                decryption_algorithm(ent_code,&nu);
                break;
            }
            case '4':
            {
                //function to count the correct and incorrect entries
                count(&g,&j,&nu);
                break;
            }
            case '5':
            {
                end (&ok);
            }
            default:
            {
                printf("\nYou enter the wrong option\n");
                printf("Please try again\n");
                break;
            }// end default
            
        }
        
    }
    while (option != '5');//repeat until the user will press 5
    
    getchar();
    return 0;
    

}// end main

//implement the display() function
void display()
{
    //print the menu
    printf("\n");
    printf( "1. Enter code \n"
            "2. Encrypt code and verify if correct (i.e., matches authorised access code)\n"
            "3. Decrypt code \n"
            "4. Display the number of times the code was entered (i) Successfully (ii) Incorrectly \n"
            "5. Exit Program\n");    
    
}//end function display()

//implement enter_code()
void enter_code(char array[],int *nu)
{
    int ok =0;
    int lenght,i;
    *nu=1;
    
    //mesage to the user to enter the code
    printf("Enter Code\n");
    
    //gets(array);
    scanf("%s",array);
    flushall();
    
    lenght= strlen(array);
    
    //check if the entered code has the correct size
    if (lenght!=SIZE-1)
    {   
        printf("your code does not have 4 elements\n");
        *nu =2;
    }
    else
    {
        //for loop to check if every elememt in the code is a digit or not
        for (i=0;i<SIZE-1;i++)
        {
            //check if the code entered is only made from digits
            if (isdigit(*(array+i))==0)
            {
                ok =1;
                *nu=2;
            }
        }
    }
    
    //display a message to the user to enter 4 elemets and they must be digits
    if ( ok == 1 )
    {
        printf("enter a 4 digit access code of size 4 elements\n");
    }
    
    //if the code wasn't enetered correct the user must try again
    if (*nu == 2 )
    {
        printf("Enter the access code again\n");
    }
    
}//end enter code()

//implement encryption_algorithm()
void encryption_algorithm (char array[] ,char array1[], int *g , int *j , int *nu)
{
    int i;
     
    // verification to see if the user entered option 1 
    if(*nu == 1)
    {
        //function to swap the 1st element with the 3rd
        swap( array, array+2);
        
        //function to swap the 2nd element with the 4th
        swap( array+1, array+3);
    
        // add 1 to each element in the array    
        for (i=0; i<SIZE-1; i++)
        {
            *(array+i) = *(array+i) + 1;
            //If any number has a value equal to 10(in our case if is the next element in the aschii code replace with 0), change this value to 0. 
            if (*(array +i) == '9'+1)
            {
                *(array +i) = '0';
            }
        }
        
        //function to check if the encrypted code is correct or the same with the access_code
        verify (array, array1, &*g, &*j);
        
        *nu = 3;
    }
    else
    {
        printf("You must enter a valid code to performe this option\n");
        *nu =0;
        
    }//end if statement
    
    
}//end encryption_algorithm

//implement verify()
void verify (char array[] ,char array1[], int *g ,int *j)
{
    int ok;
    
    //will return 0 if the strings are the same
    ok = strcmp(array, array1);
    
    //check if the entered code is the same with the access code
    if (ok==0)
    {
        printf("CORRECT CODE\n");
        (*g)++;
    }
    else
    {
        printf("ERROR CODE\n");
        (*j)++;
    }
    
}//end verify()

//implement decryption_algorithm()
void decryption_algorithm(char array[] ,int *nu)
{ 
   
    int i;
    
     //if the code was encripted
    if ((*nu == 3) || (*nu == 4))
    {
    
        for (i=0;i<SIZE-1;i++)
        {
            // substract 1 to each element in the array
            *(array+i) = *(array + i) - 1;
            //if the character before '0' is -1 change it with '9'
            if (*(array +i) == '0' - 1)
            {
                *(array +i) = '9';
            }
        }   
        
        //function to swap the elements in the array for decryption
        swap(array,array+2);
        
        //function to swap the elements in the array for decryption
        swap(array+1,array+3);
        
        //puts(array);
        printf("the decrypted code is: %s\n",array);
        
        *nu = 5;
       
    }
    else
    {
        printf("you can't decrypt the code before is encrypted\n");
        *nu = 3;
        
    }//end if
    

}//end decryption_algorithm

//implement count()
void count(int *g,int *j,int *nu)
{
    //count the correct and the incorrect entries
    if ((*nu == 3) || (*nu == 5))    
    {
        printf(" the user enter %d times the correct code\n",*g);
        printf(" the user enter %d times the incorrect code\n",*j);
        (*nu = 4);
        
    }
    else
    {
        printf("the code must be validated to check the correct and incorrect entries \n");
        *nu = 0;
    }//end if
    
}//end count()
 
//implement swap()
void swap (char *a, char *b)
{
    char temp;
    
    //swap the elements of the array
    temp = *a;
    *a=*b;
    *b = temp;
    
}//end swap()

//implement end()
void end (int *a)
{
    *a =1;
    //statement to exit the program
    if (*a == 1)
    {
        exit(0);
    }
}// end end()
