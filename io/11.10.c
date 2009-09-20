/* 这是一个使用了带缓冲区的io 操作的例子
 * 把要读的字符都放到缓冲区,以便下次读的时候不用
 * 在进行系统调用
 **/
#include "../src/csapp.h"

int main(int argc, char ** argv)
{
	int n;
	rio_t rio;
	char buf[MAXLINE];

	if(argc == 2)
	{
		int fd = open(argv[1], O_RDONLY, 0);
		dup2(fd, STDIN_FILENO);
	}

	rio_readinitb(&rio, STDIN_FILENO);
	while((n = rio_readlineb(&rio, buf, MAXLINE)) != 0)
	{
		rio_writen(STDOUT_FILENO, buf, n);
	}
	return 0;
}
