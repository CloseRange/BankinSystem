#ifndef WRITER_H
#define WRITER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "splitString.h"

class writer {
    public:
        static std::string next(std::string padding);
        static int nextI(std::string padding);
        static void log(std::string str);
        static void debugInfo();
        static std::string loadContent(std::string file);
        static std::string getContent(std::string file);
        static splitString* getContentSpecial(std::string file);
        static void setContent(std::string file, std::string data);
        static void setContent(std::string file, splitString* data);
        static bool fileExists(std::string file);
        static std::string itos(int i);
        static int stoi(std::string s);
        static std::string file;
};

#endif // WRITER_H
