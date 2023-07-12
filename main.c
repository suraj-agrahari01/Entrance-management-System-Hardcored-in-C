#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#define Student struct Stud

void add(FILE * fp); //to add to list
void exam(FILE *fp);//for entrance examination
void show_record();
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void printHead();//printing head line for each screen
void sort(FILE *fp);//sorting

struct Stud
{
    char name[100];
    char dob[20];
    char address[50];
    int ID;
    float Mark;
    int n;
    char ph[20];
    char gname[100];
    char email[100];
    char gph[20];

};


int main()
{
 FILE * fp;
 Student s;
int option;
char another;

if((fp=fopen("D:\\student.txt","rb+"))==NULL)
{
    if((fp=fopen("D:\\student.txt","wb+"))==NULL)
       {
           printf("can't open file");
           return 0;
       }
}

printHead();
printf("\n\n\t\tCREATED BY");
printf("\n\n\t\tARJUN CHHETRI");
printf("\n\n\t\tNIRAJ DUWAL");
printf("\n\n\t\tSURAJ AGRAHARI");
printf("\n\n\t\tPROJECT ON ENTRANCE MANAGEMENT SYSTEM");
printf("\n\n\n\t\tpress any key to continue\n\t");
printChar('-',64);
getch();

while(1)
{
    printHead();
    printf("\n\t");
    printChar(':',64);

    printf("\n\n\t\t\t1. FORM FOR STUDENT");//ADD
    printf("\n\n\t\t\t2. MODIFY STUDENT RECORD");
    printf("\n\n\t\t\t3. ENTRANCE EXAMINATION");//MODIFY
    printf("\n\n\t\t\t4. DISPLAY STUDENT RECORD");//DISPLAY
    printf("\n\n\t\t\t5. SEARCH RECORD");// RECORD
    printf("\n\n\t\t\t6. RANK OF STUDENTS");//SORTING OF RANK OF STUDENT
    printf("\n\n\t\t\t0. EXIT");//TERMINATE THE PROGRAM
    printf("\n\t");
	printf("\n\t");
	printChar('*',64);
    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);


    switch(option)
    {
        case 0: return 1;
                break;
        case 1: add(fp);
                break;
        case 2: modify(fp);
                break;
        case 3: exam(fp);
                break;
        case 4: displayList(fp);
                break;
        case 5: searchRecord(fp);
                break;
        case 6: sort(fp);
				break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0);

    }
}
return 1;

}

//----printing character ch at n times ------

void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

//-----Printing Head Line of the program -----

void printHead()
{ system("cls");

printf("\n\n\t");
printChar('=',16);
printf("[ENTRANCE] [MANAGEMENT] [SYSTEM]");
printChar('=',16);
printf("\n");
}

// ===========sorting====================================
void sort(FILE * fp)
{
 printHead();
   Student s;
 int i,b,j,troll,siz=sizeof(s),a=0;
 float tmark;
 struct sort
 {
 	int roll;
 	float mark;
 }rank[a];

    rewind(fp);
    while((fread(&s,siz,1,fp))==1)
    {
        a+=1;
    }
	rewind(fp);
	b=0;
    while((fread(&s,siz,1,fp))==1)
    {
		rank[b].roll=s.ID;
		rank[b].mark=s.Mark;
     b+=1;
    }

      for (i=0;i<a;i++)
    {
    	for(j=0;j<a-1;j++)
    	{
    		if (rank[j].mark<rank[j+1].mark)
    		{
    			tmark=rank[j].mark;
    			rank[j].mark=rank[j+1].mark;
    			rank[j+1].mark=tmark;

    			troll=rank[j].roll;
    			rank[j].roll=rank[j+1].roll;
    			rank[j+1].roll=troll;
			}
				}
	}
	printf("\n\n\t");
	printChar('*',75);
	printf("\n\n\t\tRanking\t\t\tRoll No.\t\t\tMarks\n");
	for (i=0;i<a;i++)
	{
		if (rank[i].mark>=3)
		printf("\n\t\t%d\t\t\t%d\t\t\t%f",i+1,rank[i].roll,rank[i].mark);
	}
	printf("\n\n\t");
	printChar('~',75);
    	getch();

  }


// ==========FILLING STUDENT FORM==========================

void add(FILE * fp)

