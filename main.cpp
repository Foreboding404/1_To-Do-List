#include <iostream>
#include <vector>
#include <string>

void printTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks yet!\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

std::string readInput() {
    std::string input;
    std::cin >> input;
    std::cin.ignore();
    return input;
}

int main() {
    std::vector<std::string> tasks;
    std::string input;
    int choice;

    int addTask    = 1;
    int removeTask = 2;
    int viewTasks  = 3;
    int quit       = 4;

    while (true) {
        std::cout << "\n--- Todo List ---\n";
        std::cout << addTask << ". Add task\n" << removeTask << ". Remove task\n"
                << viewTasks << ". View tasks\n" << quit << ". Quit\n> ";

        std::string raw = readInput();

        if (raw == "clear") {
            break;
        }

        try {
            choice = std::stoi(raw);
        } catch (...) {
            choice = -1;
        }

        if (choice == addTask) {
            std::cout << "Enter task: ";
            std::getline(std::cin, input);
            tasks.push_back(input);
        } else if (choice == removeTask) {
            printTasks(tasks);
            std::cout << "Enter task number to remove: ";
            std::string raw2 = readInput();
            try {
                choice = std::stoi(raw2);
            } catch (...) {
                choice = -1;
            }
            if (choice >= 1 && choice <= (int)tasks.size())
                tasks.erase(tasks.begin() + choice - 1);
        } else if (choice == viewTasks) {
            printTasks(tasks);
        } else if (choice == quit) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}