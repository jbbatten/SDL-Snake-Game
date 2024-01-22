#include "SDL_render.h"

#ifndef IDRAWABLE
#define IDRAWABLE

class IDrawable {
public:
    virtual void Draw(SDL_Renderer *renderer) = 0;
};

#endif
