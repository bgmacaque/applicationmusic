#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include <fstream>
/*!
 * \class FileReader filereader.h
 * \author Vincent ALBERT, Théo GERRIET, Adonis NAJIMI, Valentin STERN
 * \version 1.0
 * \date 07 december 2012
 * \brief This class provide the read of a file to parse it
 */
class FileReader
{
private:
    std::ifstream m_file;
    std::string m_current;
public:
    FileReader(const char *path);
    ~FileReader();
    /*!
     * \brief Get the next string
     */
    std::string next();

    /*!
     * \brief Get the current string
     */
    std::string getCurrent();

    /*!
     * \brief Indicate if the string is a JSON string or not
     */
    bool isNotJsonString(std::string s);
};

#endif // FILEREADER_H
