#ifndef __PARSER_H__
#define __PARSER_H__

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdbool.h"
#include "stdint.h"
#include "symtable.h"
#include "hack.h"

#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS
#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH -2

char *extract_label(const char *line, char* label);
char *strip(char *s);

bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);

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
    union {
        hack_addr address;
        char * label;
    };
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union a_c {
        a_instruction a_instruction;
        c_instruction c_instruction;
    } instruction;
    enum instr_type a_c;
} instruction;

void assemble(const char * file_name, instruction* instructions, int num_instructions);
opcode instruction_to_opcode(c_instruction instr);
void add_predefined_symbols();
bool parse_A_instruction(const char *line, a_instruction *instr);
void parse_C_instruction(char *line, c_instruction *instr);
int parse(FILE * file, instruction *instructions);
#endif