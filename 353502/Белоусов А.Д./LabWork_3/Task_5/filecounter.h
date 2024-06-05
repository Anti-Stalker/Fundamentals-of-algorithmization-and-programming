#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <cstdint>
#include <string>
#include <filesystem>

class FileCounter
{
public:
    FileCounter();
    static int64_t fileCount(const std::string& path);
};

#endif // FILECOUNTER_H
