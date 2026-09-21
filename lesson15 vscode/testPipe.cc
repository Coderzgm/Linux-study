#include<iostream>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<cstring>
#include<cstdio>
#include<sys/types.h>

int main()
{
    // 1.创建管道
    int fds[2]={0};
    int n=pipe(fds);
    if(n<0)
    {
        std::cout<<"pipe error"<<std::endl;
        return -1;
    }
    std::cout<<"fds[0]"<<fds[0]<<std::endl;
    std::cout<<"fds[1]"<<fds[1]<<std::endl;

    // 2.创建子进程
    pid_t id=fork();
    if(id==0)
    {
        // 子进程
        close(fds[0]);
        close(fds[1]);
        char buf[1024]={0};
        read(fds[0],buf,sizeof(buf));
        std::cout<<"child process read data:"<<buf<<std::endl;
    }
    else if(id>0)
    {
        // 父进程
        close(fds[0]);
        const char* msg="hello pipe";
        write(fds[1],msg,strlen(msg));
    }
    else
    {
        std::cout<<"fork error"<<std::endl;
    }

}
