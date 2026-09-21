#include<iostream>
#include<cstdio>

int main()
{
    std::cout<<"hello cout"<<std::endl;
    printf("hello printf\n");

    //向标准错误进行打印，stderr,cerr->2,显示器;
    std::cerr<<"hello cerr"<<std::endl;
    fprintf(stderr, "hello stderr\n");
    return 0;
}
