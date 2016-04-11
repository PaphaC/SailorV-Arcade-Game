
typedef struct
{
    int touche[300];
    int quit;
}Evenement;

typedef struct
{
    int i, tmp, o;
    int n[20];
    int tmpo;
    int c;
}Animation;

typedef struct
{
    SDL_Rect position;
    SDL_Surface *image;
    int etat;
    Animation anim;
}Personnage;

typedef struct
{
    int x;
    int y;
}taille;
