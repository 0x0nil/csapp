/* 2008年 12月 06日 星期六 23:23:44 CST
 * */
#include "csapp.h"

unsigned int snooze(unsigned int secs)
{
	unsigned int rc = sleep(secs);
	printf("sleep for %u of %u secs.\n",secs-rc,secs);
	return rc;
}
void handler(int sig)
{
	return;
}
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr,"usage:%s,<secs>\n",argv[0]);
		exit(0);
	}
	if(signal(SIGINT,handler) == SIG_ERR)
		fprintf(stderr,"signal error\n");
	snooze(atoi(argv[1]));
	exit(0);
}
