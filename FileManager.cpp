//
// Created by tommaso on 01/12/20.
//

#include "FileManager.h"

int FileManager::numRow = 0;

void FileManager::write(const std::string &str) {

    const char *cstr = str.c_str();
    if (EOF == std::fputs(cstr, file_handle))
        throw std::runtime_error("File Write Failure");
}

char *FileManager::read() {
    fseek(file_handle, 0L, SEEK_END);
    int size = ftell(file_handle);
    rewind(file_handle);

    char *str = new char[size + 1];
    fread(str, sizeof(char), size, file_handle);

    str[size] = '\0';

    return str;
}


/*void FileManager::close() {
    std::fclose(file_handle);
}*/

bool FileManager::is_open() {
    return file_handle;
}

std::vector<std::string> FileManager::getRowFile() {
    std::vector<std::string> tempVector;
    char *stempChar = this->read();
    std::string str(stempChar);
    tempVector = split(str, '\n');
    delete stempChar;
    return tempVector;
}

void FileManager::countRowFile() {
    int tempCount = 0;
    for (auto t : getRowFile())
        tempCount++;
    FileManager::numRow = tempCount;
}
