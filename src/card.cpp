#include "card.h"

card::card(std::string name, std::string id, int money, int pin, int idN) {
    this->name = name;
    this->id = id;
    this->money = money;
    this->pin = pin;
    this->idN = idN;
}
std::string card::toString() {
    return name + ":" + writer::itos(pin) + ":" + writer::itos(money) + ":" + id;
}
