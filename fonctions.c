#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "structures.h"
#ifdef __MINGW32__
#undef main
#endif

void affichage_joueur(SDL_Surface *ecran, Personnage joueur,taille *tai)
{
    SDL_Rect tiles;
    tiles.x=joueur.anim.i*(tai->x);
    tiles.y=(tai->y)*joueur.anim.o;
    tiles.w=tai->x;
    tiles.h=tai->y;
    printf("%i\n%i\n",tai->x*(joueur.anim.i),tai->y*(joueur.anim.o));
    SDL_BlitSurface(joueur.image,&tiles,ecran,&joueur.position);
}

void animation(Animation *anim)
{
    anim->tmp+=1;
    if(anim->tmp > anim->c)
    {
        anim->i+=1;
        anim->tmp=0;
    }
    if(anim->i >= anim->n[anim->o])
        anim->i=0;

}

void initAnim (Animation *anim)
{
    anim->i=0;
    anim->tmp=0;
    anim->tmpo=0;
    anim->o=0;

}
void camera(SDL_Rect *position,Evenement key, Personnage *joueur1, taille *tai)
{
        if(key.touche[SDLK_RIGHT]==1)
        {
            tai->x=50;
            tai->y=105;
            joueur1->anim.o=1;
            if((joueur1->position.x)<200)
                joueur1->position.x+=2;
            if((joueur1->position.x) >=200)
                position->x-=2;
        }
        if(key.touche[SDLK_DOWN]==1)
        {
            tai->x=50;
            tai->y=105;
            joueur1->anim.o=1;
            joueur1->position.y+=2;
            position->y-=2;
        }
        if(key.touche[SDLK_UP]==1)
        {
            tai->x=50;
            tai->y=105;
            joueur1->anim.o=2;
            joueur1->position.y-=2;
            position->y+=2;
        }
        if(key.touche[SDLK_LEFT]==1)
        {
            tai->x=50;
            tai->y=105;
            joueur1->anim.o=3;
            if((joueur1->position.x)>50)
                joueur1->position.x-=2;
            if((joueur1->position.x) <=50)
                position->x+=2;
        }
        if(key.touche[SDLK_SPACE]==1)
        {
            tai->x=60;
            tai->y=150;
            joueur1->anim.o=4;
        }

        if(position->x>0)
            position->x=0;
        if(position->x<-2144)
            position->x=-2144;
        if(position->y>0)
            position->y=0;
        if(position->y<-15)
            position->y=-15;
        if(joueur1->position.y<60)
            joueur1->position.y=60;
        if(joueur1->position.y>145)
           joueur1->position.y=145;

}
