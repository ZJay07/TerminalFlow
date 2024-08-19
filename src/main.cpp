#include "timer.hpp"
#include "task_manager.hpp"
#include <iostream>

int main() {
    int work_duration = 25;
    int short_break = 5;
    int long_break = 15;
    int cycles = 4;

    Timer timer(work_duration, short_break, long_break, cycles);
    TaskManager task_manager;

    while (true) {
        std::cout << "Pomodoro CLI - Choose an option:\n";
        std::cout << "1. Start Timer\n";
        std::cout << "2. Stop Timer\n";
        std::cout << "3. Add Task\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. List Tasks\n";
        std::cout << "6. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                timer.start();
                break;
            case 2:
                timer.stop();
                break;
            case 3: {
                std::string task;
                std::cin.ignore(); // To ignore the newline character left by std::cin
                std::cout << "Enter task: ";
                std::getline(std::cin, task);
                task_manager.add_task(task);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                task_manager.remove_task(index);
                break;
            }
            case 5:
                task_manager.list_tasks();
                break;
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
