/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  User Define Macros
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  Maximum file size that we allow in the project
#define MAXFILESIZE 50

#define MAXOPENFILES 20

#define MAXINODE 5

#define READ 1  
#define WRITE 2
#define EXECUTE 4

#define START 0 //lseek
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined Structures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    Boot Block
//  Description :       Holds the information to boot the OS
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    Super Block
//  Description :       Holds the information about the File System
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    Inode
//  Description :       Holds the information about the File 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next ;
};

typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    FileTable
//  Description :       Holds the information about Opened File
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef FileTable FILETABLE;
typedef FileTable * PFILETABLE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    UAREA
//  Description :       Holds the information about the Process
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Global Variables or Objects used in the Project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uareaobj;

PINODE head = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InitializeUAREA
//  Description :       It is used to Initialize UAREA Members
//  Author :            Sakshi Shilisiddha Chakre
//  Date :              13/01/26
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitializeUAREA()
{
    strcpy(uareaobj.ProcessName,"Myexe");

    int i = 0 ;

    for(i = 0 ; i < MAXOPENFILES ; i++)
    {
        uareaobj.UFDT[i] = NULL ;
    }

    printf("Marvellous CVFS : UAREA gets initialized successfully.\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InitializeSuperBlock
//  Description :       It is used to Initialize Super Block Members
//  Author :            Sakshi Shilisiddha Chakre
//  Date :              13/01/26
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitializeSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("CVFS : SuperBlock gets initialized successfully.\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     CreateDILB
//  Description :       It is used to create Linked List of inodes
//  Author :            Sakshi Shilisiddha Chakre
//  Date :              13/01/26
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1 ;
    PINODE newn = NULL ;
    PINODE temp = head ;

    for(i = 1 ; i <= MAXINODE ; i++)
    {
        newn = (PINODE)malloc(sizeof(INODE)) ;

        strcpy(newn->FileName,"\0");
        newn -> InodeNumber = i ;
        newn -> FileSize = 0 ;
        newn -> ReferenceCount = 0 ;
        newn -> Permission = 0 ;
        newn -> Buffer = NULL;
        newn -> next = NULL;

        if(temp == NULL)    // LL is empty
        {
            head = newn ;
        }
        else                // LL contains atleast 1 node
        {
            temp->next = newn;
            temp = temp->next;
        }

        printf("CVFS : DILB created successfully.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     StartAuxillaryDataInitialization
//  Description :       It is used to call all Functions which are used to Initialize Auxillary Data
//  Author :            Sakshi Shilisiddha Chakre
//  Date :              13/01/26
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitialization()
{
    strcpy(bootobj.Information,"Booting process of CVFS is done.\n");

    printf("%s\n",bootobj.Information);

    InitializeSuperBlock();

    CreateDILB();

    InitializeUAREA();

    printf("CVFS : auxillary data initialized successfully.\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DisplayHelp
//  Description :       It is used to display help page
//  Author :            Sakshi Shilisiddha Chakre
//  Date :              14/01/26
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayHelp()
{
    printf("------------------------------------------------------\n");
    printf("------------------CVFS Help Page----------------------\n");
    printf("------------------------------------------------------\n"); 

    printf("man   : It is used to display manual page\n");
    printf("clear : It is used to clear the terminal\n");
    printf("creat : It is used to create new file\n");
    printf("write : It is used to write the data into the file\n");
    printf("read  : It is used to read the data from the file\n");
    printf("stat  : It is used to display statistical information\n");
    printf("unlink: It is used to delete the file\n");
    printf("exit  : It is used to terminate CVFS\n");

    printf("------------------------------------------------------\n"); 

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     ManPage Display
//  Description :       It is used to display help page
//  Author :            Sakshi Shilisiddha Chakre
//  Date :              14/01/26
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ManPageDisplay(char Name[])
{
    if(strcmp("ls",Name)==0)
    {
        printf("About : It is used to display the name of all files\n");
        printf("Usage : ls\n");
    }
    else if(strcmp("man",Name)==0)
    {
        printf("About : It is used to display manual page\n");
        printf("Usage : man command_name\n");
        printf("Command_name: It is the name of the command\n");
    }
    else if(strcmp("exit",Name) == 0)
    {
        printf("About : It is used to terminate the shell\n");
        printf("Usage : exit\n");
    }
    else
    {
        printf("No manual entry for %s\n",Name);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function of the Project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char str[80] = {'\0'};
    char Command[5][20] = {{'\0'}};
    int iCount = 0 ;

    StartAuxillaryDataInitialization();

    printf("------------------------------------------------------\n");
    printf("--------------CVFS started successfully---------------\n");
    printf("------------------------------------------------------\n");

    // Infinite Listening Shell
    while(1)
    {
       fflush(stdin); 

       strcpy(str,"");

       printf("\n CVFS : > ");
       fgets(str,sizeof(str),stdin);

       iCount = sscanf(str,"%s %s %s %s %s",Command[0],Command[1],Command[2],Command[3],Command[4] );

       printf("%d\n",iCount);

       fflush(stdin); 

       if(iCount == 1)
       {
            if(strcmp("exit",Command[0]) == 0)
            {
                printf("Thank you for using CVFS\n");
                printf("Deallocating all the allocated resources\n");

                break;
            }
            else if (strcmp("ls",Command[0]) == 0)
            {
                printf("Inside ls\n");
            }
            else if (strcmp("help",Command[0]) == 0)
            {
                DisplayHelp();
            }
       }// End of else if 1
       else if(iCount == 2)
       {
            if(strcmp("man",Command[0])==0)
            {
                ManPageDisplay(Command[1]);
            }
       }// End of else if 2
       else if(iCount == 3)
       {

       }// End of else if 3
       else if(iCount == 4)
       {

       }// End of else if 4
       else 
       {
            printf("Command not found\n");
            printf("Please refer help option to get more information\n");
       } // End of else
    } // End of while
    
    return 0;
}// End of main