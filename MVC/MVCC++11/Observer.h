#ifndef OBSERVER_H
#define OBSERVER_H

#include "ModelBase.h"
class ModelBase;

class Observer
{
public:
    Observer(void){};
    virtual ~Observer(void){};
    virtual void Update(ModelBase *model) = 0;
};

#endif // OBSERVER_H
