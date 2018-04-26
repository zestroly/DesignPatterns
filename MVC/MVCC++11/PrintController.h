#ifndef PRINTCONTROLLER_H
#define PRINTCONTROLLER_H

#include "PrintModel.h"
#include "ControllerBase.h"
#include <iostream>

class PrintController: public ControllerBase
{
public:
    PrintController(PrintModel *model);
    virtual ~PrintController(void);
    virtual void Register(ModelBase *model , Observer* observer);
    void HandleUserInput(const std::string inputstr);
private:
    PrintModel* model_;
};

#endif // PRINTCONTROLLER_H
