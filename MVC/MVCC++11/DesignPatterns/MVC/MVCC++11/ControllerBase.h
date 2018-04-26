#ifndef CONTROLLERBASE_H
#define CONTROLLERBASE_H

#include "ModelBase.h"
#include "Observer.h"


class ControllerBase
{
public:
    ControllerBase(void);
    virtual ~ControllerBase(void);
    virtual void Register(ModelBase* model, Observer* observer) = 0;
};




#endif // CONTROLLERBASE_H
