#pragma once

#include <jbtScopedTimer.h>

class TimerManager
{
public:
    static TimerManager *get();

    void run();

private:
    TimerManager();
    TimerManager(const TimerManager&) = delete;
    TimerManager(TimerManager&&) = delete;
    ~TimerManager();
    uint32_t durationResult;
    
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
};