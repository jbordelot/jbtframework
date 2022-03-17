#include <iostream>
#include "TimerManager.h"

int main(int argc, char ** argv)
{
    std::cout << *argv << " started\n";
    {
        TimerManager *tm = TimerManager::get();
        tm->run();

    }
    std::cout << *argv << " stopped\n";
    return 0;
}