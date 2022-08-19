/*VOTING MACHINE CODE, MADE BY: Aditya Rane, Arzoo Lakhani, Hanupriya Deora*/
#include<stdio.h>
#include<stdlib.h>  
//For circular linked list:
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head; 
    
void insertvote();  

void search();

//candidates:
#define CANDIDATE_COUNT

#define CANDIDATE1 "Aditya Rane"
#define CANDIDATE2 "Arzoo Lakhani"
#define CANDIDATE3 "Hanupriya Deora"
#define CANDIDATE4 "Balajee Srinivasan"

int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;


int admin()
{
int choice;

void votesCount()
{
printf("\n\n ##### Voting Statistics ####");
printf("\n %s - %d ", CANDIDATE1, votesCount1);
printf("\n %s - %d ", CANDIDATE2, votesCount2);
printf("\n %s - %d ", CANDIDATE3, votesCount3);
printf("\n %s - %d ", CANDIDATE4, votesCount4);
printf("\n %s - %d ", "Spoiled Votes", spoiledtvotes); 
}
void getLeadingCandidate()
{
    printf("\n\n  #### Leading Candiate ####\n\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    printf("[%s]",CANDIDATE1);
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    printf("[%s]",CANDIDATE2);
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    printf("[%s]",CANDIDATE3);
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    printf("[%s]",CANDIDATE4);
    else
    printf("----- Warning !!! No-win situation----");    
}





do
{
printf("\n\n 1. Find Vote Count");
printf("\n 2. Find leading Candidate");
printf("\n 3. EXIT");
printf("\n\n Please enter your choice : ");
scanf("%d", &choice);

switch(choice)
{

case 1: votesCount();
        break;
case 2: getLeadingCandidate();
        break;
case 3: return 0;
        break;

default: printf("\n Error: Invalid Choice");
}
}
while(choice!=0);
}
    

    void insertvote(int a)  
{  
    struct node *ptr,*temp;   
    int PRN=a;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
       
        ptr->data = PRN;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        printf("\n PRN inserted\n");
        int choice;

        

       printf("\n\n ### Please choose your Candidate for Student Council ####\n\n");
       printf("\n 1. %s", CANDIDATE1);
       printf("\n 2. %s", CANDIDATE2);
       printf("\n 3. %s", CANDIDATE3);
       printf("\n 4. %s", CANDIDATE4);
       printf("\n 5. %s", "None of These");

       printf("\n\n Input your choice (1 - 5) : ");
       scanf("%d",&choice);

      switch(choice)
      {
          case 1: votesCount1++; break;
          case 2: votesCount2++; break;
          case 3: votesCount3++; break;
          case 4: votesCount4++; break;
          case 5: spoiledtvotes++; break;
          default: printf("\n Error: Wrong Choice !! Please retry");
                //hold the screen
                getchar();
      }
        printf("\n thanks for vote !!");

          
    }  
  
}  
  void search()  
{  
    struct node *ptr;  
    int PRN,i=0,flag=1;  
    ptr = head;
     printf("\nEnter Your PRN?\n");   
     scanf("%d",&PRN);     
    if(ptr == NULL)  
    {  
        printf("Congratulations you're the first to vote");
        insertvote(PRN);

    }  
    else  
    {     
        if(head ->data == PRN)  
        {  
        printf("PRN found at location %d, you have already voted",i+1);  
        flag=0;  
        }  
        else   
        {  
        while (ptr->next != head)  
        {  
            if(ptr->data == PRN)  
            {  
                printf("PRN found at location %d ,you have already voted",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        }  
        if(flag != 0)  
        {  
            printf("You are eligible to vote\n");
            insertvote(PRN);

        }  
    }     
          
}
void student()
{
    search();
}


int main()
{
int i;
int choice;

do{
printf("\n\n ###### Welcome to Election/Voting 2022 #####");
printf("\n\n 1. Student Login");
printf("\n 2. Admin Login");
printf("\n 3. Exit");


printf("\n\n Please enter your choice : ");
scanf("%d", &choice);

switch(choice)
{
case 1: student();break;
case 2: admin();break;
case 3: return 0; break;
default: printf("\n Error: Invalid Choice");
}
}while(choice!=0);

//hold the screen
getchar();
return 0;
}