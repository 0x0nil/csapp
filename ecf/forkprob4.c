/* 2008年 12月 06日 星期六 22:50:29 CST
 * */
#include "csapp.h"

void doit()
{
	fork();
	fork();
	printf("hello\n");
	return;
}

int main()
{
	doit();
	printf("hello\n");
	exit(0);
}
