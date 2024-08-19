#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <thread>
#include <iostream>

class Timer {
public:
    Timer(int work_duration, int short_break, int long_break, int cycles);
    void start();
    void stop();
    void reset();
    void run_timer(int duration, const std::string &message);
    
private:
    int work_duration_;
    int short_break_;
    int long_break_;
    int cycles_;
    bool running_;
};

#endif // TIMER_HPP
