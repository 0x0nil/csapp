/*
 * 2008年 12月 07日 星期日 21:52:51 CST
 * */
#include "csapp.h"

void handler(int sig)
{
	printf("caught sigint\n");
	exit(0);
}

int main()
{
	if(signal(SIGINT,handler) == SIG_ERR)
	{
		printf("signal error");
	}
	pause();
	exit(0);
}
