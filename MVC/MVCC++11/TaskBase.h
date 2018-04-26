#ifndef TASKBASE_H
#define TASKBASE_H

class TaskBase
{
public:
    TaskBase(void){};
    virtual ~TaskBase(void){};

    virtual void DoTask() = 0;
};




#endif // TASKBASE_H
