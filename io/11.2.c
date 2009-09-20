/* 2009年 05月 19日 星期二 17:11:35 CST
 * 这个城市打开的两个文件描述符都指向同一个文件
 * 两个文件描述符指向不同的文件表项,所以它们的
 * 文件位置(即不一样)
 * 但它们最终都是指向同一个v-node 表项的(即它们最终
 * 指向同一文件,用fd1对文件进行的修改,用fd2能读出来
 * 修改后的状态.
 * */
#include "../src/csapp.h"

int main()
{
	int fd1,fd2;
	char c;
	char a = 'h';

	fd1 = open("foobar.txt",O_RDWR,0);
	fd2 = open("foobar.txt",O_RDWR,0);
	read(fd1, &c, 1);
	read(fd2, &c, 1);
	printf("fd1 = %d,fd2 = %d\n",fd1,fd2);
	printf("c = %c\n",c);
	write(fd2, &a ,1);
	read(fd1, &c, 1);
	printf("c = %c\n",c);
	read(fd1, &c, 1);
	printf("c = %c\n",c);
	close(fd1);
	close(fd2);
	return 0;
}
