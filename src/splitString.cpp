#include "splitString.h"

splitString::splitString(std::string base, char delim) {
    this->tail = NULL;
    this->head = NULL;
    std::string p = "";
    this->len = 0;

    for ( size_t i = 0 ; i < base.length(); i++) {
        std::string c(1, base[i]);
        if(base.at(i) == delim) {
            if(p != "") this->push(p);
            p = "";
            len++;
        } else p += c;
        if(i == base.length()-1) if(p != "") this->push(p);
    }
}
splitString::splitString(std::string base) {
    this->tail = NULL;
    this->head = NULL;
    std::string p = "";

    for ( unsigned int i = 0 ; i < base.length(); i++) {
        std::string c(1, base[i]);
        len++;
        push(c);
    }
}
splitString::splitString() {
    this->tail = NULL;
    this->head = NULL;
}
void splitString::push(std::string toPush) {
    splitString::node* n = new splitString::node(toPush);
    if(this->head == NULL) {
        this->head = n;
        this->tail = n;
    } else {
        this->tail->next = n;
        this->tail = n;
    }
}
std::string splitString::get(int i) {
    return this->head->get(i);
}
std::string splitString::node::get(int i) {
    if(i-- != 0) {if(next != NULL) return next->get(i); else return "";}
    return data;
}
std::string splitString::start() {
    return (this->pos = this->head)->data;
}
std::string splitString::next() {
    this->pos = this->pos->next;
    if(this->pos == NULL) return "";
    return this->pos->data;
}

splitString::node::node(std::string data) {
    this->data = data;
    this->next = NULL;
}
void splitString::log() {if(this->head != NULL) this->head->log(); }
void splitString::node::log() {
    std::cout << this->data << std::endl;
    if(this->next != NULL) this->next->log();
}
