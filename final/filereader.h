#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include <fstream>
class FileReader
{
private:
    std::ifstream m_file;
    std::string m_current;
public:
    FileReader(const char *path);
    ~FileReader();
    std::string next();
    std::string getCurrent();
};

#endif // FILEREADER_H
