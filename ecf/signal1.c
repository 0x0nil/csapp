/*
 * 2008年 12月 09日 星期二 14:41:55 CST
 * */

#include "csapp.h"

void handler1(int sig)
{
	pid_t pid;

	if((pid = waitpid(-1,NULL,0)) < 0) /*回收已结束的子进程*/
	{
		fprintf(stderr,"waitpid error!");
	}
	printf("handler reaped child %d \n",(int)pid);
	sleep(2);		
	/* 
	 * 在这两秒內会有3个子进程结束，在这两秒内，会有3个
	 * 信号到达，它处理第一个信号，好没处理完，第二个信
	 * 号就到了，所以阻塞第二个信号，使第二信号成为待处
	 * 理信号第三西信号到达时，以为有已经有了一个待处理
	 * 信号，所以丢弃第三个信号，当第一信号处理完时，
	 * 内核看到有一个待处理信号，就通知进程处理，所以，
	 * 最终只是处理了两个信号，还有一个进程没回收。
	 * */
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

	for(i =0; i<3; i++)		/*创建3个子进程，每个进程睡眠1秒然后退出*/
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
