/*
 * 2008年 12月 07日 星期日 21:26:50 CST
 * */
#include "csapp.h"

int main()
{
	pid_t pid;

	if((pid=fork())==0)
	{
		pause();
		printf("control should nevet reach here!\n");
		exit(0);
	}

	kill(pid,SIGKILL);
	exit(0);
}
