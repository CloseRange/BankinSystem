#include <iostream>
#include <fstream>
#include <string>

#include "writer.h"
#include "cardHandler.h"
#include "bankStructure.h"
#include "card.h"

void push(bankStructure* bank);
card* login(bankStructure* bank, std::string id);
int main() {
    bankStructure* bank = new bankStructure(1000);
    writer::log("Type your card number to login");
    writer::log("     (type 'debug' if you forgot your info)");
    writer::log("     (type 'register' to create a new card");
    std::string code;
    card* target = NULL;
    while(target == NULL) {
        std::string pad = "> ";
        if(target != NULL) pad = target->name + "> ";
        code = writer::next(pad);
        if(code == "debug") writer::debugInfo();
        else if(code == "register") push(bank);
        else {
            target = login(bank, code);
            if(target != NULL) {
                writer::log("   Name  : " + target->name);
                writer::log("   Money : " + writer::itos(target->money));
                writer::log("   Pin   : " + writer::itos(target->pin));
                writer::log("   Card #: " + target->id);
            }
        }
    }
    writer::log("     (type 'help' to get a list of commands)");
    while(true) {
        code = writer::next(target->name + "> ");
        if(code == "help") {
            writer::log("  'transfer' - transfer money from your account to another");
            writer::log("  'add' - add money into your account (for debugging) ");
            writer::log("  'relog' - log into a different account");
            writer::log("  'debug' - for when you forget your card number or pin");
            writer::log("  'details' - see your account details");
        } else if(code == "transfer") {
            std::string id = writer::next("Target account card # : ");
            int amount = writer::nextI("Amount to transfer : ");
            if(target->money <= amount) {
                    writer::log("Insufficient funds");
            } else {
                card* otherAcc = bank->isValid(id);
                if(otherAcc != NULL) {
                    target->money -= amount;
                    otherAcc->money += amount;
                    bank->save();
                }
            }
        } else if(code == "add") {
            int ad = writer::nextI("Amount : ");
            target->money += ad;
            bank->save();
        } else if(code == "relog") {
            std::string id = writer::next("Card # : ");
            target = login(bank, id);
            if(target != NULL) {
                writer::log("   Name  : " + target->name);
                writer::log("   Money : " + writer::itos(target->money));
                writer::log("   Pin   : " + writer::itos(target->pin));
                writer::log("   Card #: " + target->id);
            }
        } else if(code == "debug") {
            writer::debugInfo();
        } else if(code == "details") {
            writer::log("   Name  : " + target->name);
            writer::log("   Money : " + writer::itos(target->money));
            writer::log("   Pin   : " + writer::itos(target->pin));
            writer::log("   Card #: " + target->id);
        }
    }
    return 0;
}
card* login(bankStructure* bank, std::string id) {
    int pin = writer::nextI("Pin : ");
    return bank->isValid(id, pin);
}
void push(bankStructure* bank) {
    std::string name = "";
    while(name == "") {
        name = writer::next("Name : ");
    }
    int pin = 0;
    while(pin < 999 || pin > 10000) {
        pin = writer::nextI("Pin : ");
        if(!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore();
        } else {
            if(pin < 999 || pin > 10000) writer::log("Pin must be 4 digits and can not begin with 0");
        }
    }
    card* c = bank->addAccount(name, pin);
    std::string predata = writer::getContent("debugInfo.txt");
    if(predata != "") predata += "\n";

    //std::ostringstream str;
    //str << c->pin;


    predata += name + "\n   pin: " + writer::itos(c->pin) + "\n   acc#: " + c->id;
    writer::log("Your new card number is : " + c->id);
    writer::setContent("debugInfo.txt", predata);
}
