#include "ThreadBase.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>

ThreadBase::ThreadBase()
    :runflag_(false)
{
   // thread_ = new std::thread()
    thread_ = NULL;
    sem_init(&sem_, 0, 10);

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

bool ThreadBase::PostTaskThread(TaskBase * task)
{
    sem_wait(&sem_);
    cs_.lock();
    taskqueue_.push(task);
    cs_.unlock();
    return false;
}

void ThreadBase::ThreadProc(void *pdata)
{
    ThreadBase* threadbase = (ThreadBase*)pdata;
    threadbase->runflag_ = true;
    while(threadbase->runflag_)
    {
        threadbase->cs_.lock();
        if(!threadbase->taskqueue_.size())
        {
            //std::cout<<"no task!"<<std::endl;
            threadbase->cs_.unlock();
            usleep(1000*1000);
            continue;
        }
        TaskBase* task = threadbase->taskqueue_.front();
        threadbase->taskqueue_.pop();
        threadbase->cs_.unlock();

        std::cout<<"doing task!"<<std::endl;

        sem_post(&threadbase->sem_);
        threadbase->HandleTask(task);

        //执行线程


        delete task;




    }

}



