#include"func.h"

int main(int argc,char* argv[])
{
	if(argc!=4)
	{
		printf("error args");
	}
	int count=atoi(argv[3]);//创建进程的数目
	pcdata p=(pcdata)calloc(count,sizeof(cdata));//为子进程结构体申请空间
	make_child(p,count);
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	set_init(sfd,argv[1],argv[2]);
	listen(sfd,count);
	int epfd;
	epfd=epoll_create(1);
	struct epoll_event event;
	wait(NULL);//等待所有的子进程
	return 0;
}
