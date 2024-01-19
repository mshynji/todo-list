#pragma once

#include "task.hpp"
#include <string>
#include <fstream>

struct TaskNode {
    Task     *task;
    TaskNode *next;

    TaskNode() : task(nullptr), next(nullptr) {};
    TaskNode(Task *t) : task(t), next(nullptr) {};
};

class TaskList {
private:
    int len;
    TaskNode *head;

public:
    TaskList();
    ~TaskList(); 
    int length();
    void displayList();
    bool addToList(std::string name, std::string description);
    bool checkFromList(int index);
    void saveToFile(std::ofstream& file);
};
