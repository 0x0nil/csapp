/*
 * 2008年 12月 07日 星期日 15:03:26 CST
 * */
#include "csapp.h"
#define MAXARGS 128

/*function prototype*/
void eval(char *cmdline);
int parseline(const char *cmdline,char **argv);
int builtin_command(char **argv);

char buf1[MAXLINE];
char *buf=buf1;
int main()
{
	char cmdline[MAXLINE];
	while(1)
	{/*red*/
		printf("> ");
		fgets(cmdline,MAXLINE,stdin);
		if(feof(stdin))
			exit(0);

		/*evaluate*/
		eval(cmdline);
	}
	return 0;
}

/* eval-evaluate a command line
 * 运行输入的命令
 * 先用命令解释函数解释命令,然后用fock创建进程
 * 再用execve加载程序
 * bg为1则在后台运行,否则在前台运行
 * */
void eval(char *cmdline)
{
	char *argv[MAXARGS];
	int bg;
	pid_t pid;
	bg = parseline(cmdline,argv);
	if(argv[0]==NULL)
		return;
	if(!builtin_command(argv))
	{
		if((pid = fork()) == 0)
		{
			if(execve(argv[0],argv,environ) < 0)
			{
				printf("%s: command not found.\n",argv[0]);
				exit(0);
			}
		}
		
		if(!bg)
		{
			int status;
			if(waitpid(pid,&status,0) < 0)
				printf("waitfg:waitpid error");
		}
		else
			printf("%d %s ",pid,cmdline);
	}
	return;
}
/* 判断命令是否是内部命令
 * 内部命令返回1,否则返回0
 * */
int builtin_command(char **argv)
{
	if(!strcmp(argv[0],"quit"))
			exit(0);
	if(!strcmp(argv[0],"&"))
		return 1;
	return 0;
}

/* parseline-parse the command line an build the argv array 
 * 翻译命令,把cmdline中的命令格式化到argv中
 * 方法是以空格为分界分界命令和参数
 * 非后台运行返回0
 * 后台运行返回1
 * */
int parseline(const char *cmdline, char **argv) 
{
	char *delim;
	int argc;
	int bg;
	memcpy(buf,cmdline,MAXLINE);
	buf[strlen(buf)-1] = ' ';
	while(*buf && (*buf == ' '))
		buf++;
	argc = 0;
	while((delim = strchr(buf,' ')))
	{
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while(*buf && (*buf == ' '))
			buf++;
	}
		argv[argc] = NULL;
		if(argc == 0)
			return 1;
		if((bg=(*argv[argc-1] == '&')) != 0)
			argv[--argc] = NULL;

		return bg;
}
