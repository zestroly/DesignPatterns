#ifndef PRINTMODEL_H
#define PRINTMODEL_H

#include "ModelBase.h"
#include <iostream>
#include <list>

class PrintModel: public ModelBase
{
public:
    PrintModel();
    virtual ~PrintModel(void);
    void GetPrintString(std::string& str);
    void SetPrintString(const std::string &str);
    virtual void Attach(Observer* observer);
    virtual void Detach(Observer* observer);
    virtual void Notify();
private:
    std::list<Observer*> observerlist_;
    std::string printstring_;
};

#endif // PRINTMODEL_H
