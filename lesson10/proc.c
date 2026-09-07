#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	pid_t id=fork();
	if(id==0)
	{
	    int cnt=5;
	    while(cnt)
	    {
		printf("我是一个子进程，pid:%d,ppid:%d\n",getpid(),getppid());
		sleep(1);
		cnt--;
	    }
	
	    exit(0);
	}
	
    pid_t rid=wait(NULL);
    if(rid>0)
    {
	printf("wait success, rid: %d\n",rid);
    }
    return 0;
}

//void fun()
//{
//    printf("fun begin!\n");
//    _exit(4);
//    printf("fun end!f\n");
//}
//
//int main()
//{
//    fun();
//    printf("main!");
//
//    sleep(1);
//
//    exit(23);
//
//
//
//
//    return 0;
//}
