/* 2008年 12月 06日 星期六 21:41:40 CST
 * */
#include "csapp.h"

int main()
{
	int i;

	for(i=0; i<2; i++)
		fork();
	printf("hello!\n");
	exit(0);
}
/* 会输出2的2次方,即4行hello!
 * */
