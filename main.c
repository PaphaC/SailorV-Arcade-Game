#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "structures.h"
#ifdef __MINGW32__
#undef main
#endif

Evenement Event();
void affichage_joueur(SDL_Surface *ecran, Personnage joueur, taille *tai);
void animation(Animation *anim);
void initAnim (Animation *anim);
void camera(SDL_Rect *position,Evenement key, Personnage *joueur1, taille* tai);

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *background = IMG_Load("background.png");
    SDL_Surface *minakoface = IMG_Load("minakonormal.jpg");
    SDL_Surface *lifebar = IMG_Load("lifebar.png");
    SDL_Rect position;
    Evenement key;
    Personnage joueur1;
    SDL_Rect posbar;
    taille tai;
    key.quit=0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_WM_SetCaption("Esoteric", NULL);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

	Mix_Music *musique=Mix_LoadMUS("ROUTE_VENUS.MID");
    Mix_PlayMusic(musique, -1);

    ecran = SDL_SetVideoMode(320, 240, 24,  SDL_DOUBLEBUF);

    joueur1.image= IMG_Load("sailor.png");
    joueur1.position.x=50;
    joueur1.position.y=105;

    initAnim(&joueur1.anim);
    joueur1.anim.n[0]=1;
    joueur1.anim.n[1]=12;
    joueur1.anim.n[2]=8;
    joueur1.anim.n[3]=12;
    joueur1.anim.n[4]=10;
    joueur1.anim.c=2;


    tai.x=50;
    tai.y=105;

    SDL_Rect p;
    posbar.x=33;
    posbar.y=5;

    while(key.quit==0)
    {
        key=Event();
        joueur1.anim.o=0;

        if(key.touche[SDLK_ESCAPE]==1)
            key.quit=1;
        camera(&position,key,&joueur1,&tai);
        p=position;

        SDL_BlitSurface(background,NULL,ecran,&p);
        SDL_BlitSurface(minakoface,NULL,ecran,NULL);
        SDL_BlitSurface(lifebar,NULL,ecran,&posbar);

        affichage_joueur(ecran,joueur1, &tai);

        SDL_Flip(ecran);
        animation(&joueur1.anim);

        SDL_Delay(33);
    }
    return 0;
}
