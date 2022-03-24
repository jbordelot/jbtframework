#include "jbtTriggerTimer.h"
#include <sstream>
#include <iostream>
#include <cstring>
#include <unistd.h>

namespace jbt
{
    uint32_t TriggerTimer::s_nbTimer = 0;

    TriggerTimer::TriggerTimer(std::function<void(uint32_t, TriggerTimer*)> fCallback, std::string name)
        : m_fCallback(fCallback)
    {
        std::stringstream ss;
        if(name.empty())
        {
            ss << "Timer " << s_nbTimer;
        }
        else
        {
            ss << name;
        }
        m_name = ss.str();
        ++s_nbTimer;
    }

    TriggerTimer::~TriggerTimer()
    {
        stop();
        (*m_thread).join();
    }

    void TriggerTimer::start(uint32_t time, bool isPeriodic)
    {
        m_bIsPeriodic = isPeriodic;
        m_time = time;
        m_thread = new std::thread(&TriggerTimer::timer_handler, this);
        m_bCancel = false;
    }

    void TriggerTimer::stop()
    {
        m_bCancel = true;
    }

    std::string TriggerTimer::getName()
    {
        return m_name;
    }

    void TriggerTimer::default_callback(uint32_t timeout, TriggerTimer* sender)
    {
        std::cout << sender->getName() << " timed out after " << timeout << " ms\n";
    }

    void TriggerTimer::timer_handler()
    {
        sched_param parameter;
        parameter.sched_priority = sched_get_priority_max(SCHED_RR);
        if(pthread_setschedparam((*m_thread).native_handle(), SCHED_RR, &parameter))
        {
            std::cerr << "Error while setting sched param: " << strerror(errno) << '\n';
        }
        m_bIsActive = true;

        std::chrono::duration<int, std::milli> timeout(m_time);
        std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
        while(!m_bCancel)
        {
            std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = now - start;
            std::this_thread::sleep_for(std::chrono::duration<int, std::nano>(1));
            if(!(duration < timeout))
            {
                m_callbackThread = new std::thread(m_fCallback, duration.count() * 1000, this);
                //(*_observer).notifyTimeout(_id, duration.count() * 1000);
                pthread_setschedparam((*m_callbackThread).native_handle(), SCHED_RR, &parameter);
                if(m_bIsPeriodic)
                {
                    start = std::chrono::high_resolution_clock::now();
                }
                else
                {
                    m_bCancel = true;
                }
            }
        }
        m_bIsActive = false;
    }
}