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
    virtual std::string GetTaskName(){};
    virtual void SetTaskName(std::string& taskname){};
    virtual void DoTask() = 0;
};

class PrintTask:public TaskBase
{
public:
    PrintTask(PrintView* view , PrintModel* model, std::string taskname);
    ~PrintTask();
    virtual void DoTask();
    std::string GetTaskName();
    void SetTaskName(std::string& taskname);
private:
    PrintView* view_;
    PrintModel* model_;
    std::string TaskName_;
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
