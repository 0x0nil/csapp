/* 2009年 05月 20日 星期三 15:24:19 CST
 * 这是一个使用了带缓冲区的io 操作的例子
 * 把要读的字符都放到缓冲区,以便下次读的时候不用
 * 在进行系统调用
 **/
#include "../src/csapp.h"
#define MAXBUF 10
int main(int argc, char ** argv)
{
	int n;
	rio_t rio;
	char buf[MAXBUF];
	printf("%d\n",MAXBUF);

	rio_readinitb(&rio, STDIN_FILENO);
	while((n = rio_readnb(&rio, buf, MAXBUF)) != 0)
	{
		rio_writen(STDOUT_FILENO, buf, n);
	}
	return 0;
}
