#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdint.h"

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH -2

char *strip(char *s);
void parse(FILE * file);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);
char *extract_label(const char *line, char* label);

typedef int16_t hack_addr;
typedef int16_t opcode;

enum instr_type {
    Invalid = -1,
    A_type,
    C_type
};

typedef struct c_instruction {
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;
} c_instruction;

typedef struct a_instruction {
    union addr_label {
        hack_addr address;
        char * label;
    };
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union a_c {
        a_instruction;
        c_instruction;
    };
    enum instr_type;
} instruction;
