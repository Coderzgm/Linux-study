#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("参数个数 argc = %d\n", argc);
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}

