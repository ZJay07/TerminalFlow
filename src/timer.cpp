#include "timer.hpp"

Timer::Timer(int work_duration, int short_break, int long_break, int cycles)
    : work_duration_(work_duration), short_break_(short_break),
      long_break_(long_break), cycles_(cycles), running_(true) {}

void Timer::start() {
    for (int i = 0; i < cycles_; ++i) {
        if (!running_) break;
        run_timer(work_duration_, "Work Session");
        if (i == cycles_ - 1) {
            run_timer(long_break_, "Long Break");
        } else {
            run_timer(short_break_, "Short Break");
        }
    }
}

void Timer::stop() {
    running_ = false;
}

void Timer::reset() {
    running_ = true;
}

void Timer::run_timer(int duration, const std::string &message) {
    std::cout << message << " starts now for " << duration << " minutes.\n";
    std::this_thread::sleep_for(std::chrono::minutes(duration));
    std::cout << message << " is over.\n";
}
