#pragma once

// Task 是所有任务的抽象基类。
// 进程池中，每个真正的任务都必须继承它，并实现 Run()。
// 这样做的好处是：
// 1. 任务和进程池解耦；
// 2. 可以统一管理不同类型的任务；
// 3. 子进程只需要调用 Run()，不关心具体任务细节。
class Task
{
public:
    virtual ~Task() = default;

    // 任务执行入口。
    // 子进程在执行时会调用这个函数。
    virtual int Run() = 0;
};
