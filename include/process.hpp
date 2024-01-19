#pragma once

namespace Process {
    void args(int argc, char **argv);
    void addTask(char *n, char *d);
    void checkTask(char *arg);
    void saveToFile();
    void readFromFile();
}
