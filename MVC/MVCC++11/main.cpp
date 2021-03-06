#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include <unistd.h>

#include "PrintController.h"
#include "PrintModel.h"
#include "PrintView.h"

int main()
{

    PrintModel model;
    PrintController controller(&model);
    PrintView view(&model);
    controller.Register(&model, &view);

    view.run();
    std::string str;
    std::default_random_engine  engine(time(nullptr));
    std::uniform_int_distribution<> dis(1, 100);
    int  waittime;
    int i = 0;
    while(1)
    {
        i++;
        waittime = 1000*dis(engine);
        usleep(waittime);
        controller.HandleUserInput(std::to_string(i));
    }

    return 0;
}

