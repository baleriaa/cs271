#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdint.h"

#define SYMBOL_TABLE_SIZE 100

typedef int16_t hack_addr;
 struct Symbol {
	char* name;
	hack_addr addr;
} Symbol;

struct Symbol* hashArray[SYMBOL_TABLE_SIZE];
struct Symbol *find(char * name);
int hash(char *str);
void insert(char* name, hack_addr addr);
void display_table();