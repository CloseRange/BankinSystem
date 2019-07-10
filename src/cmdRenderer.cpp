#include "cmdRenderer.h"
#include "entity.h"

void cmdRenderer::init(int width, int height) {
    cmdRenderer::width = width;
    cmdRenderer::height = height;
}
bool cmdRenderer::gameLoop() {
    for(entity e : cmdRenderer::objects) {
        e.draw(*cmdRenderer::lines);
    }
}
