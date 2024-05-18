#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> todoList;

    while(true) {
        std::cout << "\n --- TODO ---\n";
        std::cout << "1. Add task\n";
        std::cout << "2. View tasks\n";
        std::cout << "3. Remove task\n";
        std::cout << "4. Exit\n";
        std:: cout << "Enter: ";

        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << "Enter task: ";
                std::string task;
                std::cin.ignore();
                std::getline(std::cin, task);
                todoList.push_back(task);
                std::cout << "Task added!\n";
                break;
            }
            case 2: {
                if (todoList.empty()) {
                    std::cout << "You have " << todoList.size() << " tasks\n";
                }
                else {
                    std::cout << "--- Tasks ---\n";
                    for (size_t i = 0; i < todoList.size(); ++i) {
                        std::cout << i + 1 << ". " << todoList[i] << "\n";
                    }
                }
                break;
            }
            case 3: {
                if (todoList.empty()) {
                    std::cout << "You have " << todoList.size() << " tasks\n";
                }
                else {
                    std::cout << "Which task should be removed?: " << todoList.size();
                    size_t taskNumber;
                    std::cin >> taskNumber;
                    if (taskNumber > 0 && taskNumber <= todoList.size()) {
                        todoList.erase(todoList.begin() + taskNumber - 1);
                    }
                    else {
                        std::cout << "Err. Invalid\n";
                    }
                }
                break;
            }
            case 4: {
                std::cout << "Exiting... \n";
                return 0; 
                break;
            }
            default: {
                std::cout << "Err. Invalid" << std::endl;
                break;
            }
        };
    };
    return 0;
}
