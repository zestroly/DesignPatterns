#ifndef MODELBASE_H
#define MODELBASE_H

#include "Observer.h"

class Observer;

class ModelBase
{
public:
    ModelBase();
    virtual ~ModelBase(void);
    virtual void Attach(Observer * observer)=0;
    virtual void Detach(Observer* observer)=0;
    virtual void Notify() =0;

};

#endif // MODELBASE_H
