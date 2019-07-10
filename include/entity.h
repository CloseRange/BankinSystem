#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class entity {
    public:
        entity();
        int x;
        int y;
        virtual void draw(std::string *render_target[]);
        protected:
    private:
};

#endif // ENTITY_H
