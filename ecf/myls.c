/* 
 * 2008年 12月 29日 星期一 15:13:03 CST
 * */
#include "csapp.h"

int main(int agrc, char * argv[], char * envp[])
{
	//setenv("COLUMNS","40",1);
	if(getenv("COLUMNS")==NULL)
	{
		setenv("COLUMNS","80",1);
		printf("output is 80 columns wide.\n");
	}
	else
	{
		printf("output is %s columns wide.\n",getenv("COLUMNS"));
	}
	return 0;
}
