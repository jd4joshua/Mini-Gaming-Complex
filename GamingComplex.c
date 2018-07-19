#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
static int i=0;
int flPos=0,ran;
static char grid[6][7];
unsigned long amount=10000,deposit,withdraw;
int choice,p,k=1;
char transaction='y';
int n;
void login(void);
void reg(void);
void atm();
void currentPos();
void floor();
void callElevator();
void toFl();
void start();
void drop(int col,int);
void check();
int checkVerticalx();
int checkHorizontalx();
int checkDiagonalDownx();
int checkDiagonalUpx();
int checkVerticalo();
int checkHorizontalo();
int checkDiagonalDowno();
int checkDiagonalUpo();
int main()
{
 char ch;
 srand(time(NULL));
 clrscr();
 printf("\nWELCOME TO MY MINI GAMING COMPLEX");
 printf("\n=================================");
 printf("\nPress Any key to proceed...!!");
 getch();
 clrscr();
 XY:
 printf("\n1. LOGIN\t2. REGISTER");
 printf("\nENTER YOUR CHOICE: ");
 scanf("%d",&n);
 switch(n)
 {
  case 1:clrscr();
	 login();
	 break;
  case 2:clrscr();
	 reg();
	 break;
  default:printf("\nNO MATCH FOUND");
	  printf("\nPress Enter to re-Enter the choice");
	  if(getch()==13)
	   clrscr();
	  goto XY;
 }
 enter:
 printf("\nPress ENTER to go to the ATM!");
 if(getch()==13)
  {
   clrscr();
   atm();
  }
 else
 { goto enter;}
 ran=rand()%2;
 printf("\n-------ELEVATOR----------------");
 printf("\n [1] |    |    |   -->Connect 4");
 printf("\n [0] |   [E]   |   -->ATM");
 printf("\nPress enter to continue");
 getch();
 floor();
 return 0;
}
void reg()
{
 FILE *fp1,*fp2;
 char name[30],pass[30],temp[30];
 //int z=0;
 fp1=fopen("username.txt","a+");
 fp2=fopen("password.txt","a+");
 printf("\nWELCOME TO THE REGISTRATION");
 printf("\n===========================");
 printf("\nENTER USERNAME: ");
 scanf("%s",name);
 while(!feof(fp1))
 {
  fscanf(fp1,"%s",temp);
  if(strcmp(temp,name)==0)
  {
   printf("\nUSERNAME ALREADY EXISTS");
   reg();
  }
 }
 fprintf(fp1,"%s\n",name);
 printf("\nDESIRED PASSWORD: ");
 /*z=0;
 while((c=getch())!=13)
 {
  pass[z++]=c;
  printf("%c",'*');
 }
 for(z=0;z<10;z++)
 {
  pass[z]=getch();
  if(pass[z]==13)
  {
   pass[z]='\0';
   break;
  }
  else
  {
   printf("*");
  }
 }*/
 scanf("%s",pass);
 fprintf(fp2,"%s\n",pass);
 fclose(fp1);
 fclose(fp2);
 printf("\nPress enter if you agree with Username and Password");
 getch();
 clrscr();
 printf("\nYou are successfully registered");
 printf("\nTry login your account??\n");
 printf("> PRESS 1 FOR YES\n> PRESS 2 FOR NO\n");
 scanf("%d",&n);
 switch(n)
 {
  case 1:clrscr();
	 login();
	 break;
  case 2:clrscr();
	 printf("\nTHANK YOU FOR REGISTERING!");
	 break;
 }
 getch();
}
void login()
{
 FILE *fp1,*fp2;
 char name[30],pass[30],temp1[30],temp2[30];
 int i,flag=0;
 fp1=fopen("username.txt","a+");
 fp2=fopen("password.txt","a+");
 printf("\nWELCOME TO LOG IN ZONE");
 printf("\n^^^^^^^^^^^^^^^^^^^^^^");
 printf("\nENTER USERNAME: ");
 scanf("%s",name);
 printf("\nENTER PASSWORD: ");
 scanf("%s",pass);
 while(!feof(fp1))
 {
  flag=0;
  for(i=0;i<30;i++)
  {
   temp1[i]='\0';
   temp2[i]='\0';
  }
  fscanf(fp1,"%s",temp1);
  fscanf(fp2,"%s",temp2);
  if((strcmp(temp1,name)==0)&&(strcmp(temp2,pass))==0)
  {
   flag=1;
   break;
  }
 }
 if(flag==1)
 {
  clrscr();
  printf("\nYOU HAVE LOGGED IN SUCCESSFULLY!!");
  printf("\nWELCOME, HAVE A NICE DAY");
 }
 else
 {
  printf("\nIncorrect Username or Password!");
  printf("\nWould you like to Register? Press Enter if yes!");
  if(getch()==13)
  {reg();}
  else
  {login();}
 }
 fclose(fp1);
 fclose(fp2);
 getch();
}
void currentPos()
{
 clrscr();
 printf("\nCurrent position of the elevator:");
 switch (ran)
 {
  case 0:printf("\n [1] |    |    |   -->Connect 4");
	 printf("\n [0] |   [E]   |   -->ATM");
	 break;
  case 1:printf("\n [1] |   [E]   |   -->Connect 4");
	 printf("\n [0] |    |    |   -->ATM");
	 break;
 }
 ran=rand()%2;
}
void floor()
{
 currentPos();
 printf("\nYou are currently on floor: %d",flPos);
 printf("\nPress enter to call elevator");
 getch();
 callElevator();
}
void callElevator()
{
 clrscr();
 switch(flPos)
 {
  case 0:printf("\n [1] |    |    |   -->Connect 4");
	 printf("\n [0] |   [E]   |   -->ATM");
	 break;
  case 1:printf("\n [1] |   [E]   |   -->Connect 4");
	 printf("\n [0] |    |    |   -->ATM");
	 break;
 }
 printf("\nPress enter to continue");
 getch();
 toFl();
}
void toFl()
{
 int to;
 delay(1000);
 printf("\nYou are now inside the elevator. \nTo Which floor do you want to go?");
 scanf("%d",&to);
 switch (to)
 {
  case 0:printf("\n [1] |    |    |   -->Connect 4");
	 printf("\n [0] |   [E]   |   -->ATM");
	 flPos=0;
	 printf("\nYou have chosen to use ATM");
	 delay(3000);
	 printf("\nPress Enter to go to the ATM!");
	 if(getch()==13)
	 {
	  clrscr();
	  atm();
	 }
	 else
	 {break;}
	 break;
  case 1:printf("\n [1] |   [E]   |   -->Connect 4");
	 printf("\n [0] |    |    |   -->ATM");
	 flPos=1;
	 printf("\nYou have chosen to play Connect 4");
	 delay(3000);
	 start();
	 break;
  default:printf("Invalid Option!");
 }
 floor();
}
void atm()
{
 clrscr();
 while(k!=0)
 {
  printf("\n********Welcome to ATM Service**************\n");
  printf("1. Check Balance\n");
  printf("2. Withdraw Cash\n");
  printf("3. Deposit Cash\n");
  printf("4. Quit\n");
  printf("********************************************\n\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch(choice)
  {
   case 1:printf("\n YOUR BALANCE IS Rs : %lu ",amount);
	  break;
   case 2:printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
	  scanf("%lu",&withdraw);
	  if(withdraw%100!=0)
	  {
	   printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
	  }
	  else if(withdraw>(amount-500))
	  {
	   printf("\n INSUFFICENT BALANCE!");
	  }
	  else
	  {
	   amount=amount-withdraw;
	   printf("\n\n PLEASE COLLECT CASH");
	   printf("\n YOUR CURRENT BALANCE IS: %lu", amount);
	  }
	  break;
   case 3:printf("\n ENTER THE AMOUNT TO DEPOSIT:");
	  scanf("%lu",&deposit);
	  amount=amount+deposit;
	  printf(" YOUR BALANCE IS: %lu", amount);
	  break;
   case 4:printf("\n THANK YOU FOR USING ATM!");
	  break;
   default:printf("\n INVALID CHOICE!");
  }
  printf("\n\nDO YOU WISH TO HAVE ANOTHER TRANSCATION?(Y/N):");
  transaction=getch();
  clrscr();
  if(transaction=='n'||transaction=='N')
   {k=0;clrscr();}
 } k=1;
}
void start()
{
 int a=100,count=1;char pl1[30];int i,c,j,l,r;
 amount=amount-750;
 clrscr();
 for(i=0;i<6;i++)
 {
  for(j=0;j<7;j++)
  {
   grid[i][j]='-';
  }
 }
 printf("\t\tWelcome to connect 4!\n*********************************************\nThe aim of this game is to get 4 coins in \nseries-vertically,horizontally or diagonally.");
 printf("\n*********************************************\nLet's begin!");
 printf("\nRs. 750 will be deducted from your account to play the game!");
 printf("\nWould you like to play the game? Press Enter if Yes!");
 if(getch()==13)
 { printf("\nBalance=%d",amount);}
 else
 {
  flPos=1;
  floor();
 }
 printf("\nEnter name of player 1:");
 scanf("%s",pl1);
 printf("\n\nHere is your grid:\n");
 printf("0 1 2 3 4 5 6\n");
 for(i=0;i<6;i++)
 {
  for(j=0;j<7;j++)
  {
   printf("%c ",grid[i][j]);
  }
  printf("\n");
 }
 while(a!=0)
 {
  if(count%2==1)
  {
   check();
   printf("\n%s:",pl1);
   printf("\nEnter column number:");
   scanf("%d",&c);
   {drop(c,count);}
   printf("\nHere is your Grid now:");
   printf("\n0 1 2 3 4 5 6\n");
   for(i=0;i<6;i++)
   {
    for(j=0;j<7;j++)
    {
     printf("%c ",grid[i][j]);
    }
    printf("\n");
    //check();
   }
   count++;
   --a;
  }
  else if(count%2==0)
  {
   check();
   r=rand()%7;
   printf("\nComputer chooses:%d",r);
   drop(r,count);
   printf("\nHere is you Grid now:");
   printf("\n0 1 2 3 4 5 6\n");
   for(i=0;i<6;i++)
   {
    for(j=0;j<7;j++)
    {
     printf("%c ",grid[i][j]);
    }
    printf("\n");
    //check();
    r=rand()%7;
   }
   count++;
   --a;
  }
 }
}
void drop(int col,int count)
{
 int r=5;
 while(r!=-1)
 {
  if(grid[r][col]=='-')
  {
   if(count%2==1)
    {grid[r][col]='x';}
   else if(count%2==0)
    {grid[r][col]='o';}
   break;
  }
  else if(grid[r][col]=='x'||grid[r][col]=='o')
  {
   r--;
  }
 }
 if(r==-1)
 printf("You cannot insert any more coins in this column");
}
void check()
{
 int re1,re2,re3,re4,re5,re6,re7,re8,cho;
 re1=checkVerticalx();
 re2=checkHorizontalx();
 re3=checkDiagonalDownx();
 re4=checkDiagonalUpx();
 if(re1==1||re2==1||re3==1||re4==1)
 {
  printf("\nYou are the Winner");
  printf("\nCongratulations you won Rs.1000");amount=amount+1000;
  printf("\nCurrent balance=%d",amount);
  delay(10000);clrscr();
  printf("\nWould you like to:");
  printf("\n1.Play again?\n2.Goto the elevator? or\n3.Exit?");
  printf("\nEnter your choice:");
  scanf("%d",&cho);
  switch(cho)
  {
   case 1:start();break;
   case 2:floor();break;
   case 3:exit(0);
   default:printf("\nInvalid Entry!");
  }
 }
 re5=checkVerticalo();
 re6=checkHorizontalo();
 re7=checkDiagonalDowno();
 re8=checkDiagonalUpo();
 if(re5==1||re6==1||re7==1||re8==1)
 {
  printf("Computer is the Winner");
  delay(10000);clrscr();
  printf("\nWould you like to:");
  printf("\n1.Play again?\n2.Goto the elevator? or\n3.Exit?");
  printf("\nEnter your choice:");
  scanf("%d",&cho);
  switch(cho)
  {
   case 1:start();break;
   case 2:floor();break;
   case 3:exit(0);
   default:printf("\nInvalid Entry!");
  }
 }
}
int checkVerticalx()
{
 int flags=0;
 int row,col;
 for(col=0;col<7;col++)
 {
  for(row=0;row<=2;row++)
  {
   if((grid[row][col]=='x')&&
   (grid[row+1][col]=='x')&&
   (grid[row+2][col]=='x')&&
   (grid[row+3][col]=='x'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
int checkHorizontalx()
{
 int flags=0;
 int row,col;
 for(row=0;row<6;row++)
 {
  for(col=0;col<=3;col++)
  {
   if((grid[row][col]=='x')&&
   (grid[row][col+1]=='x')&&
   (grid[row][col+2]=='x')&&
   (grid[row][col+3]=='x'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
int checkDiagonalDownx()
{
 int flags;
 int row,col;
 //Check diagonal "\"
 for(row=0;row<=2;row++)
 {
  for(col=0;col<=3;col++)
  {
   if((grid[row][col]=='x')&&
   (grid[row+1][col+1]=='x')&&
   (grid[row+2][col+2]=='x')&&
   (grid[row+3][col+3]=='x'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
int checkDiagonalUpx()
{
 int flags;
 int row,col;
 //Check diagonal "/"
 for(row=0;row<=2;row++)
 {
  for(col=3;col<=6;col++)
  {
   if((grid[row][col]=='x')&&
   (grid[row+1][col-1]=='x')&&
   (grid[row+2][col-2]=='x')&&
   (grid[row+3][col-3]=='x'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
int checkVerticalo()
{
 int flags=0;
 int row,col;
 for(col=0;col<7;col++)
 {
  for(row=0;row<=2;row++)
  {
   if((grid[row][col]=='o')&&
   (grid[row+1][col]=='o')&&
   (grid[row+2][col]=='o')&&
   (grid[row+3][col]=='o'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
int checkHorizontalo()
{
 int flags=0;
 int row,col;
 for(row=0;row<6;row++)
 {
  for(col=0;col<=3;col++)
  {
   if((grid[row][col]=='o')&&
   (grid[row][col+1]=='o')&&
   (grid[row][col+2]=='o')&&
   (grid[row][col+3]=='o'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
int checkDiagonalDowno()
{
 int flags;
 int row,col;
 //Check diagonal "\"
 for(row=0;row<=2;row++)
 {
  for(col=0;col<=3;col++)
  {
   if((grid[row][col]=='o')&&
   (grid[row+1][col+1]=='o')&&
   (grid[row+2][col+2]=='o')&&
   (grid[row+3][col+3]=='o'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
int checkDiagonalUpo()
{
 int flags;
 int row,col;
 //Check diagonal "/"
 for(row=0;row<=2;row++)
 {
  for(col=3;col<=6;col++)
  {
   if((grid[row][col]=='o')&&
   (grid[row+1][col-1]=='o')&&
   (grid[row+2][col-2]=='o')&&
   (grid[row+3][col-3]=='o'))
   {
    flags=1;
    return (flags);
   }
  }
 }
 return (flags);
}
