#include "task_manager.hpp"
#include <iostream>

void TaskManager::add_task(const std::string &task) {
    tasks_.push_back(task);
}

void TaskManager::remove_task(int index) {
    if (index < 0 || index >= tasks_.size()) {
        std::cout << "Invalid task index.\n";
        return;
    }
    tasks_.erase(tasks_.begin() + index);
}

void TaskManager::list_tasks() const {
    for (int i = 0; i < tasks_.size(); ++i) {
        std::cout << i << ": " << tasks_[i] << "\n";
    }
}
