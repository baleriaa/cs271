#include "parser.h"

void parse (FILE * file){
	char line[MAX_LINE_LENGTH] = "";

	while(fgets(line, sizeof(line), file)){
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
			printf("%c  %s\n", line_type, label);
		}
		else if (is_Ctype(line)){
			char c_type = 'C';
			printf("%c  %s\n", c_type, line);
		}
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
	stpcpy(s, s_new);
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