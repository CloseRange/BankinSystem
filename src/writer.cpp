#include "writer.h"

std::string writer::file = "users.txt";
std::string writer::next(std::string padding) {
    std::string r;
    std::cout << padding;
    std::cin >> r;
    return r;
}
int writer::nextI(std::string padding) {
    int r;
    std::cout << padding;
    std::cin >> r;
    return r;
}
void writer::log(std::string str) { std::cout << str << std::endl; }
bool writer::fileExists(std::string file) {
    std::ifstream f(file.c_str());
    return f.good();
}
void writer::debugInfo() {
    if(!fileExists("debugInfo.txt")) {
        log("you have no accounts registered!");
    } else {
        log(loadContent("debugInfo.txt"));
    }
}
std::string writer::itos(int i) {
    std::ostringstream s;
    s << i;
    return s.str();
}
int writer::stoi(std::string s) {
    int number;
    std::istringstream iss (s);
    iss >> number;
    if(iss.fail()) return -1;
    return number;
}


std::string writer::loadContent(std::string file) {
    std::ifstream t(file.c_str());
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    return str;
}

std::string writer::getContent(std::string file) {
    std::string content = "";
    std::string line;

    std::ifstream myfile;
    myfile.open(file.c_str());
    if (myfile) {
        while (myfile >> line) {
            if(content != "") content += '\n';
            content += line;
        }
        myfile.close();
    }
    return content;
}
splitString* writer::getContentSpecial(std::string file) {
    splitString* content = new splitString();
    std::string line;

    std::ifstream myfile;
    myfile.open(file.c_str());
    if (myfile) {
        while (myfile >> line) {
            content->push(line);
        }
        myfile.close();
    }
    // content->log();
    return content;
}
void writer::setContent(std::string file, std::string data) {
    std::ofstream myfile;
    myfile.open(file.c_str());
    myfile << data;
    myfile.close();
}
void writer::setContent(std::string file, splitString* ss) {
    std::ofstream myfile;
    myfile.open(file.c_str());
    bool first = false;
    for(std::string n = ss->start(); n != ""; n = ss->next()) {
        if(first) myfile << '\n';
        first = true;
        myfile << n;
    }
    myfile.close();
}
