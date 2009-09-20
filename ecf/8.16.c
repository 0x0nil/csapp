/*
 * 2008年 12月 29日 星期一 16:27:25 CST
 * */
#include "csapp.h"
#define N 2

int main()
{
	int status, i;
	pid_t pid;
	char *a="abc";

	for(i=0; i<N; i++)
	{
		if((pid = fork()) == 0)
		{
			*a='d';
			exit(100+i);
		}
	}

	while ((pid = waitpid(-1,&status,0)) >0)
	{
		if(WIFSIGNALED(status))
		{
			printf("child %d terminated by signal %d: segmentation\n",
					pid,WTERMSIG(status));
		}
		else if(WIFEXITED(status))
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
