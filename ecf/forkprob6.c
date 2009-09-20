/* 
 * 2008年 12月 27日 星期六 20:17:32 CST
 * */
#include "csapp.h"
void doit()
{
	if(fork() == 0)
	{
		fork();
		printf("hello\n");
		return;
	}
	return;
}

int main()
{
	doit();
	printf("hello\n");
	exit(0);
}
