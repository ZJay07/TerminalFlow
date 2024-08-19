#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <vector>
#include <string>

class TaskManager {
public:
    void add_task(const std::string &task);
    void remove_task(int index);
    void list_tasks() const;
    
private:
    std::vector<std::string> tasks_;
};

#endif // TASK_MANAGER_HPP
