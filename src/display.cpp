#include "task.hpp"
#include "tasklist.hpp"
#include "display.hpp"
#include <iostream>

void Display::help() {
    std::cout << "to-do list usage:\n";
    std::cout << " command       args                    description\n";
    std::cout << " -------       ----                    -----------\n";
    std::cout << "-h, --help                          | lists all commands and arguments\n";
    std::cout << "-l, --list                          | lists all of your due tasks\n";
    std::cout << "-a, --add     [name] [description]  | adds a new task to the bottom of your to-do list\n";
    std::cout << "-c, --check   [id]                  | checks out a task from your to-do list\n";
}

void Display::tasks(TaskList *taskList) {
    std::cout << "to-do list:\n";
    std::cout << "n. of tasks: " << taskList->length() << "\n";
    taskList->displayList();
}

void Display::taskAddedSuccessfully() {
    std::cout << "to-do list:\n";
    std::cout << "task added successfully to the end of the list\n";
}

void Display::taskNotAdded() {
    std::cout << "to-do list:\n";
    std::cout << "task could not be added to list\n";
}

void Display::taskCheckedOut() {
    std::cout << "to-do list:\n";
    std::cout << "task checked out of list\n";
}

void Display::taskNotFound() {
    std::cout << "to-do list:\n";
    std::cout << "task could not be found\n";
}

void Display::fileNotFound() {
    std::cout << "to-do list:\n";
    std::cout << "save file could not be open\n";
}
