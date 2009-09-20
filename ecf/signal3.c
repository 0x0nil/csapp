/*
 * 2008年 12月 10日 星期三 00:43:23 CST
 * */

#include "csapp.h"

void handler1(int sig)
{
	pid_t pid;

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

	/*
	 * 诸如read这样的慢速系统调用在被信号中断后，在Solaris系统上是不会
	 * 自动重启的，它们会提前返回给调用应用程序一个错误条件
	 * 而是linux中是会自动重启的
	 * 这里用while手动使read调用重启。
	 * */
	while((n=read(STDIN_FILENO,buf,sizeof(buf))) < 0)
		if(errno!= EINTR)
			fprintf(stderr,"read");

	printf("parent processing input\n");
	while(1)
		;
	exit(0);
}
