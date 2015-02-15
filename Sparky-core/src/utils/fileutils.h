#pragma once

#include <string>
#include <fstream>
#include <iostream>

class FileUtils
{
public:
    static std::string read_file(const char *path)
    {
        std::string result;
        std::ifstream stream(path, std::ios::in);
        if (!stream.good() || !stream.is_open())
        {
            std::cout << "Could not read file: '" << path << "'!" << std::endl;
            return NULL;
        }
        std::string line = "";
        while (!stream.eof())
        {
            std::getline(stream, line);
            result += line + "\n";
        }
        stream.close();
        return result;
    }

};