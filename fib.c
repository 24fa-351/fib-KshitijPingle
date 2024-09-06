//Kshitij Pingle
//CWID: 885626978
//CPSC 351
//Assignment 1 - Fibonacci Sequence
//5 September 2024

#include <stdio.h>
#include <stdlib.h>

//Recursive Fibonacci Sequence
unsigned long fib_recurse(unsigned long previous, unsigned long current, unsigned long max, unsigned long count) {

   //Check if we're stopping
   if (count >= max) {
      return current;
   }

   int temp = previous;

   previous = current;
   current += temp;

   if (count == 1) {
      current++;        //Update current on first func call
   }

   //Recursively call function
   unsigned long fib_num = fib_recurse(previous, current, max, count + 1);

   return fib_num;
}

//Iterative Fibonacci Sequence
unsigned long fib_iterate(unsigned long previous, unsigned long current, unsigned long max) {
      
   unsigned long temp = 0;
   
   for (int i = 1; i < max; ++i) {     //Sorry prof, I like my 'i' counter vars
      temp = previous;
      previous = current;
      current += temp;
      
      if (i == 1) {
         current++;     //Update current on first iteration
      }
      
   }
   return current;
}


int main(int argc, char *argv[]) {

   //Receive and process all passed arguments
   unsigned long num1 = atoi(argv[1]);

   char route = argv[2][0];               //"i" = iterative, "r" = recursive

   unsigned long num2 = 0;

   FILE *file = fopen(argv[3], "r");      //"r" = read

   fscanf(file, "%lu", &num2);            //Get single num from file
   fclose(file);

   unsigned long max = num1 + num2;

   unsigned long previous = 0;
   unsigned long current = 0;
   unsigned long fib_num = 0;

   //Fibonnaci Sequence
      // 0 1 1 2 3 5 8 13 21 34 55 ...

   switch (route) {
      case 'i':
         //Call Iterative Fibonacci Function
         fib_num = fib_iterate(previous, current, max);
         break;

      case 'r':
         //Call Recursive Fibonacci Function
         fib_num = fib_recurse(previous, current, max, 1);
         break;
   
      default:
         break;
   }

   printf("%lu", fib_num);       //'lu' means unsigned long

   return 0;
}
