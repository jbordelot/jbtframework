#pragma once

#include <string>
#include <functional>
#include <thread>

namespace jbt
{
    class TriggerTimer
    {
    public:
        TriggerTimer(std::function<void(uint32_t, TriggerTimer*)> fCallback = TriggerTimer::default_callback, std::string name = "");
        ~TriggerTimer();

        void start(uint32_t, bool isPeriodic = false);
        void stop();

        std::string getName();  

        static void default_callback(uint32_t, TriggerTimer*);


    private:
        std::string m_name;

        std::function<void(uint32_t, TriggerTimer*)> m_fCallback;

        static uint32_t s_nbTimer;

        std::thread *m_thread = nullptr;
        std::thread *m_callbackThread = nullptr;

        bool m_bCancel = true;
        bool m_bIsPeriodic = false;
        bool m_bIsActive = false;

        uint32_t m_time;

        void timer_handler();
    };
}