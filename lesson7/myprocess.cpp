#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
    try {
        pid_t _id = fork();

        if (_id < 0) {
            throw string("fork 创建进程失败");
        }
        else if (_id == 0) {
            // 子进程逻辑
            cout << "我是子进程！我的pid: " << getpid() 
                 << "，父进程id: " << getppid() << endl;
        }
        else {
            // 父进程逻辑
            cout << "我是父进程！我的pid: " << getpid() 
                 << "，子进程id: " << _id << endl;
        }
    }
    // 修正：const 左值引用捕获字符串异常
    catch (const string& str)
    {
        cout << str << endl;
    }

    return 0;
}


//int main()
//{
//    while(1)
//    {
//	sleep(1);
//	printf("我是一个进程！，我的pid：%d\n,我的父进程id：%d\n",getpid(),getppid());
//    }
//}

