#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdint.h"

SYMBOL_TABLE_SIZE 100

typdef int16_t hack_addr

typedef struct Symbol {
	char name[SYMBOL_TABLE_SIZE];
	int addr;
}

Symbol* hashArray[SYMBOL_TABLE_SIZE];

int hash(char *str);
struct Symbol *find(char * key);
void insert(char* key, hack_addr addr);
void display_table();
