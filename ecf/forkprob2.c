/* 
 * 2008年 12月 27日 星期六 20:59:57 CST
 * */
#include "csapp.h"
void end(void)
{
	printf("2");
}

int main()
{
	if(fork() == 0)
		atexit(end);
	if(fork() == 0)
		printf("0");
	else
		printf("1");
	exit(0);
}
