#include <stdio.h>
#include <math.h>
#include <string.h>


// Subset contains the particular value like a, b, c , abc, ab etc
// For each value, check unique and add in unique_next field


struct Subset {
	char subset_val[50];
	struct Subset * next;
	struct Unique * unique_next;
} subset;

struct Unique {
	char unique_val[50];
	struct Unique * next;
} unique;

// reading data from data.txt

//(TODO: vijay, thapaliya) 

// Put this data in text file and read from text file
// Add the values in a char array e.g. [['11111', '1', '1', '1', '1'], more_values, more_values, more_values]


// 1. Write a function to add each element from powerset to the subset struct
// Use hashmap


void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 

    
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      char subset_val[4];

      int index = 0;
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j)){
            //printf("%c", set[j]);
            subset_val[index] = set[j];
            index ++;
            // each index coming over here
          }


       }

       // Now based on index add values after reading from file
       for (int i=0; i< index;i++){
        printf("%c",subset_val[i]);
       }


       index = 0;
       printf("\n");

    }

    

}
 
/*Driver program to test printPowerSet*/
int main()
{
  static const char filename[] = "data.txt";
   FILE *file = fopen ( filename, "r" );
   if ( file != NULL )
   {
      char line [ 128 ]; /* or other suitable maximum line size */
      char *p = NULL;
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
        //fputs ( line, stdout ); /* write the line */
        
        p = strtok(line," ");

        // from each line now we read word by word
        while(p != NULL)
        {
          //printf("%s\n ",p); /* your word */
          p = strtok(NULL," ");
        }
        // main logic goes here get the different combinations and add to hashmap

      }
      fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }

  char set[] = {'1','2','3', '4'};
  printPowerSet(set, 4);
  return 0;
}