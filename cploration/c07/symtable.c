#include "symtable.h"

unsigned int hash(char *str)
    {
        unsigned int hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash % SYMBOL_TABLE_SIZE;
    }

void insert(char* key, hack_addr addr){
	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	item->addr = addr;
	item->key = key;

	//get the hash
	int hashIndex = hashCode(key);

	//move in array until an empty or deleted cell
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != NULL) {
		//go to next cell
		++hashIndex;

		//wrap around table
		hashIndex %= SIZE;
	}

	hashArray[hashIndex] = item;
}

struct Symbol *find(char * key) {
	//get the hash
	char hashIndex = hashCode(key);

	//move in array until and empty
	while(hashArray[hashIndex] != NULL) {
		if(hashArray
	}
}

