#ifndef CARD_H
#define CARD_H

#include <string>
#include "writer.h"

class card {
    public:
        card(std::string name, std::string id, int money, int pin, int idN);
        std::string name;
        std::string id;
        int money;
        int pin;
        int idN;
        std::string toString();
};

#endif // CARD_H
