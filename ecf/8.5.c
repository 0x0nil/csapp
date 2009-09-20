/* 2008年 12月 06日 星期六 23:23:44 CST
 * */
#include "csapp.h"

unsigned int snooze(unsigned int sec);
unsigned int snooze(unsigned int sec)
{
	int leftsec = sleep(sec);
	printf("slept for %d of %d sec\n",leftsec,sec);
	return 0;
}
int main()
{
	snooze(6);
	printf("hello\n");
	return 0;
}
