/*
 * 2008年 12月 10日 星期三 10:49:17 CST
 * */

#include "csapp.h"

handler_t *Signal(int signum, handler_t *handler)
{
	struct sigaction action,old_action;

	action.sa_handler =handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags=SA_RESTART;

	if(sigaction(signum,&action,&old_action) < 0)
		fprintf(stderr,"Signal error");
	return (old_action.sa_handler);
}
