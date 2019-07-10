#include "bankStructure.h"

// THE BIGGER THIS NUMBER, THE MORE PEOPLE THIS BANK CAN HOLD.
// BUT ALSO ALSO
const int bankStructure::ID_LENGTH = 6;

bankStructure::bankStructure(int initalNumberOfUsers) {
    this->head = new node();
    writer::log("... creating banking data structure ...");
    this->head->layerDown(bankStructure::ID_LENGTH, "", 0, this);
    members = 0;

    // users.txt   :   name : pin : money : id

    if(writer::fileExists(writer::file)) {
        writer::log("... fetching user data ...");
        splitString* ss = writer::getContentSpecial(writer::file);
        for(std::string n = ss->start(); n != ""; n = ss->next()) {
            //std::cout << n << std::endl;
            splitString* ns = new splitString(n, ':');
            bankStructure::node* N = findNode(ns->get(3));
            //std::cout << N->id << std::endl;
            std::string name = ns->get(0);
            card* c = new card(name, N->id, writer::stoi(ns->get(2)), writer::stoi(ns->get(1)), N->idN);
            N->setData(c);
            members++;
        }

        savedData = ss;
    } else {
        writer::log("... creating " + writer::itos(initalNumberOfUsers) + " random users ...");
        splitString* d = randomize(initalNumberOfUsers);
        writer::setContent(writer::file, d);
        savedData = d;
    }
}
card* bankStructure::isValid(std::string id_, int pin_) {
    bankStructure::node* n = findNode(id_);
    if(n == NULL || n->data == NULL) {
        writer::log("Not a valid card #");
        return NULL;
    }
    if(n->data->pin != pin_) {
        writer::log("Invalid pin");
        return NULL;
    }
    return n->data;
}
card* bankStructure::isValid(std::string id_) {
    bankStructure::node* n = findNode(id_);
    if(n == NULL || n->data == NULL) {
        writer::log("Not a valid card #");
        return NULL;
    }
    return n->data;
}
bankStructure::node* bankStructure::findNode(std::string id) {
    //std::cout << id << std::endl;
    splitString* ss = new splitString(id);
    ss->start();
    return head->findNode(ss);
}
bankStructure::node* bankStructure::node::findNode(splitString* ss) {
    if(this->isTail) return this;
    std::string d = ss->pos->data;
    int j = (int) d.at(0);
    if(!(j >= 48 && j <= 57)) return NULL;
    int i = writer::stoi(d);
    ss->next();
    //std::cout << "CRAPPPP  " << d << "-" << std::endl;
    return this->branches[i]->findNode(ss);
}
bankStructure::node* bankStructure::getAvailableNode() {
    srand (time(NULL));
    bankStructure::node* point = head;
    while(!point->isTail) {
        bool avail = false;
        int i=0;
        while(!avail) {
            i = rand() % 10;
            avail = point->branches[i]->pathAvailable;
        }
        point = point->branches[i];
    }
    return point;
}
splitString* bankStructure::randomize(int r) {
    splitString* re = new splitString();
    while(r --> 0) {
        bankStructure::node* n = getAvailableNode();
        std::string name = cardHandler::randomName();
        card* c = new card(name, n->id, rand() % 5000, rand() % 9999, n->idN);
        n->setData(c);
        members++;
        re->push(c->toString());
    }
    return re;
}

void bankStructure::node::setData(card* d) {
    if(!this->isTail) {
        bool isOpen = false;
        for(int i=0; i<10; i++) {
            if(this->branches[i]->pathAvailable) {
                    isOpen = true   ;
                    break;
            }
        }
        if(!isOpen) {
                this->pathAvailable = false;
                if(this->upper != NULL) this->upper->setData(d);
        }
    } else {
        this->data = d;
        this->pathAvailable = false;
        this->upper->setData(d);
    }
}

card* bankStructure::addAccount(std::string name, int pin) {
    bankStructure::node* n = getAvailableNode();
    card* c = new card(name, n->id, 500, pin, n->idN);
    n->setData(c);
    members++;
    savedData->push(c->toString());
    writer::setContent(writer::file, savedData);
    return c;
}
void bankStructure::save() {
    savedData = new splitString();
    node* point = tailHead;
    while(point != NULL) {
        std::string s = point->save();
        if(s != "") savedData->push(s);
        point = point->next;
    }
    writer::setContent(writer::file, savedData);
}
std::string bankStructure::node::save() {
    if(data == NULL) return "";
    return data->toString();
}

void bankStructure::node::layerDown(int i, std::string cid, int cidN, bankStructure* coreBank) {
    this->pathAvailable = true;
    this->data = NULL;
    if(i-- > 0) {
        for(int j=0; j<10; j++) {
            this->branches[j] = new node();
            //std::ostringstream str;
            //str << j;
            this->branches[j]->layerDown(i, cid+writer::itos(j), cidN*10 + j, coreBank);
            this->branches[j]->upper = this;
            this->isTail = false;
        }
    } else {
        this->isTail = true;
        this->next = NULL;
        if(coreBank->tailTail != NULL) coreBank->tailTail->next = this;
        coreBank->tailTail = this;
        if(coreBank->tailHead == NULL) coreBank->tailHead = this;
        this->id = cid;
        this->idN = cidN;
    }
}
