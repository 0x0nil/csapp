/* 
 * 2008年 12月 29日 星期一 15:01:23 CST
 * */
#include "csapp.h"

int main(int argc,char *argv[],char *envp[])
{
	int i;
	printf("command line arguments:\n");
	for(i=0; argv[i]!=NULL;i++)
		printf("	argv[%2d]: %s\n",i,argv[i]);
	printf("\n");
	printf("environment variables:\n");
	for(i=0;envp[i];i++)
		printf("	envp[%2d]: %s\n",i,envp[i]);
	exit(0);
}
