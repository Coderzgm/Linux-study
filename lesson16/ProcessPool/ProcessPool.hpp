#pragma once

#include "Task.hpp"

#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

// TaskManager 负责统一管理所有任务。
// 它保存任务对象，并负责按编号随机选取某个任务执行。
class TaskManager
{
public:
    TaskManager()
    {
        // 使用当前时间作为随机种子，保证每次启动时随机值不同。
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    ~TaskManager()
    {
        for (auto task : _tasks)
        {
            delete task;
        }
        _tasks.clear();
    }

    // 注册任务：把任务对象加入管理容器。
    void Register(Task* task)
    {
        if (task != nullptr)
        {
            _tasks.push_back(task);
        }
    }

    // 返回随机任务编号。
    // 如果没有任务，则返回 -1。
    int Code() const
    {
        if (_tasks.empty())
        {
            return -1;
        }
        return std::rand() % static_cast<int>(_tasks.size());
    }

    // 按编号执行某个任务。
    void Execute(int code)
    {
        if (code < 0 || code >= static_cast<int>(_tasks.size()))
        {
            return;
        }
        _tasks[code]->Run();
    }

private:
    std::vector<Task*> _tasks;
};

// ProcessPool 是一个简化版的进程池骨架。
// 它的思路是：
// 1. 维护任务管理器；
// 2. 通过 fork() 创建多个子进程；
// 3. 每个子进程从任务池里取出任务并执行；
// 4. 父进程负责回收子进程。
class ProcessPool
{
public:
    explicit ProcessPool(size_t process_num = 1)
        : _process_num(process_num)
    {
    }

    ~ProcessPool()
    {
        Stop();
    }

    void SetProcessNum(size_t process_num)
    {
        _process_num = process_num;
    }

    size_t GetProcessNum() const
    {
        return _process_num;
    }

    void Register(Task* task)
    {
        _task_manager.Register(task);
    }

    // 启动进程池：创建指定数量的子进程。
    // 子进程内部循环执行任务，直到任务列表为空。
    void Start()
    {
        for (size_t i = 0; i < _process_num; ++i)
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                // 子进程逻辑：不断从任务池中选任务并执行。
                while (true)
                {
                    int code = _task_manager.Code();
                    if (code < 0)
                    {
                        break;
                    }
                    _task_manager.Execute(code);
                }
                std::exit(0);
            }
            else if (pid > 0)
            {
                _child_pids.push_back(pid);
            }
            else
            {
                throw std::runtime_error("fork failed");
            }
        }
    }

    // 停止进程池：等待所有子进程退出。
    void Stop()
    {
        for (pid_t pid : _child_pids)
        {
            waitpid(pid, nullptr, 0);
        }
        _child_pids.clear();
    }

private:
    size_t _process_num = 1;
    TaskManager _task_manager;
    std::vector<pid_t> _child_pids;
};