{
printHead();

char another='y';
Student s;
fseek(fp,0,SEEK_END);
 printf("\n\n\n");
    printf("\t\t");
    printChar('~',85);
    puts("\n\t\t*POINTS TO REMEMBER WHILE FILLING FORM");
    puts("\n\t\ti.  One should pay proper attention while filling the form.");
	puts("\n\t\tii. phone number and identification document number should be numeric (<10) i.e charcter");
	puts("\n\t\t    from 0 to 9.");
	puts("\n\t\tiii.one should remember their identification document number as it is the key factor");
	puts("\n\t\t    for other steps  ");
	puts("\n\t\tiv. one can modify their form record in modify portion with plenty of rs 500");
	puts("\n\t\tv.  identification document number should be last exam symbol number or ");
	puts("\n\t\t    citizenship number without any special sign(eg-,/_)  ");
	printf("\t\t");
	printChar('~',85);
	printf("\n\n\n");
	getch();
	printHead();
while(another=='y'||another=='Y')
{

    printf("\n\n\t\tEnter Full Name of Student:\t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter date of birth of Student:\t");
    fflush(stdin);
    fgets(s.dob,20,stdin);
    s.dob[strlen(s.dob)-1]='\0';

    printf("\n\n\t\tEnter Address:\t");
    fflush(stdin);
    fgets(s.address,50,stdin);
    s.address[strlen(s.address)-1]='\0';

    printf("\n\n\t\tIdentification document no: \t");
    scanf("%d",&s.ID);

	s.Mark=0;
	s.n=0;

    printf("\n\n\t\tEnter student phone number:\t");
    fflush(stdin);
    fgets(s.ph,20,stdin);
    s.ph[strlen(s.ph)-1]='\0';


  printf("\n\n\t\tEnter email ID Student:\t");
    fflush(stdin);
    fgets(s.email,100,stdin);
    s.email[strlen(s.email)-1]='\0';


    printf("\n\n\t\tEnter guardian name of Student:\t");
    fflush(stdin);
    fgets(s.gname,100,stdin);
    s.gname[strlen(s.gname)-1]='\0';


    printf("\n\n\t\tEnter student's guardian phone number:\t");
    fflush(stdin);
    fgets(s.gph,20,stdin);
    s.gph[strlen(s.gph)]='\0';

    fwrite(&s,sizeof(s),1,fp);
    printf("\n\n\t\tWant to enter another student info (Y/N)\t");
    fflush(stdin);
    another=getche();
}
}

