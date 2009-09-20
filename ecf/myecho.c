/* 
 * 2008年 12月 06日 星期六 23:48:22 CST
 * */
#include "csapp.h"
int main(int argc,char *argv[],char *envp[])
{
	printf("command line arguments:\n");
	int i=0;
	for(i=0; argv[i]!=NULL;i++)
	{
		printf("argv[%d]: %s\n",i,argv[i]);
	}
	printf("environment variabless:\n");
	for(i=0; envp[i]!=NULL; i++)
	{
		printf("envp[%d]: %s\n",i,envp[i]);
	}
	return 0;
}
