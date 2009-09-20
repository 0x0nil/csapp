/*
 * 2008年 12月 10日 星期三 10:58:01 CST
 * */
#include "csapp.h"

void handler2(int sig)
{
	pid_t pid;

	while((pid = waitpid(-1,NULL,0)) > 0)
		printf("handler reaped child %d\n",(int)pid);

	if(errno!=ECHILD)
	{
		fprintf(stderr,"waitpid error");
	}
	sleep(2);
	return;
}

int main()
{
	int i,n;
	char buf[MAXBUF];
	pid_t pid;
	/*
	 * 使用封装了sigaction的Signal，sigaction是Posix兼容系统的
	 * 可移植信号处理函数
	 * */
	Signal(SIGCHLD,handler2);

	for(i=0; i<3; i++)
	{
		pid = fork();
		if(pid == 0)
		{
			printf("hello from child %d\n",(int)getpid());
			sleep(1);
			exit(0);
		}
	}

	if((n = read(STDIN_FILENO,buf,sizeof(buf))) < 0)
		fprintf(stderr,"read error");
	while(1)
		;
	exit(0);
}
