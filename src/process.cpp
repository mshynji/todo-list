#include "task.hpp"
#include "tasklist.hpp"
#include "display.hpp"
#include "process.hpp"
#include "filepath.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

TaskList *taskList = new TaskList();

void Process::args(int argc, char **argv) {
    readFromFile();

    if(argc == 1) {
        Display::help();
    } else {
        if((strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) && argc == 2)
            Display::help();
        else if((strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) && argc == 2)
            Display::tasks(taskList);
        else if((strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "--add") == 0) && argc == 4)
            addTask(argv[2], argv[3]);
        else if((strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--check") == 0) && argc == 3)
            checkTask(argv[2]);
        else
            Display::help();
    }

    saveToFile();
    delete taskList;
}

void Process::addTask(char *n, char *d) {
    std::string name = n;
    std::string description = d;

    if(taskList->addToList(name, description))
        Display::taskAddedSuccessfully();
    else
        Display::taskNotAdded();
}

void Process::checkTask(char *arg) {
    int index = atoi(arg);

    if(taskList->checkFromList(index))
        Display::taskCheckedOut();
    else
        Display::taskNotFound();
}

void Process::saveToFile() {
    std::ofstream file(FilePath::getExecPath() + "/to-do.txt");

    if(file.is_open()) {
        taskList->saveToFile(file);
        file.close();
    }

    else Display::fileNotFound();
}

void Process::readFromFile() {
    std::ifstream file(FilePath::getExecPath() + "/to-do.txt");

    if(file.is_open()) {
        std::string name;
        std::string description;

        while(std::getline(file, name) && std::getline(file, description))
            taskList->addToList(name, description);

        file.close();
    }
}
