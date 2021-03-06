//
// Created by tommaso on 01/12/20.
//

#ifndef EASYBANK_FILEMANAGER_H
#define EASYBANK_FILEMANAGER_H

#include <cstdio>
#include <stdexcept>
#include <vector>
#include "../Utility.h"
#include <string>

class FileManager {
public:
    FileManager(const char *filename, const char *type = "a+") : file_handle(std::fopen(filename, type)) {
        if (!file_handle) {
            throw std::runtime_error("File open Failure");
        }
    };

    virtual ~FileManager() {
        if (file_handle) {
            if (std::fclose(file_handle)) {
            }
        }
    }

    void write(std::string &str, bool firstelement = false);

    char *read();

    //void close();
    bool is_open();

    std::vector<std::string> getRowFile();

    FileManager(const FileManager &) = delete;

    FileManager &operator=(const FileManager &) = delete;

private:
    std::FILE *file_handle;
    const char *filename;
};


#endif //EASYBANK_FILEMANAGER_H
