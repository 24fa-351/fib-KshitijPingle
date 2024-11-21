//Kshitij Pingle
//CWID: 885626978
//CPSC 351
//Assignment 1 - Fibonacci Sequence
//5 September 2024

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int (*FibFuncPtr) (unsigned int n);

//Recursive Fibonacci Sequence
unsigned int fib_recurse(unsigned int n) {

   if (n < 2) {
      return n;
   }
   return fib_recurse(n - 1) + fib_recurse(n - 2);
}

//Iterative Fibonacci Sequence
unsigned int fib_iterate(unsigned int n) {
      
   unsigned int temp = 0;
   unsigned int previous = 0;
   unsigned int current = 0;
   
   for (unsigned int i = 1; i < n; ++i) {     //Sorry prof, I like my 'i' counter vars
      temp = previous;
      previous = current;
      current += temp;
      
      if (i == 1) {
         current++;     //Update current on first iteration
      }
      
   }

   return current;
}


int main(unsigned int argc, char *argv[]) {

   if (argc != 4) {
      printf("Invalid number of arguments\n");
      printf("Usage: ./fib <num1> <fib_method> <file>\n");
      return 1;
   }

   //Receive and process all passed arguments
   unsigned int num1 = atoi(argv[1]);

   char fib_method = argv[2][0];           //"i" = iterative, "r" = recursive

   if ((fib_method != 'i') && (fib_method != 'r')) {
      printf("Invalid method. Fib method should either be an 'i' or a 'r'.\n");
      printf("Usage: ./fib <num1> <fib_method> <file>\n");
      return 1;
   }

   unsigned int num2 = 0;

   FILE *file = fopen(argv[3], "r");       //"r" = read

   fscanf(file, "%u", &num2);            //Get single num from file
   fclose(file);

   unsigned int max = num1 + num2;

   FibFuncPtr fib_routine;

   //Fibonnaci Sequence
      // 0 1 1 2 3 5 8 13 21 34 55 ...

   switch (fib_method) {
      case 'i':
         //Call Iterative Fibonacci Function
         // fib_num = fib_iterate(previous, current, max);
         fib_routine = fib_iterate;
         break;

      case 'r':
         //Call Recursive Fibonacci Function
         //fib_num = fib_recurse_provider(max - 1);
         // fib_num = fib_recurse(max - 1);
         fib_routine = fib_recurse;
         --max;
         break;
   
      default:
         break;
   }

   unsigned int fib_num = fib_routine(max);

   printf("%u", fib_num);       //'u' means unsigned int

   return 0;
}
