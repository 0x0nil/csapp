/*
 * 2008年 12月 29日 星期一 16:16:27 CST
 * */
#include "csapp.h"
#define N 2

int main()
{
	int status, i;
	pid_t pid;

	for(i=0; i<N; i++)
	{
		if((pid = fork()) == 0)
			exit(100+i);
	}

	while ((pid = waitpid(-1,&status,0)) >0)
	{
		if(WIFEXITED(status))
		{
			printf("child %d terminated normally with exit status=%d\n",
					pid,WEXITSTATUS(status));
		}
		else
			printf("child %d terminated abnormally\n",pid);
	}
	if(errno != ECHILD)
		fprintf(stderr,"waitpid error\n");
	exit(0);
}
