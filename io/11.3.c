/* 2009年 05月 19日 星期二 17:14:38 CST
 ﹡子进程和父进程共享一个文件表项,子进程对文件
 * 的读,会影响到父进程中的文件描述符的所指向的
 * 文件表项的文件位置
 * */

#include "../src/csapp.h"

int main()
{
	int fd;
	char c;

	fd = open("foobar.txt",O_RDONLY,0);
	if(fork() == 0)
	{
		read(fd, &c, 1);
		printf("c = %c\n",c);
		exit(0);
	}
	wait(NULL);
	read(fd, &c , 1);
	printf("c = %c\n",c);
	exit(0);
}
