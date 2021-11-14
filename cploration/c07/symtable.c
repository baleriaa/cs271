#include <symtable.h>

    int hash (char *str)
    {
        long hash = 5381;
        int c;
        while ((c = *str++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        return hash % SYMBOL_TABLE_SIZE;
    }

void insert(char* name, hack_addr addr){
	struct Symbol *item = (struct Symbol*) malloc(sizeof(struct Symbol));
	item->addr = addr;
	item->name = name;

	//get the hash
	int hashIndex = hash(name);

	//move in array until an empty or deleted cell
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {
		//go to next cell
		++hashIndex;

		//wrap around table
		hashIndex %= SYMBOL_TABLE_SIZE;
	}

	hashArray[hashIndex] = item;
}

struct Symbol *find(char * name) {
	//get the hash
	int hashIndex = hash(name);

	//move in array until and empty
	while(hashArray[hashIndex] != NULL) {

		if(hashArray[hashIndex]->name == name) 
			return hashArray[hashIndex];

		//go to next cell
			++hashIndex;
		//wrap around the table
			hashIndex %= SYMBOL_TABLE_SIZE;
	}
		return NULL;
}

void display_table() {
	int i = 0;

	for(i = 0; i < SYMBOL_TABLE_SIZE; i++) {
		
		if(hashArray[i] != NULL) {
			printf(" (%s, %d)", hashArray[i]->name, hashArray[i]->addr);
		} else {
			printf(" ~~ ");
		}
	
		printf("\n");
	}
}