//===================ENTRANCE EXAMINATION===============
void exam(FILE *fp)
{
    printHead();
    int tempRoll,flag,siz,r;
    Student s;
    float countr;
    char another,cha;
    siz=sizeof(s);
    fseek(fp,0,SEEK_END);
    printf("\n\n\n");
    printf("\t\t");
    printChar('~',85);
    puts("\n\t\t*POINTS TO REMEMBER WHILE GIVING EXAMINATION ");
    puts("\n\t\ti.   One should enter their identification document number to began the entrance exam.");
	puts("\n\t\tii.  Entrance is taken for 20 minute having total 10 marks.");
	puts("\n\t\tiii. Examinee can skip any question by pressing's' ");
	puts("\n\t\tiv.  Once skipped questions cant be reattemped.");
	puts("\n\t\tv.   It consist of 10 question each having 1 marks.");
	puts("\n\t\tvi.  There is the negative marking of 10% marks per each wrong answer.");
	puts("\n\t\tvii. Once the answer is submitted cannot be recorrected.");
	puts("\n\t\tviii.Total score is displayed when all the answer are submitted.");
	printf("\t\t");
	printChar('~',85);
	printf("\n\n\n");
	getch();
	printHead();
    printf("\n\n\t\t Do you want to take exam  (Y/N)\t");
	fflush(stdin);
    another=getch();

   if (another=='y'||another=='Y')
   {
    printf("\n\n\tEnter Identification Number of Student: ");
    scanf("%d",&tempRoll);
    rewind(fp);
    while((fread(&s,siz,1,fp))==1)
    {
    if(s.ID==tempRoll&& s.n==0)
        {
		flag=1;
        break;
        }
    }
     if (flag==1)
      {countr=0.0;
      int i,m;
     bool arr[10]={0};
     int A[10];
     // srand(time(NULL));
     time_t t;
     srand((unsigned)time(&t));

   for (i=0;i<10;i++)
    {int r = rand()%10;
    if(!arr[r])
    A[i]= r;
    else
    i--;
    arr[r]=1;
     }

      for(i=0;i<10;i++)
        {
                //system("cls");
                     // A[i]=i;

     switch(A[i])
     {
		case 1:
		a1:
		    system("cls");
		printf("\n\n\n\tQ.The word ‘engineer’ has its primary stress on its ______ syllable:\n");
		printf("\n\n\t(A) first \t\t(B) second \n\t(C) third \t\t(D) fourth");
		//ans c
		cha=getch();
		if (cha=='c'||cha=='C')
		{
			countr++;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='d'||cha=='D')
		{
			countr-=.1;
			break;
		}else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a1;
		}


		case 2:
            system("cls");
		a2:
		printf("\n\n\n\tQ.Two and two _____ four.");
		printf("\n\n\n\t(A) makes \t\t\t(B) make \n\t(C) have made \t\t\t(D) will be made ");
		// ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
				else if(cha=='c'||cha=='C'||cha=='b'||cha=='B'||cha=='d'||cha=='D')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a2;
		}


		    case 3:
                system("cls");
		a3:
		printf("\n\n\n\t\tQ.pH of 0.2 N H2SO4 is:");
		printf("\n\n\n\t(A) 0.69 \t\t\t(B) 1.2 \n\t(C) 0.76 \t\t\t(D) 0.56");
		// ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;
		}		else if(cha=='c'||cha=='C'||cha=='b'||cha=='B'||cha=='d'||cha=='D')
		{
			countr-=.1;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a3;
		}


			case 4:
            system("cls");
            a4:
		printf("\n\n\n \tQ.Catalytic oxidation of ammonia in air forms:");
		printf("\n\n\n\t(A)NO2 \t\t\t(B) N2O5 \n\t(C) N2O \t\t(D) NO");
		//ans d
		cha=getch();
		if (cha=='d'||cha=='D')
		{
			countr++;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}		else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='c'||cha=='C')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a4;
		}


		case 5:

		    system("cls");
		    a5:
		printf("\n\n\n\t\tQ.The magnetism of the magnet is due to:");
		printf("\n\n\n\t(A) the spin motion of electron \n\t\t(B) cosmic ray \n\t(C) the earth \n\t\t(D) pressure of big magnet inside the earth ");
		//ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;

		}else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
				else if(cha=='d'||cha=='D'||cha=='b'||cha=='B'||cha=='c'||cha=='C')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a5;
		}


        case 6:
            system("cls");
            a6:
		printf("\n\n\n\tQ.The maximum percentage of ingredients in cement is that of:");
		printf("\n\n\t(A) magnesia \t\t(B) lime \n\t(C) alumina \t\t(D) silica");
		//ans b
		cha=getch();
		if (cha=='b'||cha=='B')
		{
			countr++;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
				else if(cha=='a'||cha=='A'||cha=='d'||cha=='D'||cha=='c'||cha=='C')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a6;
		}


        case 7:
            system("cls");
            a7:
		printf("\n\n\n\tQ.The second derivative of f(x) = 1/x at point (1,1) is equal to:");
		printf("\n\n\t(A) 1 \t\t\t(B) -1 \n\t(C) 2 \t\t\t(D) -2");
		//ans c
		cha=getch();
		if (cha=='c'||cha=='C')
		{
			countr++;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
				else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='d'||cha=='D')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a7;
		}


		case 8:
            system("cls");
            a8:
		printf("\n\n\n\tQ.Which of the following is a logic gates? ");
		printf("\n\n\tA.PUT\t\tB.THEN\n\tC.NOR\t\tD.WHEN\n");
		//ans c
		cha=getch();
		if (cha=='c'||cha=='C')
		{
			countr++;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
				else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='d'||cha=='D')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a8;
		}


		case 9:
            system("cls");
            a9:
		printf("\n\n\n\tQ.:If the line 2x+3y+4+k(-x+y+5)=0 is horizontal then the value of k is:");
		printf("\n\n\t(A) 0 \t\t\t(B) 1 \n\t(C) 3 \t\t\t(D) 2");
		//ans d
		cha=getch();
		if (cha=='d'||cha=='D')
		{
			countr++;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
				else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='c'||cha=='C')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a9;
		}


		case 10:
            system("cls");
            a10:
		printf("\n\n\t\tQ.:IUPAC name of CH3-CH2 - CH2 -CH (OCH3) - CO Br is:");
		printf("\n\t(A) 2- methoxylpentanoyl bromide \t\t\t\t(B) 3- methoxylpentanoyl bromide \n\t\t\t\t(C) 3-methoxyhexanoyl bromide \t\t(D) 2-methoxyhexanoyl bromide");
		//ans a
		cha=getch();
		if (cha=='a'||cha=='A')
		{
			countr++;
			break;
		}
		else if(cha=='s'||cha=='S')
		{
			countr=countr+0;
			break;
		}
				else if(cha=='a'||cha=='A'||cha=='b'||cha=='B'||cha=='c'||cha=='C')
		{
			countr-=.1;
			break;
		}
		else{
			printf("\n\n\n\n\t\t\t\t<error in choosing option:>");
			getch();
			goto a10;
		}

		} //s.ID;
    }
     fflush(stdin);
						//to hold marks
	 rewind(fp);
