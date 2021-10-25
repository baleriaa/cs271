#include "parser.h"

void parse (FILE * file)
{
	
}

char line[strlen(s)];

while(fgets(line, sizeof(line), fin))
{
       strip(line);
	if (line == NULL)
	{
		continue;
	}
	else
	{
		printf("%s\n", line);
	}
	printf(line);	
}

char *strip(char *s)
{
	char s_new[s + 1];
	int i = 0;
	for (char *s2 = s; *s2; s2++)
       {
   		if (*s2 && *(s+1) == "/")
		{
			break;
		}
		else if (!= isspace(*s2))
		{
			s_new[i++] = *s2;	
		}
       }
	s_new[i] = '\0';
	stpcpy(s, s_new);
	return s;

}
