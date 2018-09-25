/*=============================================================
| Source code:Conversion_chart.c
|      Author:Alexis Gonzalez
|   Assignment:Specifications
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
| Compile/Run:gcc Conversion_chart.c
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

float Kilometer_to_mile(float kilometer);
float Mile_to_kilometer(float mile);
int Step_input();
void Print_table(int step);
void Introduction();
/*
| Max_conversion_value- The maximun range that is included in the conversion
|                       table
| Min_conversion_value- The minimum range that is included in the conversion
|                       table
| Chart_Break- How many rows are printed untill a blank ine is printed.
|
| Break_check- The value used to check if a blank line should be printed.
|
| Min_input_value- The Minimum accepted step
|
| Max_input_value- The maximum accepted step
|
| Number_exist_check- The value used  to check if an int exist
|
| Kilometer_to_mile_conversion_rate- The value used to convert kilometers
|                                    to miles
|
| Mile_to_kilometer_conversion_rate- The value used to convert miles to 
|                                    kilometers
|
*/

const int Max_conversion_value = 400;
const int Chart_break = 8;
const int Break_check = 0;
const int Min_conversion_value = 80;
const int Min_input_value = 1;
const int Max_input_value = 9;
const int Number_exist_check=1;
const float Kilometer_to_mile_conversion_rate = 0.6214;
const float Mile_to_kilometer_conversion_rate = 1.6093;

/*
| The main does the following-
| Calls for the introduction text
| Request user input using Step_input for step
| Prints table using the user inputed step
*/
int main()
   {
   Introduction();
   int step = Step_input();
   Print_table(step);
   }
/*
| Prints the introduction explaining the program to users
*/
void Introduction()
   {
   printf("This program will create a table that converts Miles"
          " to Kilometers \n and converts Kilometers to"
          " Miles from %d to %d in steps indicated \n by the"
          " user. \n",Min_conversion_value,Max_conversion_value);
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
|
|             scanf('%f",&step) != Number_exist_check   ->  checks if
|                                              there is no inputed number
|
|
|             (int)step != step    ->  checks if the user inputed a float
|
|             step > Max_input_value ->  checks if the  input is greater than
|                                       the Max_input_value
|
|             step < Min_input_value ->  checks if the input is less than 
|                                       the Min_input_value
|
|            If the check fails the following is executed:
|             Prints a message requesting a new input
|             clears the rest of the previous input using getchar
|              scanf acceps a new input.
|           User inputed step is returned as an int
*/
int Step_input()
   {

   float step = 0.0;
   printf("Select the step with an int");
   printf(" from %d and %d for the conversion table"
          " \n",Min_input_value,Max_input_value);
   while(scanf("%f",&step ) != Number_exist_check
         || (int)step != step
         || step > Max_input_value
         || step < Min_input_value )
      {
      printf("You entered an invalid answer, select a"
             " integer step from %d to %d"
             " \n",Min_input_value,Max_input_value);
      while(getchar() != '\n');
      } 
   return (int)step;
   }
/*
|This function takes the user inputed step to create a conversion table
|Variables used:
|           int step (function argument)
|              used to determine the value increase for each line in the table
|           int table_location(initally set to Min_conversion_value)
|              used to determine what value is being printed on the table
|           float kilo_to_mile( set to 0)
|              used to hold converted kilometer_to_mile value
|           float mile_to_kilo( set to 0)
|              used to hold converted Mile_to_kilometer value
|           int break_counter( set to -1)
|              used to dertermine when to print a blank line
|   
| The function starts by printing the top ofthe table. Every line of  the
| table is then executed using the following loop
|  for(table_locaton; table_location < Max_conversion_value;
|      table_location=table_location+step)
|    The loop starts with the minimum range, with each loop operating on the 
|    next step  value ( determed by step) and ends when the value reaches 
|    the maximum range value.
|
|
| The loop does the following:
|    Determines kilo_to_mile using Kilometer_to_Mile Function
|    Determines mile_to_kilo using Mile_to_Kilometer function
|    Determines if a break is needed
|        if so prints a blank line
|    Prints the table line using %15.2f (15 spaces reserved,
|                                        2 decimal places)
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
   int table_location = Min_conversion_value;
   float kilo_to_mile = 0;
   float mile_to_kilo = 0;
   int break_counter = -1;
   printf("   Kilometers     Miles        Miles     Kilometers\n");
   printf("____________________________________________________\n");
   for(table_location;table_location <= Max_conversion_value;
       table_location = table_location+step)
      {
      
      
      kilo_to_mile = Kilometer_to_mile((float)table_location);
      mile_to_kilo = Mile_to_kilometer((float)table_location);
      break_counter++;
      if(break_counter % Chart_break == Break_check )
         {
         printf("\n");
         }
      printf(" %12.2f",(float)table_location);
      printf("%12.2f",kilo_to_mile);
      printf("%12.2f",(float)table_location);
      printf("%12.2f\n",mile_to_kilo); 
      }
   return;
   }
/*
| This function converts Kilometers to Miles
|    Variables used:
|      Float kilometer ( function argument)
|        used as the value thats converted
|      Float mile 
|        used to store converted value
|
|  Equation used: kilometer=mile*0.6214
|      This is based on how many kilometers are in 1 mile to 4 decimal places. 
|       https://www.google.com/search?q=kilometer+to+mile
|
|  Returns mile
*/

float Kilometer_to_mile(float kilometer)
   {
   float mile = kilometer * Kilometer_to_mile_conversion_rate;
   return mile;
   }
/*
| This function converts Miles to Kilometers
|   Variables used :
|        Float mile ( function argument)
|          Used  as the value thats converted
|        Float kilometer
|          Used to store the converted value
|
|    Equation Used: mile = kilometer * 1.6093
|       This is based on how many kilometers are in a mile
|       https://www.google.com/search?q=mile+to+kilometer
|
|    Returns kilometers
*/
float Mile_to_kilometer(float mile)
   {
   float kilometer = mile * Mile_to_kilometer_conversion_rate;
   return kilometer;
   }

