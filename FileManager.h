//
// Created by tommaso on 01/12/20.
//

#ifndef EASYBANK_FILEMANAGER_H
#define EASYBANK_FILEMANAGER_H

#include <cstdio>
#include <stdexcept>
#include <vector>
#include "MethodClass.h"

class FileManager {
public:
    FileManager(const char *filename) : file_handle(std::fopen(filename, "r+")) {
        if (!file_handle) {
            throw std::runtime_error("File open Failure");
        }
    };

    ~FileManager() {
        if (file_handle) {
            if (std::fclose(file_handle)) {
                //TODO se abbiamo da fare qualcoas prima del falimento lo si scrive qui
            }
        }
    }

    void write(const std::string &str);

    char *read();

    //void close();

    bool is_open();

    std::vector<std::string> getRowFile();

    void countRowFile();


    FileManager(const FileManager &) = delete;

    FileManager &operator=(const FileManager &) = delete;

    static int numRow;

private:
    std::FILE *file_handle;

};


#endif //EASYBANK_FILEMANAGER_H
