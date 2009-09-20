/*
 * 2008年 12月 07日 星期日 21:37:30 CST
 * */

#include "csapp.h"

void handler(int sig)
{
	static int beeps = 0;
	printf("beep\n");
	if(++beeps <5)
		alarm(1);
	else
	{
		printf("boom\n");
		exit(0);
	}
}

int main()
{
	signal(SIGALRM,handler);
	alarm(1);
	while(1)
	{
		;
	}
	exit(0);
}