while((fread(&s,siz,1,fp))==1)
{
    if(s.ID==tempRoll)
        {
		  flag=1;
          break;
        }
}
if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    s.Mark=countr;
	s.n=1;						       //to check exam given or not
    fwrite(&s,sizeof(s),1,fp);
}

     system("cls");
	 printf("\n\n\n\n\t\t\tCongratulations %s you scored=%f\n",s.name,s.Mark);
     printf("\t\t\tBest of luck for result\n");
	 printf("\t\t\tpress any key to go homepage\t");
    fflush(stdin);
    }
   else
    {
        printf("\n\t\t\t EITHER YOU HAVENOT REGISTER YET OR YOU HAVE ALREADY GIVEN EXAM\n");
    }
   getch();
   }
}

//===========MODIFY A RECORD ===========================

void modify(FILE * fp)
{
printHead();

Student s;
int i,flag=0,tempRoll,siz=sizeof(s);
float cgpa;
printf("\n\n\t Precaution:one shouldn't enter a string character while entering ID number");
printf("\n\n\tEnter  identification document  Number of Student to MODIFY the Record : ");
scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.ID==tempRoll)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRECORD FOUND");
    printf("\n\n\t\tEnter New Data for the Record");

    printf("\n\n\t\tEnter Full Name of Student\t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter date of birth of Student\t");
    fflush(stdin);
    fgets(s.dob,20,stdin);
    s.dob[strlen(s.dob)-1]='\0';

    printf("\n\n\t\tEnter Address\t");
    fflush(stdin);
    fgets(s.address,50,stdin);
    s.address[strlen(s.address)-1]='\0';

    printf("\n\n\t\tEnter student phone number\t");
    fflush(stdin);
    fgets(s.ph,20,stdin);
    s.ph[strlen(s.ph)-1]='\0';


  printf("\n\n\t\tEnter email ID Student\t");
    fflush(stdin);
    fgets(s.email,100,stdin);
    s.email[strlen(s.email)-1]='\0';


    printf("\n\n\t\tEnter guardian name of Student\t");
    fflush(stdin);
    fgets(s.gname,100,stdin);
    s.gname[strlen(s.gname)-1]='\0';


    printf("\n\n\t\tEnter student's guardian phone number\t");
    fflush(stdin);
    fgets(s.gph,20,stdin);
    s.gph[strlen(s.gph)]='\0';
    fwrite(&s,sizeof(s),1,fp);
}

else
{
	printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");
}

printf("\n\n\t");
system("pause");

}

//====================DISPLAY THE LIST =================
void displayList(FILE * fp)
{   printHead();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\t\tDATE OF BIRTH:%s",s.dob);
        printf("\n\t\tADDRESS: %s",s.address);
        printf("\n\t\tIDENTIFICATION DOCUMENT NO.:%d",s.ID);
        printf("\n\t\tPHONE NUMBER:%s",s.ph);
		if (s.n!=0)
		printf("\n\t\tmark :%f",s.Mark);
        printf("\n\t\tGURDAIN NAME:%s",s.gname);
        printf("\n\t\tEMAIL ADDRESS OF STUDENT:%s",s.email);
        printf("\n\t\tGURDAIN PHONE NUMBER:%s",s.gph);
		printf("\n\n\t\t");
		printChar('x',40);
		printf("\n\n");
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}
//====================SEARCH =================
void searchRecord(FILE *fp)
{
    printHead();

int tempRoll,flag,siz,i;
Student s;
char another='y';

siz=sizeof(s);

while(another=='y'||another=='Y')
  {
  printf("\n\n\tEnter Identification Number of Student to search the record : ");
  scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.ID==tempRoll)
        {flag=1;
        break;
        }
}
if(flag==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\t\tDATE OF BIRTH:%s",s.dob);
        printf("\n\t\tADDRESS: %s",s.address);
        printf("\n\t\tIDENTICATION DOCUMENT NO.: %d",s.ID);
        printf("\n\t\tPHONE NUMBER:%s",s.ph);
        printf("\n\t\tGURDAIN NAME:%s",s.gname);
        printf("\n\t\tEMAIL OF STUDENT:%s",s.email);
        printf("\n\t\tGURDAIN PHONE NUMBER:%s",s.gph);

     }
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
printf("\n");
printChar('~',65);
printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getch();
  }
}
