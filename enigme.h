/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_mixer.h>

typedef struct 
{
	SDL_Surface *background[3];
	SDL_Surface *sk;
	SDL_Surface *win;
	SDL_Surface *lost;
	int positionVraiReponse;
	int positionResolution;
	

          
      
}Enigme;


void Init_Enigme(Enigme *e);
int Play_Enigme(Enigme *e,SDL_Surface *ecran,int *vv);
int Verify(Enigme *e,SDL_Surface *ecran,int xk,int yk,int *vv);
void Display_Enigme(Enigme *e,SDL_Surface *ecran);
int Verify_Enigme(Enigme *e,int *Game,SDL_Surface *ecran);
void Free_Enigme(Enigme *e);



#endif
