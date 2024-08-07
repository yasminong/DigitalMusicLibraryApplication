/*
    SECTION 05&01-DIGITAL MUSIC LIBRARY APPLICATION
    1.NOR ALIA YASMIN WONG ( CB20126 )
    2.AINI NADHAH ( CC19308)
    3.MUHAMMAD YAZID ( CC19325 )
    4.NURUL AFIFAH (CD20008)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0


void insert();//add song
void display();//display song details
void search(); //search song
void sort();//sort song
void update();//update song
void delete_song();//delete song

struct user
{
    char name[20];
    char password[10];
};

struct Date
{
    int dd;
    int mm;
    int yy;
};

struct album
{
    char title[100];
    int year;
};

struct songLibrary
{
    char name[100] ;
    char artist [100];
    char producer [100];
    char country [40];
    char genre [40];
    float duration;
    int ranking ;
    int rating ;
    struct Date da;
    struct user User;
    struct album Album;
    struct songLibrary *nextptr;
};
struct songLibrary *front , *currentptr , *previousptr , *temp ,*newptr ,*rear;

int main ()
{
    start:
    newptr=(struct songLibrary*)(malloc(sizeof(struct songLibrary)));

    printf("\n\t\t ------------------------------------------------------------- \n");
    printf("\t\t                      LOGIN MUSIC LIBRARY APPLICATION        ");
    printf("\n\t\t ------------------------------------------------------------- \n");

    fflush(stdin);
    printf("\t\t\t\t\tUsername:");
    gets(newptr->User.name);
    printf("\t\t\t\t\tPassword:");
    scanf("%s",&newptr->User.password);
    printf("\n\t\t ------------------------------------------------------------- \n");

    if(strcmp(newptr->User.password, "123")==0)
    {
         system("cls");
    }
    else
    {
        printf("\n\t\t\t\tWRONG PASSWORD!! PLEASE TRY AGAIN\n\n");
        goto start;
    }
    char ch;                                                                                                                                                                                                       ;
    int choice=TRUE;


    front= (struct songLibrary*)NULL;

        printf("\n\t\t =========================================================================\n");
        printf("\t\t   |                      PERSONAL MUSIC LIBRARY                        |");
        printf("\n\t\t =========================================================================\n");

    do
    {
        printf("\n\n\t\t     MENU ");
        printf("\n\t\t       I. INSERT A NEW SONG");
        printf("\n\t\t       P. PRINT ENTIRE MUSIC LIBRARY");
        printf("\n\t\t       S. SEARCH A SONG IN LIBRARY");
        printf("\n\t\t       O. SORT THE SONG LIST IN LIBRARY");
        printf("\n\t\t       U. UPDATE SONG IN LIBRARY");
        printf("\n\t\t       D. DELETE SONG IN LIBRARY");
        printf("\n\t\t       E. EXIT");
        printf("\n\t\t =========================================================================\n");
        printf("\n\t\t       Enter Choice : ");
        fflush(stdin);
        scanf("%s" ,&ch);
        ch=toupper(ch);

        switch(ch)
        {
            case 'I' :insert();
            break;
            case 'P' :display();
            break;
            case 'S' :search();
            break;
            case 'O' :sort();
            break;
            case 'U' :update();
            break;
            case 'D' :delete_song();
            break;
            case 'E' :choice=FALSE;
            break;

            default: printf("\nRE-ENTER VALID CHOICE.");
        }

    }
    while(choice==FALSE);
    return 0;
}

void insert()//enqueue
{
    //Create a new node using malloc function
    //pointer to a new memory allocation
    newptr = (struct songLibrary*)malloc(sizeof(struct songLibrary));//pointer to a new memory allocation

    //check the condition of front
    if(front ==NULL)//node is empty?

    {
        //insertion to an empty queue

        front = newptr; //first pointer point to first node

        rear=newptr;

        newptr->nextptr =NULL;//first and last node pointer to null

    }

    else

    {
        //insertion to a non-empty queue
        rear->nextptr = newptr;

        rear=newptr ;//rear point to new node

        rear ->nextptr =NULL;


    }

     printf("\n\t\t =========================================================================\n");
     printf("\t\t                      MUSIC LIBRARY DETAILS      \n");


     fflush(stdin);
     printf("\n\t\t         Song Title                : ");
     gets(newptr->name);
     fflush(stdin);

     printf("\n\t\t         Artist Name               : ");
     gets(newptr->artist);
     fflush(stdin);

     printf("\n\t\t         Produced by               : ");
     gets(newptr->producer);
     fflush(stdin);

     printf("\n\t\t         Country                   : ");
     gets(newptr->country);
     fflush(stdin);

     printf("\n\t\t         Song Genre                : ");
     gets(newptr->genre);
     fflush(stdin);

     printf("\n\t\t         Song Duration [Minutes]   : ");
     scanf("%f",&newptr->duration);
     fflush(stdin);

     printf("\n\t\t         Song Ranking [1-100]      : ");
     scanf("%d",&newptr->ranking);
     fflush(stdin);

     printf("\n\t\t         Song Rating [1-5]         : ");
     scanf("%d",&newptr->rating);
     fflush(stdin);

     printf("\n\t\t         Album Name                : ");
     gets(newptr->Album.title);
     fflush(stdin);

     printf("\n\t\t         Year Released              : ");
     scanf("%d",&newptr->Album.year);
     fflush(stdin);

     printf("\n\t\t         Enter added date (dd/mm/yyyy)     : ");
     scanf("%d / %d / %d",&newptr->da.dd, &newptr->da.mm, &newptr->da.yy);

     printf("\n\t\t    =========================================================================\n");

}//add new song
void display()
{
         printf("\n\t\t    =========================================================================\n");
         printf("\t\t\t\t\t          MUSIC LIBRARY DETAILS       \n\n");
         printf("\n\t\t    =========================================================================\n");

         if (front==(struct songLibrary*)NULL)//empty list
         {
            printf("\n\t\t  Music Library is empty     ");
            return;
        }
        else
        {
        currentptr=front;
        while(currentptr !=(struct songLibrary *)NULL)
        {
            printf("\n\t\t       SONG TITLE           : %s" ,currentptr->name);
            printf("\n\t\t       ARTIST NAME          : %s" ,currentptr->artist);
            printf("\n\t\t       PRODUCED BY          : %s" ,currentptr->producer);
            printf("\n\t\t       COUNTRY              : %s" ,currentptr->country);
            printf("\n\t\t       GENRE                : %s" ,currentptr->genre);
            printf("\n\t\t       DURATION [Minutes]   : %.2f" ,currentptr->duration);
            printf("\n\t\t       SONG RANKING [1-100] : %d" ,currentptr->ranking);
            printf("\n\t\t       SONG RATING  [1-5]   : %d" ,currentptr->rating);
            printf("\n\t\t       ALBUM NAME           : %s" ,currentptr->Album.title);
            printf("\n\t\t       YEAR RELEASED        : %d" ,currentptr->Album.year);
            printf("\n\t\t       DATE ADDED           : %d/%d/%d",currentptr->da.dd, currentptr->da.mm, currentptr->da.yy);
            printf("\n\t\t    =====================================================================\n");

            currentptr=currentptr->nextptr;
        }

    }

}//display list of song
void search()
{
    int category;
    char name [100];
    char artist[100];
    char producer [100];
    char country[40];
    char genre[40];
    float duration;
    char album [40];
    char playlist[40];
    int ranking;
    int rating;
    int i=1;

    printf("\n\t\t    =========================================================================\n");
    printf("\n\n\t\t       SEARCH BY CATEGORY");
    printf("\n\t\t       1. SONG TITLE");
    printf("\n\t\t       2. ARTIST NAME  ");
    printf("\n\t\t       3. EXIT");
    printf("\n\t\t    =========================================================================\n");
    printf("\n\n\t\t      Enter Category [1, 2, 3]: ");
    scanf("%d", &category);

    switch(category)
    {

        case 1:
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIBRARY LIST IS EMPTY!!!\n");

        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title : ");
             gets(name);
             fflush(stdin);


             currentptr=front;
            while(strcmp(currentptr->name,name)!=0)
             {
                 if(strcmp(currentptr->name,name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }

             }

              if (currentptr!=(struct songLibrary *)NULL)
              {

                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.\n");
                      printf("\n\t\t       Song Title           : %s", currentptr->name);
                      printf("\n\t\t       Artist Name          : %s", currentptr->artist);
                      printf("\n\t\t       Produced by          : %s", currentptr->producer);
                      printf("\n\t\t       Country              : %s", currentptr->country);
                      printf("\n\t\t       Genre                : %s", currentptr->genre);
                      printf("\n\t\t       Duration [Minutes]   : %.2f", currentptr->duration);
                      printf("\n\t\t       Song Ranking [1-100] : %d", currentptr->ranking);
                      printf("\n\t\t       Song Rating [1-5]    : %d", currentptr->rating);
                      printf("\n\t\t       Album Name           : %s" ,currentptr->Album.title);
                      printf("\n\t\t       Year Released        : %d", currentptr->Album.year);
                      printf("\n\t\t       Date Added           : %d/%d/%d",currentptr->da.dd, currentptr->da.mm, currentptr->da.yy);
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE ARTIST NAME IS NOT FOUND");
              }
         }
        break;

        case 2:
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIST IS EMPTY!!!\n");

        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter name of artist: ");
             gets(artist);
             fflush(stdin);

             currentptr=front;
            while(strcmp(currentptr->artist,artist)!=0)
             {
                 if(strcmp(currentptr->artist,artist)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }

             }

              if (currentptr!=(struct songLibrary *)NULL)
              {
                  while (currentptr != NULL)
                  {
                            if (! previousptr || currentptr->artist != previousptr->artist)
                        {
                            printf("\n\t\t       Artist name %s", currentptr->artist);
                            printf(" is exist in library.");
                            printf("\n\t\t       Song Title           : %s", currentptr->name);
                            printf("\n\t\t       Artist Name          : %s", currentptr->artist);
                            printf("\n\t\t       Produced by          : %s", currentptr->producer);
                            printf("\n\t\t       Country              : %s", currentptr->country);
                            printf("\n\t\t       Genre                : %s", currentptr->genre);
                            printf("\n\t\t       Duration [Minutes]   : %.2f", currentptr->duration);
                            printf("\n\t\t       Song Ranking [1-100] : %d", currentptr->ranking);
                            printf("\n\t\t       Song Rating [1-5]    : %d", currentptr->rating);
                            printf("\n\t\t       Album Name           : %s" ,currentptr->Album.title);
                            printf("\n\t\t       Year Released        : %d", currentptr->Album.year);
                            printf("\n\t\t       Date Added           : %d/%d/%d",currentptr->da.dd, currentptr->da.mm, currentptr->da.yy);
                            return;
                        }

                  }


              }
              else
              {
                 printf("\n\n\t\t       THE ARTIST NAME IS NOT FOUND");
              }
         }

        break;

        case 3: exit(0);

        default: printf("\n\t\t       RE-ENTER THE CATEGORY!!");
    }
}//search song by category
void sort()
{

    struct songLibrary* temp=front;
    printf("\t\tStart sorting....");
    while(temp!=NULL)
    {
        struct songLibrary* min = temp;
        struct songLibrary* r=temp->nextptr;

    int category;
    printf("\n\t\t    =========================================================================\n");
    printf("\n\n\t\t   SORT BY CATEGORY");
    printf("\n\t\t       1. SORT BY SONG RANKING");
    printf("\n\t\t       2. SORT BY RATING");
    printf("\n\t\t       3. SORT BY YEAR");
    printf("\n\t\t       4. EXIT");
    printf("\n\t\t    =========================================================================\n");
    printf("\n\t\t       Enter category [1,2,3,4]: ");
    scanf("%d", &category);

    switch(category)
    {
        case 1:
        //sorting song ranking
        while(r!=NULL)
        {
            if(min->ranking > r->ranking)
            {
                min=r;
            }
            r=r->nextptr;
        }
        break;

        case 2:
        //sorting song rating
        while(r!=NULL)
        {
            if(min->rating > r->rating)
            {
                min=r;
            }
            r=r->nextptr;
        }
        break;

        case 3:
        //sorting song year
        while(r!=NULL)
        {
            if(min->Album.year > r->Album.year)
            {
                min=r;
            }
            r=r->nextptr;
        }
        break;

        case 4: exit(0);

        default: printf("\n\t\t       RE-ENTER THE CATEGORY!!");
    }


        //swap name
        char newName[100];
        strcpy(newName,temp->name);
        strcpy(temp->name,min->name);
        strcpy(min->name,newName);
        //swap artist
        char newArtist[100];
        strcpy(newArtist,temp->artist);
        strcpy(temp->artist,min->artist);
        strcpy(min->artist,newArtist);
         //swap producer
        char newProducer[100];
        strcpy(newProducer,temp->producer);
        strcpy(temp->producer,min->producer);
        strcpy(min->producer,newProducer);
        //swap country
        char newCountry[40];
        strcpy(newCountry,temp->country);
        strcpy(temp->country,min->country);
        strcpy(min->country,newCountry);
        //swap genre
        char newGenre[40];
        strcpy(newGenre,temp->genre);
        strcpy(temp->genre,min->genre);
        strcpy(min->genre,newGenre);
        //swap duration
        float newDuration = temp->duration;
        temp->duration = min->duration;
        min->duration= newDuration;
        //swap album
        char newAlbum[100];
        strcpy(newAlbum,temp->Album.title);
        strcpy(temp->Album.title,min->Album.title);
        strcpy(min->Album.title,newAlbum);
        //swap ranking
        int newRanking = temp->ranking;
        temp->ranking = min->ranking;
        min->ranking= newRanking;
        //swap rating
        int newRating = temp->rating;
        temp->rating = min->rating;
        min->rating = newRating;
        //swap year
        int newYear = temp->Album.year;
        temp->Album.year = min->Album.year;
        min->Album.year = newYear;
        temp = temp->nextptr;

    }
    display();//calling function

}//sort based on category
void update()
{
    int category;
    char name[100];
    char artist[100];
    char album [40];

    printf("\n\t\t    =========================================================================\n");
    printf("\n\n\t\t     UPDATE BY CATEGORY ");
    printf("\n\t\t       1. UPDATE ALL SONG DETAILS");
    printf("\n\t\t       2. SONG TITLE");
    printf("\n\t\t       3. ARTIST OF THE SONG");
    printf("\n\t\t       4. PRODUCER OF THE SONG");
    printf("\n\t\t       5. COUNTRY OF THE SONG");
    printf("\n\t\t       6. ALBUM OF THE SONG");
    printf("\n\t\t       7. RANKING OF THE SONG");
    printf("\n\t\t       8. RATING OF THE SONG");
    printf("\n\t\t       9. ADDED DATE");
    printf("\n\t\t       10. EXIT");
    printf("\n\t\t    =========================================================================\n");
    printf("\n\t\t       Enter Category [1,2,3,4,5,6,7,8,9,10]: ");
    scanf("%d", &category);

    switch(category)
    {
        case 1://update all details
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIBRARY LIST IS EMPTY!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary *)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t         New Song Title: ");
                      scanf(" %[^\n]s", &currentptr->name);
                      printf("\t\t       New Artist Name: ");
                      scanf(" %[^\n]s", &currentptr->artist);
                      printf("\t\t       New Producer Name: ");
                      scanf(" %[^\n]s", &currentptr->producer);
                      printf("\t\t       New Country: ");
                      scanf(" %[^\n]s", &currentptr->country);
                      printf("\t\t       New Genre: ");
                      scanf(" %[^\n]s", &currentptr->genre);
                      printf("\t\t       New Duration [Minutes] : ");
                      scanf("%f", &currentptr->duration);
                      printf("\t\t       New Song Ranking [1-100]: ");
                      scanf("%d", &currentptr->ranking);
                      printf("\t\t       New Song Rating [1-5]: ");
                      scanf("%d", &currentptr->rating);
                      printf("\t\t       New album name: ");
                      scanf(" %[^\n]s", &currentptr->Album.title);
                      printf("\t\t       New Year Released: ");
                      scanf("%d", &currentptr->Album.year);
                      printf("\t\t       New Added Date (dd/mm/yyyy): ");
                      scanf("%d / %d / %d",&currentptr->da.dd, &currentptr->da.mm, &currentptr->da.yy);

                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG TITLE IS NOT FOUND");
              }
         }

        break;

        case 2://update song title
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIBRARY LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
             if (currentptr!=(struct songLibrary *)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title  : %s", currentptr->name);
                      printf("\n\t\t       New Song Title: ");
                      gets(currentptr->name);
                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG TITLE IS NOT FOUND");
              }
         }




        break;

        case 3://update song artist
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary *)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title : %s", currentptr->name);
                      printf("\n\t\t       New Artist Name :");
                      gets(currentptr->artist);
                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG TITLE IS NOT FOUND");
              }
         }
        break;

        case 4://update song artist
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary *)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title : %s", currentptr->name);
                      printf("\n\t\t       New Producer Name :");
                      gets(currentptr->producer);
                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG TITLE IS NOT FOUND");
              }
         }
        break;

        case 5://update song country
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary *)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title : %s", currentptr->name);
                      printf("\n\t\t       New Song Country :");
                      gets(currentptr->country);
                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG TITLE IS NOT FOUND");
              }
         }
        break;

        case 6://update album name
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIBRARY LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary*)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title  : %s", currentptr->name);
                      printf("\n\t\t       New Album Title :");
                      gets(currentptr->Album.title);
                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG IS NOT FOUND");
              }
         }
        break;

        case 7://update song ranking
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIBRARY LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary*)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title  : %s", currentptr->name);
                      printf("\n\t\t       New song ranking :");
                      scanf("%d", &currentptr->ranking);
                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG IS NOT FOUND");
              }
         }
        break;

        case 8://update song rating
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIBRARY LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary*)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title  : %s", currentptr->name);
                      printf("\n\t\t       New song rating :");
                      scanf("%d", &currentptr->rating);
                      display();
                      return;
              }
              else
              {
                 printf("\n\n\t\t       THE SONG IS NOT FOUND");
              }
         }
        break;

        case 9://update date added
        if(front==(struct songLibrary*)NULL)
        {
            printf("\n\n\t\t       THE MUSIC LIBRARY LIST IS EMPTY!!!\n");
        }
        else
         {
             fflush(stdin);
             printf("\n\t\t       Enter song title: ");
             gets(name);
             fflush(stdin);

             currentptr=front;
             while (strcmp(currentptr->name, name)!=0)
             {
                 if(strcmp(currentptr->name , name)!=0)
                 {
                     currentptr=currentptr->nextptr;
                 }
             }
              if (currentptr!=(struct songLibrary*)NULL)
              {
                      printf("\n\t\t       Song Title %s", currentptr->name);
                      printf(" is exist in library.");
                      printf("\n\t\t       Song Title  : %s", currentptr->name);
                      printf("\n\t\t  New added date (dd/mm/yyyy)  :");
                      scanf("%d / %d / %d",&currentptr->da.dd, &currentptr->da.mm, &currentptr->da.yy);
                      display();
                      return;

              }
              else
              {
                 printf("\n\n\t\t       THE SONG IS NOT FOUND");
              }
         }
        break;

        case 10: exit(0);

        default: printf("\n\t\t       RE-ENTER THE CATEGORY!!");
    }
}//update details
void delete_song()//dequeue
{
     //name that want to delete
    char name [100];

     fflush(stdin);
     printf("\n\t\t      Enter Song Title to delete : ");
     gets(name);
     fflush(stdin);

    if(front ==(struct songLibrary *) NULL)//node is empty?
    {
        printf("No Song Title Exist to Delete\n");
    }

    else if(front == rear)
    {
        if (strcmp((front)->name, name)==0)
        {
            free(front);
            front = rear = NULL;
        }

        else
        {
            printf("No Song Title Exist to Delete\n");
        }
    }

    else if (strcmp((front)->name, name)==0)
    {
        currentptr = front;
        front = (front)->nextptr;
        free(currentptr);//destroy  node, free the memory.
        currentptr= NULL;
    }
    else
    {
        struct songLibrary *curr1 = front;
        struct songLibrary *curr2;

        while (strcmp(curr1->nextptr->name, name)!=0 && curr1 !=NULL)
        {

            printf("%s\n", curr1);
            curr1 = curr1->nextptr;
        }

        if ( curr1->nextptr != rear )
        {
            curr2 = curr1->nextptr;
            curr1->nextptr = curr2->nextptr;
            free(curr2);
            curr2 = NULL;

        }

        else if (curr1->nextptr == rear)
        {
            free(rear);
            rear = curr1;
            (rear)->nextptr= NULL;
        }

        else
        {
            printf("No Song Title to Delete\n");
        }
    }
   display();//calling function
}//delete song
