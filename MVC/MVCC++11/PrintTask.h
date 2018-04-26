#ifndef PRINTTASK_H
#define PRINTTASK_H

#include "TaskBase.h"
#include "PrintView.h"

class PrintView;
class PrintModel;

class PrintTask:public TaskBase
{
public:
    PrintTask(PrintView* view, PrintModel* model);
    virtual void DoTask();

private:
    PrintView* view_;
    PrintModel* model_;

};

#endif // PRINTTASK_H
