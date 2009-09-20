/* 2008年 12月 06日 星期六 21:30:26 CST
 * fork 一次调用两次返回,在父进程中返回子进程的PID
 * 在子进程中返回零,因为子进程的PID总是非零的
 * 已区别父子进程 
 * */
#include "csapp.h"

int main()
{
	pid_t pid;
	int x =1;

	pid =fork();
	if(pid ==0)
	{
		printf("child : x =%d\n",++x);
		exit(0);
	}

	printf("parent: x=%d\n",--x);
	exit(0);
}
