#include "ThreadBase.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>

ThreadBase::ThreadBase()
    :runflag_(false)
{
    // thread_ = new std::thread()
    thread_ = NULL;
    sem_init(&sem_, 0, 2);

}

ThreadBase::~ThreadBase(void)
{
    if(thread_ != NULL)
    {
        Terminate();
        thread_->join();
        thread_ = NULL;
    }
    sem_destroy(&sem_);

}


void ThreadBase::run()
{
    runflag_ = true;
    thread_ = new std::thread(ThreadProc, (void*)this);
    return;
}


void ThreadBase::Terminate()
{
    runflag_ = false;
    return;
}

bool ThreadBase::PostTaskThread(TaskBase*  task)
{

    sem_wait(&sem_);
    cs_.lock();
    taskqueue_.push(task);
    std::cout<<"Add new task:"<<std::endl;
    cs_.unlock();
    return false;
}

void ThreadBase::ThreadProc(void *pdata)
{
    ThreadBase* threadbase = (ThreadBase*)pdata;
    threadbase->runflag_ = true;
    // 任务分配
    while(threadbase->runflag_)
    {
        threadbase->cs_.lock();
        if(threadbase->taskqueue_.empty())
        {
            threadbase->cs_.unlock();
            usleep(1000*10);
            continue;
        }
        //取出任务
        TaskBase* task = threadbase->taskqueue_.front();
        threadbase->taskqueue_.pop();
        threadbase->cs_.unlock();
        threadbase->HandleTask(task);
        delete task;
        sem_post(&threadbase->sem_);
        //执行人物
    }

}



