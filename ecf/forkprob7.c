/* 
 * 2008年 12月 27日 星期六 20:27:33 CST
 * */
#include "csapp.h"

int counter = 1;
int main()
{
	if(fork() == 0)
	{
		counter--;
			exit(0);
	}
	else
	{
		wait(NULL);
		printf("counter=%d\n",++counter);
	}
	exit(0);
}
