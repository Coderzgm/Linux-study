#include"process.h"
#include<string.h>
#include<unistd.h>

#define NUM 101//进度条总长度+1，留位置放‘0’
#define STYLE '='//进度条填充字符

void process_v1(){
    char buffer[NUM];
    memset(buffer,0,sizeof(buffer));//初始化为全0
    
    const char* lable="|/-\\";//旋转光标的四个状态
    int len=strlen(lable);

    int cut=0;
    while(cut<=100){
	//[%-100s]左对齐占100位的进度条
	//[%d%%]百分比，两个%输出一个%
	//[%c]旋转光标
	//\r回到首行覆盖
	printf("[%-100s][%d%%][%c]\r",buffer,cut,lable[cut % len]);
	fflush(stdout);

	buffer[cut]=STYLE;//进度前进一格
	cut++;
	usleep(50000); //休眠50毫秒，控制速度
    }
    printf("\n");//结束换行
}
// process.c  v2版本
void FlushProcess(double total, double current) {
    char buffer[NUM];
    memset(buffer, 0, sizeof(buffer));
    
    const char* lable = "|/-\\";
    int len = strlen(lable);
    static int cnt = 0; // 静态变量，记录旋转光标位置，函数调用间保持值

    // 计算当前进度对应的格数
    int num = (int)(current * 100 / total);
    
    // 填充进度条
    for (int i = 0; i < num; i++) {
        buffer[i] = STYLE;
    }

    // 计算百分比，保留一位小数
    double rate = current / total;

    // 打印：进度条 + 百分比 + 旋转光标
    printf("[%-100s][%.1f%%][%c]\r", buffer, rate * 100, lable[cnt % len]);
    fflush(stdout);

    cnt++;
}
