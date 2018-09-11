/*=============================================================
| Source code:Assigment_1.c
|      Author:Alexis Gonzalez
|   Assigment:Specifications
|
|      Course:Programing 3
|     Section:U03
|  Instructor:William Feild
|    Due Date:11 September, 2018
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity
|
|	___________________________________________________
|
|    Language:C
| Compile/Run:gcc Assigment_1.c
|             ./a.out
|+--------------------------------------------------------------
| Description: This program prints out a distance conversion chart for
|	       miles to kilometers and kilometers to miles in steps 
|              indicated bu the user.
|
|       Input: User input on the requested size of the steps in the range
|              [1-9].Achieved by prompting user and validating user input.
|	       if input fails validation, this program will request a
|              new input to be validated. 
|
|      Output: A table showing the conversion from Kilometers to Miles
|              and Miles to Kilometers every step.The range for the 
|              table is 80 to 400. A empty line is printed after every 8 
|              lines in the table 
|
|     Process:The program Prints the  introduction message, then request
|             the step input and checks to see if it's an int from 1-9 
|             (Failure will require the user to re-input untill an 
|             acceptable value is found.) That step value is then passed
|             to the Print_table function. The print table function will
|             then generate the table by a for loop, using the current index
|             to request the converted values using the Kilometer_to_mile
|             and Mile_to_kilometer functions and printing that index line. 
|
| Required Features Not Included:N/A
|
|  Known Bugs: The input does not guard aganist inputs such as 8ABC 
|              (A number followed by a non-number character)
|              Example- 8ABC is read as 8.
|*===============================================================*/
#include <stdio.h>

float Kilometer_to_mile(float Kilometer);
float Mile_to_kilometer(float Mile);
int Step_input();
void Print_table(int step);
void Introduction();
/*
| Max_conversion_value- The maximun range that is included in the conversion
|                       table
| Min_conversion_value- The minimum range that is included in the conversion
|                       table
| Chart_Break- How many rows are printed untill a blank ine is printed.
*/

const int Max_conversion_value=400;
const int Chart_break=8;
const int Min_conversion_value=80;

/*
| The main does the following-
| Calls for the introduction text
| Request user input using Step_input for step
| Prints table using the user inputed step
*/
main()
   {
   int step;
   Introduction();
   step=Step_input();
   Print_table(step);
   }
/*
| Prints the introduction explaining the program to ysers
*/
void Introduction()
   {
   printf("This program will create a table that converts Miles"
          " to Kilometers \n and converts Kilometers to"
          " Miles from 80 to 400 in steps indicated \n by the user. \n");
   return;
   }
/*
|This function request the user to input a n interger value in the range [1-9]
|using a while loop to check the input. 
|
|Variables used: 
|              Float step ( This value is a float to assist in checking 
|                           if the user inputed an int or a float)  
|While Loop: Accepts a value and does the following checks:
|             scanf('%f",&step) != 1   ->  checks if there is no inputed number
|             (int)step != step        ->  checks if the user inputed a float
|             step > 9              ->  checks if the  input is greater than 9
|             step < 1                 ->  checks if the input is less than 1
|
|            If the check fails the following is executed:
|             Prints a message requesting a new input
|             clears the rest of the previous input using getchar
|              scanf acceps a new input.
|           User inputed step is returned as an int
*/
int Step_input()
   {

   float step=0.0;
   printf("Select the step with an int");
   printf(" from 1 and 9 for the conversion table \n");
   while(scanf("%f",&step ) != 1 || (int)step != step || step > 9
         || step < 1 )
      {
      printf("You entered an invalid answer, select a"
             " interger step from 1 to 9 \n");
      while(getchar() != '\n');
      } 
   return (int)step;
   }
/*
|This function takes the user inputed step to create a conversion table
|Variables used:
|           int step (function argument)
|              used to determine the value increase for each line in the table
|           int Table_location(initally set to the  lowest value for the table)
|              used to determine what value is being printed on the table
|           float Kilo_to_mile
|              used to hold converted kilometer_to_mile value
|           float Mile_to_kilo
|              used to hold converted Mile_to_kilometer value
|           int Break_counter( set to -1)
|              used to dertermine when to print a blank line
|   
| The function starts by printing the top ofthe table. Every line of  the
| table is then executed using the following loop
|  for(Table_locaton; Table_location < 400; Table_location=Table_location+step)
|    The loop starts with the minimum range, with each loop operating on the 
|    next step  value ( determed by step) and ends when the value reaches 
|    the maximum range value.
|
|
| The loop does the following:
|    Determines Kilo_to_mile using Kilometer_to_Mile Function
|    Determines Mile_to_kilo using Mile_to_Kilometer function
|    Determines if a break is needed
|        if so prints a blank line
|    Prints the table line
|
|  Example of table with break of 2,min _conversion_value=0, Step =5 : 
|  
|  Kilometer     Mile     Mile     Kilometer 
| ______________________________________________
|      0.00      0.00     0.00         0.00
|      5.00      3.11     5.00         8.05
|
|     10.00      6.21    10.00        16.09
|     15.00      9.32    15.00        24.14
|
*/
void Print_table(int step)
   {
   int Table_location=Min_conversion_value;
   float Kilo_to_mile;
   float Mile_to_kilo;
   int Break_counter=-1;
   printf("   Kilometers     Miles        Miles     Kilometers\n");
   printf("____________________________________________________\n");
   for(Table_location;Table_location<=Max_conversion_value;
       Table_location=Table_location+step)
      {
      
      
      Kilo_to_mile=Kilometer_to_mile((float)Table_location);
      Mile_to_kilo=Mile_to_kilometer((float)Table_location);
      Break_counter++;
      if(Break_counter == Chart_break)
         {
         printf("\n");
         Break_counter=0;
         }
      printf("      %5.2f      ",(float)Table_location);
      printf(" %5.2f      ",Kilo_to_mile);
      printf(" %5.2f      ",(float)Table_location);
      printf("%5.2f \n",Mile_to_kilo); 
      }
   return;
   }
/*
| This function converts Kilometers to Miles
|    Variables used:
|      Float Kilometer ( function argument)
|        used as the value thats converted
|      Float Mile 
|        used to store converted value
|
|  Equation used: Kilometer=Mile*0.6214
|      This is based on how many kilometers are in 1 mile to 4 decimal places. 
|       https://www.google.com/search?q=kilometer+to+mile
|
|  Returns Mile
*/

float Kilometer_to_mile(float Kilometer)
   {
   float Mile;
   Mile=Kilometer*0.6214;
   return Mile;
   }
/*
| This function converts Miles to Kilometers
|   Variables used :
|        Float Mile ( function argument)
|          Used  as the value thats converted
|        Float Kilometer
|          Used to store the converted value
|
|    Equation Used: Mile = Kilometer * 1.6093
|       This is based on how many kilometers are in a mile
|       https://www.google.com/search?q=mile+to+kilometer
|
|    Returns Kilometers
*/
float Mile_to_kilometer(float Mile)
   {
   float Kilometer;
   Kilometer=Mile*1.6093;
   return Kilometer;
   }

