#include "../src/csapp.h"

int main( int argc, char **argv)
{
	struct stat s;
	char *type, *readok;

	int fd = atoi(argv[1]);
	fstat(fd,&s);
	if(S_ISREG(s.st_mode))
		type = "regular";
	else if(S_ISDIR(s.st_mode))
		type = "directory";
	else
		type = "other";
	
	if((s.st_mode & S_IRUSR))
		readok = "yes";
	else
		readok = "no";

	printf("type:%s,read:%s\n",type,readok);
	return 0;
}
