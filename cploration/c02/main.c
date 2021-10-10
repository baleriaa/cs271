#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 100

int main()
{
/** WARMUP **/
// declare a string with value
char hello[] = "Hello";
// declare an empty string
char name[MAX_LIMIT]; 

// prompt user
printf("What is your name? ");

// read in a string from user and save in variable
// [^\n] means to discard the newline character
scanf("%[^\n]s", name);

// print out "hello <name>"
printf("%s %s!\n\n", hello, name);

/** Exercise 1 **/ 
char welcome[MAX_LIMIT];
strcpy(welcome, hello);
strcat(welcome, " ");
strcat(welcome, name);
printf("%s! \n", welcome);

/** Exercise 2 **/ 
int name_size = strlen(name);
printf("Your name is %d characters long\n", name_size);

/** Exercise 2 **/ 
char prof[8] = 
{
  'P','a','t','r','i','c','k','\0'
};
int first = strcmp(name, prof);
if(first < 0)
{
  printf("%s is before %s", name, prof);
}
else if (first > 0)
{
  printf("%s is before %s", prof, name);
}
else
{
  printf("%s is %s", name, prof);
}
return 0;
}
