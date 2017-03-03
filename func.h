#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//进程池的数据结构
typedef struct childdata
{
	pid_t pid;
	int fdw;
	short busy;//标示子进程是否忙碌
}cdata,*pcdata;

void make_child(pcdata,int);
void set_init(int,char*,char*);
