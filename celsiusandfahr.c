/* create 2 array wth 5 element for fahr and celsius 
give data fahr array and convert to celsius and run the program again giving data to the celsius array and convert 
to fahr
Dill win 10 borland
*/

#include <stdio.h>
# define SIZE 3

int main()
{
    float celsius[SIZE] = {0};
    float fahr[SIZE] = {0};
    int i = 0;
    
    //give data to celsius array using pointer notification
    
    for (i = 0; i<SIZE; i++)
    {
        printf("the celsius temperature for the last 3 days is\n");
        scanf("%f",&*(celsius + i));
        flushall();
    }
    
    // convert celsius to fahr of the last 3 days
    
    for (i = 0; i<SIZE; i++)
    {
        *(fahr  + i) = *(celsius+i) * 9/5 +32;
    }
    
    // display all the fahr temp of the last 3 days and display the address where they are 
    
    for (i = 0; i<SIZE; i++)
    {
        printf(" the address  %p containes fahr[%d] and is %.2f\n",(fahr + i),i,*(fahr + i));
    }
    
    for (i = 0; i<SIZE; i++)
    {
        *(fahr+i) = 0;
    }
    
    //give data to fahr array of the last 3 days 
    
    for (i = 0; i<SIZE; i++)
    {
        printf("the fahr temperature for the last 3 days is\n");
        scanf("%f",&*(fahr + i));
        flushall();
    }
    
    //convert fahr to celsius
    
    for (i = 0; i<SIZE; i++)
    {
        *(celsius +i) = ((*(fahr + i) -32) * 5/9);
    }
    
    // display all the celsius temp of the last 3 days and display the addresses where the data is
    
    for (i = 0; i<SIZE; i++)
    {
        printf(" the address  %p containes celsius[%d] and is %.2f\n",(celsius + i),i,*(celsius + i));
    }
    
    getchar();
    return 0;
}//end main
    