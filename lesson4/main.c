// main.c
#include "process.h"
#include <stdio.h>
#include <unistd.h>

double total = 1024.0; // 总大小 1024MB
double speed = 1.0;    // 下载速度 1MB/次

void DownLoad() {
    double current = 0;
    while (current <= total) {
        FlushProcess(total, current); // 更新进度条
        usleep(3000);  // 模拟下载耗时
        current += speed;
    }
    printf("\ndownload %.2fMB Done\n", current);
}

int main() {
    DownLoad();
    DownLoad();
    DownLoad();
    return 0;
}
