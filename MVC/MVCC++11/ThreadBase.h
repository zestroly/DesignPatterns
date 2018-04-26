#ifndef THREADBASE_H
#define THREADBASE_H
#include <queue>
#include <thread>
#include <mutex>
#include <semaphore.h>
class TaskBase;
class PrintTask;


class ThreadBase
{
public:
    ThreadBase(void);
    virtual ~ThreadBase(void);
    void run();
    void Terminate();
    bool PostTaskThread(TaskBase* task);
    virtual void HandleTask(TaskBase* task) =0;
    static void ThreadProc(void *pdata);
private:
    int threadid_;
    bool runflag_;

    std::thread* thread_;
    std::queue<TaskBase*> taskqueue_;
    std::mutex cs_;
    sem_t sem_;
};

#endif // THREADBASE_H
