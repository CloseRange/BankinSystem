#ifndef SPLITSTRING_H
#define SPLITSTRING_H

#include <string>
#include <iostream>
// THIS CLASS WAS CREATED BECAUSE I QUICKLY GOT TIRED OF SPLITTING STRINGS.
// THIS CLASS IS JUST A LINKED LIST SPECIFICALLY USED FOR STRINGS THAT ARE SPLIT UP...

class splitString {
    public:
        splitString(std::string base, char delim);
        splitString(std::string base);
        splitString();
        class node;
        splitString::node* head;
        splitString::node* tail;
        std::string start();
        std::string next();
        std::string get(int i);
        splitString::node* pos;
        int len;
        void push(std::string toPush);
        void log();
};
class splitString::node {
    public:
        node(std::string data);
        std::string data;
        splitString::node* next;
        std::string get(int i);
        void log();
};

#endif // SPLITSTRING_H
