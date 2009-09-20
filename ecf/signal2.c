/*
 * 2008年 12月 09日 星期二 19:30:41 CST
 * */

#include "csapp.h"

void handler1(int sig)
{
	pid_t pid;

	/*
	 * 由于前面signal1会出现无法处理阻塞，信号不排队等现象
	 * 现在通过修改SIGCHLD处理程序，使得每次调用SIGCHLD处理
	 * 程序时，回收尽可能多的僵死子进程。
	 * waitpid 如果成功返回子进程的PID
	 * 第一参数为－1表示等待集合是由父进程所有的子进程组成
	 * 第三参数为0表示waitpdi挂起调用进程的执行，直到等待集合
	 * （即第一参数）中的一个子进程终止。
	 * */
	while((pid = waitpid(-1,NULL,0)) > 0)
	{
		printf("handler reaped child %d \n",(int)pid);
	}
	if(errno != ECHILD)
		fprintf(stderr,"waitpid error!");
	sleep(2);
	return;
}

int main()
{
	int i, n;
	char buf[MAXBUF];
	if(signal(SIGCHLD,handler1) == SIG_ERR)
	{
		fprintf(stderr,"signal error!");
	}

	for(i =0; i<3; i++)
	{
		if(fork() == 0)
		{
			printf("hello from child %d\n",(int)getpid());
			sleep(1);
			exit(0);
		}
	}

	if((n=read(STDIN_FILENO,buf,sizeof(buf))) < 0)
		fprintf(stderr,"read");

	printf("parent processing input\n");
	exit(0);
}
