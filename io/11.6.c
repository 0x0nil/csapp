/* 2009年 05月 20日 星期三 15:03:57 CST
 * */
#include "../src/csapp.h"

int main()
{
	int fd1,fd2;

	fd1 = open("foo.txt", O_RDONLY, 0);
	printf("fd2 = %d\n",fd1);
	fd2 = open("bar.txt", O_RDONLY, 0);
	printf("fd2 = %d\n",fd2);
	close(fd2);
	fd2 = open("baz.txt", O_RDONLY, 0);
	printf("fd2 = %d\n",fd2);
	exit(0);
}
