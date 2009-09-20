/* 2008年 12月 06日 星期六 21:36:51 CST
 * */
#include "csapp.h"

int main()
{
	int x= 1;
	
	if(fork() == 0)
		printf("printf1: x=%d\n",++x);
	printf("printf2: x=%d\n",--x);
	exit(0);
}

/* 子进程输出:printf1:x=2\n printf2: x=1\n
 * 父进程输出:printf2:x=0\n
 * */
