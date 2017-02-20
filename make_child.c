#include"func.h"
void handle_request(int fd)
{
	while(1);
}
void make_child(pcdata p,int count)//传递参数记录子进程的个数
{
	int fds[2];//定义一个管道
	int i;
	pid_t pid;//存储fork,再进行赋值
	for(i=0;i<count;i++)	
	{//循环每执行一次，初始化一条管道
		 socketpair(AF_LOCAL,SOCK_STREAM,0,fds);//fork之前先把管道初始化好	 
	     pid=fork();//fork之后必须有判断
		 if(0==pid)//子进程死循环,实现多个子进程
		{
			close(fds[1]);
			handle_request(fds[0]);//响应父进程给他的请求,传递给每一个子进程
		}
		p[i].pid=pid;//把子进程的pid赋值给父进程并存储
		p[i].fdw=fds[1];//存管道的一端
		p[i].busy=0;//先赋值，标示非忙碌
		close(fds[0]);//每次都关闭另外一端
	}
}
