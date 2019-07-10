#ifndef RENDERER_H
#define RENDERER_H

#include "entity.h"


class cmdRenderer {
    public:
        static void init(int width, int height);
        //static void draw(int x, int y, std::string s);
        //static void render();
        //static void endrender();
        static bool gameLoop();
        //static void pushEntity();
        static std::string lines[];
        static entity objects[];
        static int width, height;
};

#endif // RENDERER_H
