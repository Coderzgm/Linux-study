#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<sys/types.h>
//void GetCommand()
//
//void ParseCommand()
//
//void Execute()
//
//void PrintCommandLine()
//{
//    printf("myshell$ ")
//}
//void GetCommandLine()
//{
//    
//}
//void ExecuteCommand();

int main()
{   


    while(1)
    {
	printf("myshell$ ");
	
	char command[1024];//申请空间，保存用户输入

	fgets(command,1024,stdin);
	
	char* argv[64];

	argv[0]=strtok(command," ");

	pid_t id=fork();

	if(id<0)
	{
	    perror("fork error");
	}
	else if(id==0)
	{
	    execvp(argv[0],argv);
	}
	else
	{
	    waitpid(id,NULL,0);
	}


    }
	

//    pid_t pid =fork();
//
//    if(pid<0)
//    {
//	printf("fork error\n");
//	return 1;
//    }
//    if(pid==0)
//    {
//	printf("child running...\n");
//
//	sleep(3);
//
//	return 10;
//    }
//    int status=0;
//
//    waitpid(pid,&status,0);//我要等 PID 为 pid 的那个子进程。
//
//    printf("child finished\n");
//
//    if(WIFEXITED(status))
//    {
//	printf("exit code=%d\n",WEXITSTATUS(status));
//    }


    return 0;
}
