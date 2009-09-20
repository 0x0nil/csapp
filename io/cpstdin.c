#include "../src/csapp.h"

int main()
{
	char c;
	ssize_t n;
	while((n=read(STDIN_FILENO,&c,1)) != 0)
	{
		/*printf("n=%d\n",n);*/
		write(STDOUT_FILENO,&c,1);
	}
	exit(0);
}
