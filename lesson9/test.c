#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    while(1)
    {
	sleep(1);
        printf("我是一个进程！，我的pid: %d\n", getppid()); // 获取当前进程的父进程pid
    }
 }

