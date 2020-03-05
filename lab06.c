/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. liang312@purdue.edu
*  2. jiang655@purdue.edu
*  3. liu2476@purdue.edu
*
*  Lab #: 06
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Thursday, 3:30, SC 231
*
*  Program Description:
*  The program takes in a interger between -[99999, 99999] and ouputs the text
*  version of the number.
*
***************************************************************************/
#include<stdio.h>
#include <math.h>

//global declarations
int getInput();
void onesF(int);
void tensF(int);
void hyphen();
void negativeF(int);
void thousandsF(int);
void hundredsF(int);

int main()
{

  int input;

  input = getInput();
  printf("Text equivalence:");

  if (input == 0)
  {
    printf("zero\n");
  }

  else
  {
    negativeF(input);
    input = fabs(input);

    thousandsF(input);
    hundredsF(input);
    tensF(input);
  }

  printf("\n");
  return(0);
}



int getInput()
{
  int input;
  printf("Enter integer in range [-99999, 99999] -> ");
  scanf("%d", &input);

  return(input);
}

void negativeF(int input)
{
  if(input < 0)
  {
    printf("minus");
  }
}

void onesF(int input)
{
  if(input == 1)
  {
    printf(" one");
  }
  else if(input == 2)
  {
    printf(" two");
  }
  else if(input == 3)
  {
    printf(" three");
  }
  else if(input == 4)
  {
    printf(" four");
  }
  else if(input == 5)
  {
    printf(" five");
  }
  else if(input == 6)
  {
    printf(" six");
  }
  else if(input == 7)
  {
    printf(" seven");
  }
  else if(input == 8)
  {
    printf(" eight");
  }
  else if(input == 9)
  {
    printf(" nine");
  }
}

void tensF(int input)
{

  if(input < 10)
  {
    input = (input % 100) /10;
    onesF(input);
  }
  else if(input < 20)
  {
    if (input == 10)
    {
      printf(" ten");
    }
    else if(input == 11)
    {
      printf(" eleven");
    }
    else if(input == 12)
    {
      printf(" twelve");
    }
    else if(input == 13)
    {
      printf(" thirteen");
    }
    else if(input == 14)
    {
      printf(" fourteen");
    }
    else if(input == 15)
    {
      printf(" fifteen");
    }
    else if(input == 16)
    {
      printf(" sixteen");
    }
    else if(input == 17)
    {
      printf(" seventeen");
    }
    else if(input == 18)
    {
      printf(" eighteen");
    }
    else if(input == 19)
    {
      printf(" nineteen");
    }
  }
  else if(input < 30)
  {
    printf(" twenty");
    hyphen();
    onesF(input - 20);
  }
  else if(input < 40)
  {
    printf(" thirty");
    hyphen();
    onesF(input - 30);
  }
  else if(input < 50)
  {
    printf(" fourty");
    hyphen();
    onesF(input - 40);
  }
  else if(input < 60)
  {
    printf(" fifty");
    hyphen();
    onesF(input - 50);
  }
  else if(input < 70)
  {
    printf(" sixty");
    hyphen();
    onesF(input - 60);
  }
  else if(input < 80)
  {
    printf(" seventy");
    hyphen();
    onesF(input - 70);
  }
  else if(input < 90)
  {
    printf(" eighty");
    hyphen();
    onesF(input - 80);
  }
  else if(input < 100)
  {
    printf(" ninty");
    hyphen();
    onesF(input - 90);
  }
}

void hyphen()
{
  printf("-");
}

void hundredsF(int input)
{
  input = (input % 1000) / 100;

  if(input == 1)
  {
    printf(" one");
  }
  else if(input == 2)
  {
    printf(" two");
  }
  else if(input == 3)
  {
    printf(" three");
  }
  else if(input == 4)
  {
    printf(" four");
  }
  else if(input == 5)
  {
    printf(" five");
  }
  else if(input == 6)
  {
    printf(" six");
  }
  else if(input == 7)
  {
    printf(" seven");
  }
  else if(input == 8)
  {
    printf(" eight");
  }
  else if(input == 9)
  {
    printf(" nine");
  }

  if (input != 0 )
  {
    printf(" hundred");
  }

  tensF(input);
}

void thousandsF(int input)
{

  int in = input / 1000;
  hundredsF(in);
  tensF(in);
  onesF(in);

  if(input >= 1000)
  {
    printf(" thousand");
  }
}
