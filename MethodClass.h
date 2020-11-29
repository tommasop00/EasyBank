//
// Created by tommaso on 27/11/20.
//

#ifndef EASYBANK_METHODCLASS_H
#define EASYBANK_METHODCLASS_H

#include <string>
#include <vector>


inline std::vector<std::string> split(std::string &data, const char &demilimiter) {
    size_t pos = 0;
    std::vector<std::string> splitArray;

    while ((pos = data.find(' ')) != std::string::npos) {
        splitArray.push_back(data.substr(0, pos));
        data.erase(0, pos + 1); //pos + demilimiter(' ').length
    }
    splitArray.push_back(data);

    return splitArray;
}

#endif //EASYBANK_METHODCLASS_H
