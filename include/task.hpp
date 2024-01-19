#pragma once

#include <string>

class Task {
private:
    std::string name;
    std::string description;

public:
    Task(std::string name, std::string description);
    std::string getName();
    std::string getDescription();
    std::string getInfo();
};
