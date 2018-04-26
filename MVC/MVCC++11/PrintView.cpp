#include "PrintView.h"

/* class TaskBase start*/
TaskBase::TaskBase(void)
{
    //printf("%s %s %d\n",__FILE__, __FUNCTION__, __LINE__);
}

TaskBase::~TaskBase(void)
{
    //printf("%s %s %d\n",__FILE__, __FUNCTION__, __LINE__);
}

/* class TaskBase end*/


/* class PrintTask start*/
PrintTask::PrintTask(PrintView* view, PrintModel* model , std::string taskname)
    :view_(view), model_(model),TaskName_(taskname)
{

    //printf("%s %s %d\n",__FILE__, __FUNCTION__, __LINE__);

}
  PrintTask::~PrintTask()
  {
      //printf("%s %s %d\n",__FILE__, __FUNCTION__, __LINE__);

  }

void PrintTask::DoTask()
{
    view_->DoUpdate(model_);
    std::cout << "do task:"<<this->GetTaskName()<<std::endl;
    return;
}

std::string PrintTask::GetTaskName()
{
    return TaskName_;
}

void PrintTask::SetTaskName(std::string &taskname)
{
    TaskName_ = taskname;
}

/* class PrintTask end*/

PrintView::PrintView(PrintModel *model)
    :model_(model)
{
   // printf("%s %s %d\n",__FILE__, __FUNCTION__, __LINE__);
}


PrintView::~PrintView()
{
   // printf("%s %s %d\n",__FILE__, __FUNCTION__, __LINE__);

}

void PrintView::HandleTask(TaskBase* task)
{
    TaskBase* printtask =task;
    printtask->DoTask();
}

void PrintView::Update(ModelBase* model)
{
    if(model_ == model)
    {

        TaskBase *task = new PrintTask(this, model_, model_->GetPrintString());
        if (task != NULL)
        {
            PostTaskThread(task);
        }else{
            printf("%s %s %d: can't not alloc mem!\n",__FILE__, __FUNCTION__, __LINE__);
        }
    }
    return;
}

void PrintView::DoUpdate(ModelBase* model)
{
    if(model_ == model)
    {

    }
}


