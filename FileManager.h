//
// Created by tommaso on 01/12/20.
//

#ifndef EASYBANK_FILEMANAGER_H
#define EASYBANK_FILEMANAGER_H

#include <cstdio>
#include <stdexcept>

class FileManager {
public:
    FileManager(const char *filename) : file_handle(std::fopen(filename, "r+")) {
        if (!file_handle) {
            throw std::runtime_error("File open Failure");
        }
    };

    ~FileManager() {
        if (std::fclose(file_handle)) {
            //TODO se abbiamo da fare qualcoas prima del falimento lo si scrive qui
        }
    }

    void write(const char *str);

    const char *read();

    void close();

    bool is_open();

    FileManager(const FileManager &) = delete;

    FileManager &operator=(const FileManager &) = delete;

private:
    std::FILE *file_handle;

};


#endif //EASYBANK_FILEMANAGER_H
