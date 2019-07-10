#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"


class player: public entity {
    public:
        player(int x, int y);
        void draw(string* render_target);
    protected:

    private:
};

#endif // PLAYER_H
