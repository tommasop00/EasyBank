//
// Created by tommaso on 27/11/20.
//

#ifndef EASYBANK_METHODCLASS_H
#define EASYBANK_METHODCLASS_H

#include <string>
#include <vector>


inline std::vector<std::string> split(std::string &data, const char demilimiter, int elem = 1) {
    size_t pos = 0;
    std::vector<std::string> splitArray;

    int count = 0;
    while ((pos = data.find(demilimiter)) != std::string::npos && ((elem == 1) ? true : (count < elem - 1))) {
        splitArray.push_back(data.substr(0, pos));
        data.erase(0, pos + 1);
        count++;
    }


    splitArray.push_back(data);

    return splitArray;
}

#endif //EASYBANK_METHODCLASS_H
