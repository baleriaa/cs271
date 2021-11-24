#include "parser.h"
#include "error.h"
#include "symtable.h"

void parse (FILE * file){
	char line[MAX_LINE_LENGTH] = "";
	unsigned int line_num = 0;
	unsigned int instr_num = 0;
	while(fgets(line, sizeof(line), file)){
		++line_num;
		if (instr_num > MAX_INSTRUCTIONS){
			exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS + 1);
		}
       strip(line);
		if (*line == '\0'){
			continue;
		}
		else if (is_Atype(line)){
			char inst_type = 'A';
			printf("%c  %s\n", inst_type, line);
		}
		else if (is_label(line)){
			char line_type = 'L';
			char label[MAX_LABEL_LENGTH + 1] = "";
			extract_label(line, label);
			if (!isalpha(label[0])){
				exit_program(EXIT_INVALID_LABEL, line_num, line);
			}
			if (symtable_find(label) == NULL){
				exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
			}
			else {
				symtable_insert(line, instr_num);
			}
			continue;
			printf("%c  %s\n", line_type, label);
		}
		else if (is_Ctype(line)){
			char c_type = 'C';
			printf("%c  %s\n", c_type, line);
		}
		++instr_num;
	}	
}
 
char *strip(char *s){
	char s_new[strlen(s) + 1];
	int i = 0;
	for (char *s2 = s; *s2; s2++){
   		if (*s2 == '/' && *(s2+1) == '/'){
			break;
		} 
		else if (!isspace(*s2)){
			s_new[i++] = *s2;	
		}
	}
	s_new[i] = '\0';
	strcpy(s, s_new);
	return s;
}
bool is_Atype(const char *line){
	return *line == '@';
}
bool is_label(const char *line){
	return *line == '(' && strlen(line)-1;
}
bool is_Ctype(const char *line){
	return !is_label(line) && !is_label(line);
}

char *extract_label(const char *line, char* label){
	int i = 0;
	for (const char *line2 = line; *line2; line2++){
		if (*line2 == '(' || *line2 == ')'){
			continue;
		}
		else {
			label[i++] = *line2;
		}
	}		
	return label;
}