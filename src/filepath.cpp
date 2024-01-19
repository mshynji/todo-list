#include "filepath.hpp"
#include <limits.h>
#include <unistd.h>

std::string FilePath::getExecPath()
{
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    std::string::size_type pos = std::string(result).find_last_of("\\/");

    return std::string(result, (count > 0) ? count : 0).substr(0, pos);
}
