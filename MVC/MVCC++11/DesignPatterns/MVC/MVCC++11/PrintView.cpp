#include "PrintView.h"

/* class TaskBase start*/
TaskBase::TaskBase(void)
{

}

TaskBase::~TaskBase(void)
{

}

/* class TaskBase end*/


/* class PrintTask start*/
PrintTask::PrintTask(PrintView* view, PrintModel* model )
    :view_(view), model_(model)
{


}

void PrintTask::DoTask()
{
    view_->DoUpdate(model_);
    return;
}

/* class PrintTask end*/

PrintView::PrintView(PrintModel *model)
    :model_(model)
{
}


PrintView::~PrintView()
{

}

void PrintView::HandleTask(TaskBase* task)
{
    std::cout<<"call HandleTask"<<std::endl;

    PrintTask* printtask =(PrintTask*)task;

    printtask->DoTask();

}

void PrintView::Update(ModelBase* model)
{
    if(model_ == model)
    {
        PrintTask *task = new PrintTask(this, model_);
        PostTaskThread(task);
    }
    return;
}

void PrintView::DoUpdate(ModelBase* model)
{
    if(model_ == model)
    {
        std::string str;
        model_->GetPrintString(str);
        std::cout<<str<<std::endl;
    }
}


