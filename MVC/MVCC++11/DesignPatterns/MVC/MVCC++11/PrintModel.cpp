#include "PrintModel.h"

PrintModel::PrintModel()
{
}

PrintModel::~PrintModel(void)
{
}

void PrintModel::Attach(Observer * observer)
{
    observerlist_.push_front(observer);
}

void PrintModel::Detach(Observer * observer)
{
    observerlist_.remove(observer);
}

void PrintModel::Notify()
{
    std::list<Observer*>::iterator it = observerlist_.begin();
    while (it != observerlist_.end())
    {
        (*it)->Update(this);
        ++it;
    }
    std::cout <<"finish!"<<std::endl;
    return;
}

void PrintModel::GetPrintString(std::string& str)
{
    str = printstring_;
}

void PrintModel::SetPrintString(const std::string& str)
{
    printstring_ = str;
}
