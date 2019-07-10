#ifndef BANKSTRUCTURE_H
#define BANKSTRUCTURE_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <iostream>

#include "card.h"
#include "cardHandler.h"
#include "writer.h"
#include "splitString.h"

class bankStructure {
    public:
        const static int ID_LENGTH;
        int members;

        bankStructure(int initalNumberOfUsers);
        splitString* randomize(int r);
        class node;
        bankStructure::node* getAvailableNode();
        bankStructure::node* findNode(std::string id);
        card* addAccount(std::string name, int pin);
        card* isValid(std::string id_, int pin_);
        card* isValid(std::string id_);
        splitString* savedData;
        void save();
        void log();
    private:
        node* head;
        node* tailHead;
        node* tailTail;
};


class bankStructure::node {
    public:
            bool isTail;
            bool pathAvailable;
            card* data;
            node* branches[10];
            node* upper;
            std::string id;
            int idN;
            void layerDown(int i, std::string cid, int cidN, bankStructure* coreBank);
            void setData(card* d);
            node* findNode(splitString* ss);
            node* next;
            std::string save();
};

#endif // BANKSTRUCTURE_H
