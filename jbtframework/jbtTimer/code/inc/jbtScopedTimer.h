#pragma once

#include <chrono>
#include <functional>

namespace jbt
{
    class ScopedTimer
    {
    public:
        ScopedTimer(std::function<void(uint32_t)> callback = ScopedTimer::default_callback);
        ~ScopedTimer();

    private:
        std::chrono::high_resolution_clock::time_point m_t0, m_t1;
        std::function<void(uint32_t)> m_fCallback;

        static void default_callback(uint32_t duration);
    };
}