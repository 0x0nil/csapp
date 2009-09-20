/* 
 * 2008年 12月 27日 星期六 20:05:34 CST
 * */
#include "csapp.h"
int main()
{
	int x =3;
	if(fork() != 0)
		printf("x=%d\n",++x);
	printf("x=%d\n",--x);
	exit(0);
}
