#include "../src/csapp.h"
/* 这是打开和关闭文件的例子,O_CREAT表示如果文件不存在,就创建一个新的空文件
 * 这里不加上这个参数的话open就会返回-1
 * DEF_MODE是用来控制文件的权限的,如果改成0的话,open 也会返回-1
 * 因为open 是创建了一个文件,但它没有权限打开。
 */
int main()
{
	int fd1, fd2;

	fd1 = open("foo.txt", O_RDONLY|O_TRUNC|O_CREAT,DEF_MODE);
	printf("fd1 =%d\n",fd1);
	close(fd1);
	fd2 = open("baz.txt",O_RDONLY|O_CREAT, DEF_MODE);
	printf("fd2 = %d\n",fd2);
	close(fd2);
	exit(0);
}
