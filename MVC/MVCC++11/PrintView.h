#ifndef PRINTVIEW_H
#define PRINTVIEW_H
#include "Observer.h"
#include "ViewBase.h"
#include "PrintModel.h"
#include "ThreadBase.h"

class PrintView;

class TaskBase
{
public:
    TaskBase(void);
    virtual ~TaskBase(void);
    virtual void DoTask() = 0;
};

class PrintTask:public TaskBase
{
public:
    PrintTask(PrintView* view , PrintModel* model);
    virtual void DoTask();
private:
    PrintView* view_;
    PrintModel* model_;
};


class PrintView
        : public ViewBase, public Observer, public ThreadBase
{
public:
    PrintView(PrintModel* model);
    virtual ~PrintView(void);
    virtual void Update(ModelBase * model);
    virtual void HandleTask(TaskBase* task);
    void DoUpdate(ModelBase * model);
private:
    PrintModel *model_;
};

#endif // PRINTVIEW_H
