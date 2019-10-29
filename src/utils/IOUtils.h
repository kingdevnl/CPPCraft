//
// Created by Jasper on 28-10-2019.
//

#ifndef MYPROJECT_IOUTILS_H
#define MYPROJECT_IOUTILS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <spdlog/spdlog.h>

namespace IOUtils {

    inline static std::vector<char> readFile(const char *fileName) {
        spdlog::info("readFile: {}", fileName);
        std::ifstream file(fileName, std::ios::ate);

        if(!file || file.bad()) {
            spdlog::critical("Failed to find file {}",fileName);
        }
        size_t size = file.tellg();
        std::vector<char> buffer(size);

        file.seekg(0);
        file.read(buffer.data(), size);
        file.close();





        return buffer;

    }
}


#endif //MYPROJECT_IOUTILS_H
