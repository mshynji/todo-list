#include "task.hpp"

Task::Task(std::string name, std::string description) : name(name), description(description) {};

std::string Task::getName()        { return name; }
std::string Task::getDescription() { return description; }
std::string Task::getInfo() {
    return name + ": " + description;
}
