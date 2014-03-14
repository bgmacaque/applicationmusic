#include "filereader.h"

FileReader::FileReader(const char *path) : m_file(path, std::ios::in){
    if(!m_file.is_open()){
        throw "ERROR DURING OPENING";
    }
}

FileReader::~FileReader(){
    m_file.close();
}

std::string FileReader::next(){
    std::string word = "";
    m_file >> word;
    m_current = word;
    return word;
}

std::string FileReader::getCurrent(){
    return m_current;
}
