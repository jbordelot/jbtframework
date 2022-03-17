#include "jbtScopedTimer.h"
#include <iostream>

namespace jbt
{
    ScopedTimer::ScopedTimer(std::function<void(uint32_t)> callback)
        : m_t0(std::chrono::high_resolution_clock::now()), m_fCallback(callback)
    {}

    ScopedTimer::~ScopedTimer()
    {
        m_t1 = std::chrono::high_resolution_clock::now();
        uint32_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_t1 - m_t0).count();
        m_fCallback(duration);
    }

    void ScopedTimer::default_callback(uint32_t duration)
    {
        std::cout << "duration: " << duration << " ms\n";
    }
}