#include <stdio.h>
#include <string.h>


#define MAX_LIMIT 100;

int main()
{
/** WARMUP **/
// declare a string with value
char hello[] = "Hello";
// declare an empty string
char name[100]; 

// prompt user
printf("What is your name? ");

// read in a string from user and save in variable
// [^\n] means to discard the newline character
scanf("%[^\n]s", name);

// print out "hello <name>"
printf("%s %s!\n\n", hello, name);

/** Exercise 1 **/ 
char welcome[100];
strcpy(welcome, hello);
strcat(welcome, " ");
strcat(welcome, name);
printf("%s! ", welcome);

/** Exercise 2 **/ 
int welcome_size = sizeof(name);
printf("Your name is %lu characters long", strlen(name));

/** Exercise 2 **/ 


return 0;
}

