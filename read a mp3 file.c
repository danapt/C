/*program with persisten data assigment
read a mp3 file and display the information from the tag
daniel apetri
borland
win10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

typedef struct file
{
    char title[SIZE];
    char author[SIZE];
    char album[SIZE];
    char year[5];
    char comment[SIZE];
    char genre;
    
} mp3;

//prototype
int tag(FILE *,mp3 *id3);
void display(mp3 *id3);
void find_genre(FILE *, mp3 *id3);
    


int main ()
{
    FILE *fp;
    //initialize the structure with the null character
    mp3 ID3={"\0"
            };
            
    char file[15];
    int check;
    
    printf("enter the file you want to read: ");
    gets(file);
    flushall();
    
    //open file
    fp = fopen(file, "rb");
    
     //check if the file was open
    if (fp == NULL)
    {
        printf("file could not be opend\n");
    }
    
    //functin to check if the tag was found
    check = tag(fp,&ID3);
    
    if(check == 0)
    {
        printf("error\n");
    }
    else
    {
        //display the data from the file
        display(&ID3);
    }
    
    //function to find the genre of the file based on the last byte read from the file
    find_genre(fp,&ID3);
    
    flushall();
    getchar();
    return 0;
    
}//end main

//function to find the tag in the mp3 file
int tag(FILE *pointer, mp3 *id3)
{
    char t[4]= "\0";
    
    rewind(pointer);
    
    //go back from the end of the file with 128 bytes and read the data in the string t
    fseek(pointer,-128,SEEK_END);
    fread(t,sizeof(char), 3,pointer);
    
    //check if the tag was found
    if (strcmp("TAG", t) != 0)
    {
        printf("the tag was not found\n");
        return 0;
    }
    
    //use fread to read all the data from the mp3 file and store it in the struct mp3
    fread(id3->title, sizeof(char), 30, pointer);
    fread(id3->author, sizeof(char), 30, pointer);
    fread(id3->album, sizeof(char), 30, pointer);
    fread(id3->year, sizeof(char), 4, pointer);
    fread(id3->comment, sizeof(char), 30, pointer);
    fread(&id3->genre, sizeof(char), 1, pointer);
    
    return 1;
}//end tag()

//function to display the informtion from the mp3 file
void display(mp3 *id3)
{
    printf("title is:    %s\n",id3->title);
    printf("author is:   %s\n",id3->author);
    printf("album is:    %s\n",id3->album);
    printf("year is:     %s\n",id3->year);
    printf("comment is   %s\n",id3->comment);
    
}//end display

//function to find the genre of the file
void find_genre(FILE *pointer, mp3 *id3)
{
    //create a string and if the read byte from the last byte in teh file is a aschii character then replace the coressponding data in the string
    char gen[SIZE];
    
    switch(id3->genre)
    {
        case 0:
        {
            strcpy(gen,"Blues");
            break;
        }
        case 1:
        {
            strcpy(gen,"Classic Rock");
            break;
        }
        case 2:
        {
            strcpy(gen,"Country");
            break;
        }
        case 3:
        {
            strcpy(gen,"Dance");
            break;
        }
        case 4:
        {
            strcpy(gen,"Disco");
            break;
        }
        case 5:
        {
            strcpy(gen,"Funk");
            break;
        }
        case 6:
        {
            strcpy(gen,"Grunge");
            break;
        }
        case 7:
        {
            strcpy(gen,"Hip-Hop");
            break;
        }
        case 8:
        {
            strcpy(gen,"Jazz");
            break;
        }
        case 9:
        {
            strcpy(gen,"Metal");
            break;
        }
        case 10:
        {
            strcpy(gen,"New Age");
            break;
        }
        case 11:
        {
            strcpy(gen,"Oldies");
            break;
        }
        case 12:
        {
            strcpy(gen,"Other");
            break;
        }
        case 13:
        {
            strcpy(gen,"Pop");
            break;
        }
        case 14:
        {
            strcpy(gen,"R&B");
            break;
        }
        case 15:
        {
            strcpy(gen,"Rap");
            break;
        }
        case 16:
        {
            strcpy(gen,"Reggae");
            break;
        }
        case 17:
        {
            strcpy(gen,"Rock");
            break;
        }
        
        case 18:
        {
            strcpy(gen,"Techno");
            break;
        }
        case 19:
        {
            strcpy(gen,"Industrial");
            break;
        }
        case 20:
        {
            strcpy(gen,"Alternative");
            break;
        }
        case 21:
        {
            strcpy(gen,"Ska");
            break;
        }
        case 22:
        {
            strcpy(gen,"Death Metal");
            break;
        }
        case 23:
        {
            strcpy(gen,"Pranks");
            break;
        }
        case 24:
        {
            strcpy(gen,"Soundtrack");
            break;
        }
        case 25:
        {
            strcpy(gen,"Euro-Techno");
            break;
        }
        case 26:
        {
            strcpy(gen,"Ambient");
            break;
        }
        case 27:
                {
            strcpy(gen,"Trip-Hop");
            break;
        }
        case 28:
        {
            strcpy(gen,"Vocal");
            break;
        }
        case 29:
        {
            strcpy(gen,"Jazz+Funk");
            break;
        }
        case 30:
        {
            strcpy(gen,"Fusion");
            break;
        }
        case 31:
        {
            strcpy(gen,"Trance");
            break;
        }
        case 32:
        {
            strcpy(gen,"Classical");
            break;
        }
        case 33:
        {
            strcpy(gen,"Instrumental");
            break;
        }
        case 34:
        {
            strcpy(gen,"Acid");
            break;
        }
        case 35:
        {
            strcpy(gen,"House");
            break;
        }
        case 36:
        {
            strcpy(gen,"Game");
            break;
        }
        case 37:
        {
            strcpy(gen,"Sound Clip");
            break;
        }
        case 38:
        {
            strcpy(gen,"Gospel");
            break;
        }
        case 39:
        {
            strcpy(gen,"Noise");
            break;
        }
        case 40:
        {
            strcpy(gen,"AlternRock");
            break;
        }
        case 41:
        {
        strcpy(gen,"Bass");
        break;
        }
        case 42:
        {
            strcpy(gen,"Soul");
            break;
        }
        case 43:
        {
            strcpy(gen,"Punk");
            break;
        }
        case 44:
        {
            strcpy(gen,"Space");
            break;
        }
        case 45:
        {
            strcpy(gen,"Meditative");
            break;
        }
        case 46:
        {
            strcpy(gen,"Instrumental Pop");
            break;
        }
        case 47:
        {
            strcpy(gen,"Instrumental Rock");
            break;
        }
        case 48:
        {
            strcpy(gen,"Ethnic");
            break;
        }
        case 49:
        {
            strcpy(gen,"Gothic");
            break;
        }
        case 50:
        {
            strcpy(gen,"Darkwave");
            break;
        }
        case 51:
        {
            strcpy(gen,"Techno-Industrial");
            break;
        }
        case 52:
        {
            strcpy(gen,"Electronic");
            break;
        }
        case 53:
        {
            strcpy(gen,"Pop-Folk");
            break;
        }
        case 54:
        {
            strcpy(gen,"Eurodance");
            break;
        }
        case 55:
        {
            strcpy(gen,"Dream");
            break;
        }
        case 56:
        {
            strcpy(gen,"Southern Rock");
            break;
        }
        case 57:
        {
            strcpy(gen,"Comedy");
            break;
        }
        case 58:
        {
            strcpy(gen,"Cult");
            break;
        }
        case 59:
        {
            strcpy(gen,"Gangsta");
            break;
        }
        case 60:
        {
            strcpy(gen,"Top 40");
            break;
        }
        case 61:
        {
            strcpy(gen,"Christian Rap");
            break;
        }
        case 62:
        {
            strcpy(gen,"Pop/Funk");
            break;
        }
        case 63:
        {
            strcpy(gen,"Jungle ");
            break;
        }
        case 64:
        {
            strcpy(gen,"Native American");
            break;
        }
        case 65:
        {
            strcpy(gen,"Cabaret");
            break;
        }
        case 66:
        {
            strcpy(gen,"New Wave");
            break;
        }
        case 67:
        {
            strcpy(gen,"Psychadelic");
            break;
        }
        case 68:
        {
            strcpy(gen,"Rave");
            break;
        }
        case 69:
        {
            strcpy(gen,"Showtunes");
            break;
        }
        case 70:
        {
            strcpy(gen,"Trailer");
            break;
        }
        case 71:
        {
            strcpy(gen,"Lo-Fi");
            break;
        }
        case 72:
        {
            strcpy(gen,"Tribal");
            break;
        }
        case 73:
        {
            strcpy(gen,"Acid Punk");
            break;
        }
        case 74:
        {
            strcpy(gen,"Acid Jazz");
            break;
        }
        case 75:
        {
            strcpy(gen,"Polka");
            break;
        }
        case 76:
        {
            strcpy(gen,"Retro");
            break;
        }
        case 77:
        {
            strcpy(gen,"Musical");
            break;
        }
        case 78:
        {
            strcpy(gen,"Rock & Roll");
            break;
        }
        case 79:
        {
            strcpy(gen,"Hard Rock");
            break;
        }
        default:
        {
            strcpy(gen,"unknown");
            break;
        }   
        
    }//end switch

    printf("Genre: %s\n", gen);
}//end find gender();
