#include "PrintTask.h"

PrintTask::PrintTask(PrintView* view, PrintModel* model)
    :view_(view), model_(model)
{
}


void PrintTask::DoTask()
{
    view_->DoUpdate(model_);
    return;
}

