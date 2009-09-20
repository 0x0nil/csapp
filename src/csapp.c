/*
 * 2008年 12月 10日 星期三 10:49:17 CST
 * */

#include "csapp.h"

handler_t *Signal(int signum, handler_t *handler)
{
	struct sigaction action,old_action;

	action.sa_handler =handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags= SA_RESTART;
	if(sigaction(signum,&action,&old_action) < 0)
		fprintf(stderr,"Signal error");
	return (old_action.sa_handler);
}

/****************************************
 * The Rio package-robust I/O functions *
 ****************************************
 */
/*
 * rio_readn-robustly read n bytes(unbuffered)
 * */
/* 对read 的返回信息做相应的处理使得这个函数可以一直读
 * 直到读到要求的字节数或者发生错误,而且它可以处理read 函数
 * 被中断后的重启.
 * */
ssize_t rio_readn(int fd,void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread;
	char *bufp = usrbuf;

	while(nleft > 0)
	{
		if((nread = read(fd, bufp, nleft)) < 0)
		{
			if(errno == EINTR)
				nread = 0;
			else
				return -1;
		}
		else if(nread == 0)
			break;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}

/*
 * rio_write-robustly write n bytes(unbuffered)
 * */
ssize_t rio_writen(int fd, void * usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nwritten;
	char *bufp = usrbuf;

	while(nleft > 0)
	{
		if((nwritten = write(fd, bufp, nleft)) <= 0)
		{
			if(errno == EINTR)
				nwritten = 0;
			else
				return -1;
		}
		nleft -= nwritten;
		bufp += nwritten;
	}
	return n;
}

/* 
 * rio_readinitb
 * */
void rio_readinitb(rio_t *rp, int fd)
{
	rp->rio_fd = fd;
	rp->rio_cnt = 0;
	rp->rio_bufptr = rp->rio_buf;
}

/*
 * rio_read
 * */
/* 带缓冲区的read 函数,把内容尽可能多的读到rio_buf 中,
 * 用rio_cnt 来标记缓冲区中还未读出的字节数。
 * 用rio_bufptr 来表示缓冲区的首指针
 * 当再次调用rio_read 时就从缓冲区中读字节
 * */
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
	int cnt;

	while(rp->rio_cnt <= 0)
	{
		rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));

		if(rp->rio_cnt < 0)
		{
			if(errno == EINTR)
				return -1;
		}
		else if (rp->rio_cnt == 0)
			return 0;
		else
			rp->rio_bufptr = rp->rio_buf;
	}

	cnt = n;
	if(rp->rio_cnt < n)
		cnt = rp->rio_cnt;
	memcpy(usrbuf,rp->rio_bufptr,cnt);
	rp->rio_bufptr += cnt;
	rp->rio_cnt -= cnt;
	return cnt;
}

/*
 * rio_ readlineb
 * */
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
	int n, rc;
	char c, *bufp = usrbuf;

	for(n = 1; n < maxlen; n++)
	{
		if((rc = rio_read(rp, &c, 1)) == 1)
		{
			*bufp++ = c;
			if(c == '\n')
				break;
		}
		else if (rc == 0)
		{
			if(n == 1)
				return 0;
			else
				break;
		}
		else
			return -1;
	}
	*bufp = 0;
	return n;
}

/*
 * rio_readnb
 * */
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread;
	char *bufp = usrbuf;

	while(nleft > 0)
	{
		if((nread = rio_read(rp, bufp, nleft)) < 0)
		{
			if(errno == EINTR)
				nread = 0;
			else
				return -1;
		}
		else if ( nread == 0)
			break;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}
