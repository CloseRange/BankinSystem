#include "cardHandler.h"

int cardHandler::randomNameCount = 0;

std::string cardHandler::randomName() {
    std::string file = "names.txt";

    if(cardHandler::randomNameCount == 0) {
        srand (time(NULL));
        cardHandler::randomNameCount = 0;
        std::string line;
        std::ifstream myfile(file.c_str());

        while (std::getline(myfile, line))
            ++cardHandler::randomNameCount;
        myfile.close();
    }

    std::string line;
    std::ifstream myfile(file.c_str());

    int i = rand() % cardHandler::randomNameCount;
    std::string content = "";
    while (std::getline(myfile, line)) {
        if(i-- == 0) {
            content = line;
            break;
        }
    }
    myfile.close();

    return content;
}

