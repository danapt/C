/* program that will operate on an ATM machine for a bank. 
This program should allow bank customers to manage their PIN.
PIN is a 4 digit number.
Daniel Apetri
windows 10
borland
*/
#include <stdio.h>
#define SIZE 4

//start main
int main()
{
    // create variables and give them data
    int pin[SIZE]= {1,2,3,4};       // this is the default PIN ,will use an array
    char option;                    //use this variable to choose one of the options in the menu
    int pin_ver[SIZE] = {0};        //this array will be used to verify if the entry of the user is correct 
    int change_pin[SIZE] = {0};     //this array will be used when the user wants to change his default PIN and entry a new one // new PIN array
    int change_pin2[SIZE] = {0};    //array to verify the new PIN the user has enter // verification new PIN array
    int counter_correct = 0;        //index that counts how many times the user enters the correct PIN
    int counter_incorrect = 0;      //index that counts how many times the user enters the incorrect PIN
    int i = 0;                      //index used to help go through array containers
    
   printf("Welcome to the ATM\n");//nice welcome for the customers of the ATM
    
     // will use a do while loop to reped the options as many times the user wants 
    do
 	{
       
        printf("\n1. Enter PIN and verify correct\n");
        printf("2. Change PIN\n");
        printf("3. Display the number of times the PIN was entered\n");
        printf("4. Exit Program\n");
    
        //the user will have to choose one of the options displayed in the menu
		
        printf(" \nEnter one of the options that are displayed in the menu\n");
        option = getchar();
        flushall();
    
        // will use a switch statement to choose an option from the ATM menu
    
        switch (option)
        {
            //4 cases on switch that are representing our 4 options in the display menu
            // case 1 verify if the  PIN is correct or incorrect
            case '1':
            {
                printf("Enter your PIN\n");
                //use for loop to give data into an verification array
                for (i=0;i<SIZE;i++)
                {
                    scanf("%d",&pin_ver[i]);
                    flushall();
                }//end for loop 
                
   
                //if statement to see if the verification PIN is correct  and the containers in the array pin are equal with the elements in the pin verification array
                if ((pin[0] == pin_ver[0])&&(pin[1] == pin_ver[1])&&(pin[2] == pin_ver[2])&&(pin[3] == pin_ver[3]))
                    
                {  
                    printf("PIN is correct\n");
                    counter_correct++;
                } 
                else        //if the elements in the array verification pin are not equal with the elements in the array pin then the pin is incorrect
                {
                    printf("PIN is incorrect\n");
                    counter_incorrect++;
                }
                break;
                
            }//change your PIN option number 2 in the ATM meni
            
            case '2':
            {
                //using a for loop to give data into array change_pin  
                printf("Enter your new PIN\n");
                for (i=0;i<SIZE;i++)
                {
                    scanf("%1d",&change_pin[i]);
                    flushall();
                }
                //use a if statement to check if the elements in the array change pin are a number from 0 to 9
      
                 printf("Enter your new pin again \n");
                    
                // use a for loop to give data into each element in array change_pin2
                for (i=0;i<SIZE;i++)
                {
                    scanf("%1d",&change_pin2[i]);
                    flushall();
                }
                
                // will use a if statement to check if each element in the change pin is equal with the each element in the verification new pin array
                if ((change_pin[0] == change_pin2[0]) && (change_pin[1] == change_pin2[1]) && (change_pin[2] == change_pin2[2]) && (change_pin[3] == change_pin2[3]))
                {
                    printf("PIN has been changed\n");
                        
                    // use a for loop to give data into the array verification new pin
                    for (i=0;i<SIZE;i++)
                    {
                        pin_ver[i]=change_pin2[i];
                        pin[i]= pin_ver[i];
                        flushall();
                    }
                }
                else
                {
                    printf("PIN verification is incorrect\n");
                    printf("PIN was not changed\n");
                } 
                    
                break;
            }// this case will display how many time the PIN was enter correct and incorrect
            case '3':
            {
                printf("You enter %d times the correct PIN\n",counter_correct);
                printf("You enter %d times the incorrect PIN\n",counter_incorrect);
                break;
            }//will close the program gracefully
            
            case '4':
            {
                return 0;
            }
            default:
            {
                printf("\nYou enter the wrong option\n");
                printf("Please try again\n");
            }// end default
			
            
        }//end switch
    }// end while loop
    while ( option =='1'||'2'||'3'||'4');
 }//end main
    
    
    