
#include "task.hpp"
#include "tasklist.hpp"
#include <iostream>

TaskList::TaskList() : len(0), head(new TaskNode) {};

TaskList::~TaskList() {
    TaskNode *rem  = nullptr;
    TaskNode *node = head;

    while(node != nullptr) {
        rem  = node;
        node = node->next;

        delete rem->task;
        delete rem;
    }
}

int TaskList::length() { return len; }

void TaskList::displayList() {
    int counter = 0;
    TaskNode *node = head->next;

    while(node != nullptr) {
        Task *task = node->task;
        std::cout << "(" << counter << ") " << task->getInfo() << "\n";

        counter++;
        node = node->next;
    }
}

bool TaskList::addToList(std::string name, std::string description) {
    Task *task = new (std::nothrow) Task(name, description);
    if(task == nullptr) return false;

    TaskNode *newNode = new (std::nothrow) TaskNode(task);
    if(newNode == nullptr) return false;

    TaskNode *node = head;
    while(node->next != nullptr)
        node = node->next;

    len++;
    node->next = newNode;
    return true;
}

bool TaskList::checkFromList(int index) {
    if(index < 0 || index >= len) return false;

    int counter = 0;
    TaskNode *prev = head;
    TaskNode *node = head->next;

    while(node != nullptr && counter < index) {
        prev = node;
        node = node->next;

        counter++;
    }

    prev->next = node->next;

    delete node->task;
    delete node;

    len--;
    return true;
}

void TaskList::saveToFile(std::ofstream &file) {
    TaskNode *node = head->next;

    while(node != nullptr) {
        Task *task = node->task;
        file << task->getName() << "\n" << task->getDescription() << "\n";

        node = node->next;
    }
}
