#ifndef CARDHANDLER_H
#define CARDHANDLER_H

#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "card.h"
#include "writer.h"
#include "bankStructure.h"

class cardHandler {
    public:
        //static bankStructure* bank;
        static std::string randomName();
        static int randomNameCount;
        static bool login();
};

#endif // CARDHANDLER_H
