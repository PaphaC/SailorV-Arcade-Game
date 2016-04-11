#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "structures.h"
#ifdef __MINGW32__
#undef main
#endif

Evenement Event()
{
    SDL_Event event;
    Evenement key;
    int i=0;
    key.quit=0;

    for(i=0;i<300;i++)
    {
        key.touche[i]=0;
    }

    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            key.quit=1;
        break;
        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button)
            {
                case SDL_BUTTON_RIGHT:
                    exit(0);
                break;
            }
        break;
        case SDL_KEYDOWN:
            for(i=0;i<300;i++)
            {
                if(event.key.keysym.sym==i)
                    key.touche[i]=1;
            }
        break;
    }
    return key;
}
