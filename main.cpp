#include <iostream>
#include <vector>
#include <string>
#include <fstream>

const std::string FILENAME = "tasks.txt";

void saveTasks(const std::vector<std::string>& tasks) {
    std::ofstream file(FILENAME);
    for (const std::string& task : tasks) {
        file << task << "\n";
    }
}

void loadTasks(std::vector<std::string>& tasks) {
    std::ifstream file(FILENAME);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty())
            tasks.push_back(line);
    }
}

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
    // variable initialization
    //micellaneous
    std::string input;

    // choices
    int choice;
    int addTask    = 1;
    int removeTask = 2;
    int viewTasks  = 3;
    int quit       = 4;

    // colors
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string RESET   = "\033[0m";

    // load at the start
    std::vector<std::string> tasks;
    loadTasks(tasks); 

    while (true) {
        std::cout << "\n" << CYAN << "--- Todo List ---" << RESET << "\n";
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

    saveTasks(tasks);  // save when the loop exits
    return 0;
}