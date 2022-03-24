#include "TimerManager.h"
#include <thread>
#include <iostream>

TimerManager *TimerManager::get()
{
    static TimerManager *tm = new TimerManager;
    return tm;
}

TimerManager::TimerManager()
{

}

TimerManager::~TimerManager()
{

}

void TimerManager::run()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
}

void TimerManager::test1()
{
    {
        jbt::ScopedTimer t([&](uint32_t duration){ durationResult = duration; });
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1ms);
    }
    double precision = durationResult / 0.01;
    std::cout << "precision: " << precision << '\n';
}

void TimerManager::test2()
{
    {
        jbt::ScopedTimer t([&](uint32_t duration){ durationResult = duration; });
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ms);
    }
    double precision = durationResult / 0.1;
    std::cout << "precision: " << precision << '\n';
}

void TimerManager::test3()
{
    {
        jbt::ScopedTimer t([&](uint32_t duration){ durationResult = duration; });
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);
    }
    double precision = durationResult / 1.0;
    std::cout << "precision: " << precision << '\n';
}

void TimerManager::test4()
{
    {
        jbt::ScopedTimer t([&](uint32_t duration){ durationResult = duration; });
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1s);
    }
    double precision = durationResult / 10.0;
    std::cout << "precision: " << precision << '\n';
}

void TimerManager::test5()
{
    {
        jbt::ScopedTimer t([&](uint32_t duration){ durationResult = duration; });
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10s);
    }
    double precision = durationResult / 100.0;
    std::cout << "precision: " << precision << '\n';
}

void TimerManager::test6()
{
    uint32_t count = 0;
    jbt::TriggerTimer timer([&](uint32_t timeout, jbt::TriggerTimer* timer){++count;});
    timer.start(100, true);
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    timer.stop();
    std::cout << "Precision: " << double(count) / 10.0 << '\n';
}