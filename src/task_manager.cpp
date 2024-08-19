#include "task_manager.hpp"
#include <iostream>

void TaskManager::add_task(const std::string &task) {
    tasks_.push_back(task);
}

void TaskManager::remove_task(int index) {
    if (index < 0 || index >= tasks_.size()) {
        std::cout << "Invalid task index. Please enter a valid index.\n";
        return;
    }
    tasks_.erase(tasks_.begin() + index);
    std::cout << "Task removed successfully.\n";
}

void TaskManager::list_tasks() const {
    if (tasks_.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < tasks_.size(); ++i) {
        std::cout << i << ": " << tasks_[i] << "\n";
    }
}
