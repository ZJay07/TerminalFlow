#include "timer.hpp"
#include <thread>
#include <csignal>
#include <iostream>

#if defined(_WIN32)
#include <windows.h>  // Include the Windows header for MessageBox
#endif

Timer::Timer(int work_duration, int short_break, int long_break, int cycles)
    : work_duration_(work_duration), short_break_(short_break),
      long_break_(long_break), cycles_(cycles), running_(true) {}

void Timer::start() {
    running_ = true;
    std::thread timer_thread(&Timer::run_timer, this, work_duration_, "Work Session");
    timer_thread.detach();  // Run timer in a separate thread
}

void Timer::stop() {
    running_ = false;
}

void Timer::reset() {
    running_ = true;
}

void Timer::run_timer(int duration, const std::string &message) {
    if (!running_) return;

    std::cout << message << " starts now for " << duration << " minutes.\n";
    std::this_thread::sleep_for(std::chrono::minutes(duration));

    if (running_) {
        std::cout << message << " is over.\n";
        
        // Bring to foreground or send a notification
        #if defined(__linux__) || defined(__APPLE__)
        std::cout << "\a"; // Terminal beep as a simple notification
        // Alternatively, you can use system notifications
        system("notify-send 'Pomodoro' 'Your session is over!'");
        #elif defined(_WIN32)
        MessageBoxA(0, "Your Pomodoro session is over!", "Flow Timer", MB_OK);
        #endif
    }
}
