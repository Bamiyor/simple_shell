#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	pid_t child;
	int status;
	size_t read;
	while(1){
		char *buf;
		size_t buflen;
		char *binary_part;
		char *token;
		char *argv[70] = {NULL};
		int i = 0;

		child =fork();
	       if (child == -1){
		      perror("child process failed");
		      exit(100);


	       }
	       if (child == 0){
		       buff = malloc(1024);
		       if (buff == NULL)
		       {
			       perror("memory allocation failed");
				exit(80);
		       }
		       printf("$");
		       bufflen = strlen(buff);
		       read = getline(&buff, &bufflen, stdin);
		       if (read == -1){
			       perror("unable to read any command");
			       exit(90);
		       }
		       token = strtok(buf, " ");
		       while (token != NULL){
			       argv[i] = token;
			       token = strtok(NULL, " ");
			       i++;
		       }
				    

	       }
	}
	return (0);
}
