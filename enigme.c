/**
* @file engima.c
* @brief Testing Program.
* @author mtx
* @version 0.1
* @date Jun 17, 2020
*
* Collision Trigo
*
*/
#include "enigme.h"
#include <stdbool.h>
#include <math.h>
void Init_Enigme(Enigme *e)
{
	e->background[0]=IMG_Load("fond.jpg");
	e->background[1]=IMG_Load("PCBclipartwired.png");
	e->background[2]=IMG_Load("Lock-schematicform.PNG");

	e->sk=IMG_Load("swissup.png");

}

void Display_Enigme(Enigme *e,SDL_Surface *ecran)
{
	SDL_Rect position;
	position.x = (800/8)-(255/8);
	position.y = (600/2)-(314/2);
	SDL_Rect positiong;
	positiong.x= (800/1.2)-(300/1.2);
	positiong.y= (600/2)-(233/2);

	SDL_Rect posk;
	//posk.x=(800/4)-(500/4);
	//posk.y=(800/4)-(500/4);
	SDL_BlitSurface(e->background[0],NULL,ecran,NULL);
	SDL_BlitSurface(e->background[1],NULL,ecran,&position);
	SDL_BlitSurface(e->background[2],NULL,ecran,&positiong);
	//SDL_BlitSurface(e->sk,NULL,ecran,&posk);
}


int Verify(Enigme *e,SDL_Surface *ecran,int xk,int yk)
{
	SDL_Rect contact;
	contact.x=268;
	contact.y=309;
	int xCC=288,yCC=420;
	int xC1=xk-103,yC1=yk+81;
	int xC2=xk+103,yC2=yk+81;
	int dC1CC=sqrt(pow(xC1-xCC,2)+pow(yC1-yCC,2));
	int dC2CC=sqrt(pow(xC2-xCC,2)+pow(yC2-yCC,2));
	if((dC1CC>=81)&&(dC2CC<=81)&&(xk>230))
		{
			printf("C1/C2 %d %d",xC1,xC2);
			printf("d1/d2 %d %d",dC1CC,dC2CC);
			printf("COLLIISSSIIOOONN");
		}

}



int Play_Enigme(Enigme *e,SDL_Surface *ecran)
{
	int hee=1;
	Display_Enigme(e,ecran);
	SDL_Event event;
	SDL_Event movek;
	int x=0,y=0;
	bool clcheck= false;
	while(1)
	{
		Display_Enigme(e,ecran);//affichage

		//SDL_BlitSurface(e->sk,NULL,ecran,&posk);

		while(SDL_PollEvent(&event))
		{
		switch (event.type)
		{

			/*case SDL_MOUSEMOTION:
			{
				printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
				//break;

			}*/
			case SDL_MOUSEBUTTONDOWN:
			{
					printf("SourisON");
					clcheck=!clcheck;
					while(clcheck)
					{
						while(SDL_PollEvent(&movek))
						{
							switch(movek.type)
							{
								case SDL_MOUSEMOTION:
									printf("xxx");
									SDL_Rect positionK;
									SDL_GetMouseState( &x, &y );
									printf("Souris cliquée en position %d %d\n",x, y);
									positionK.x = x-58 ;
									positionK.y = y-143 ;
									Verify(e,ecran,positionK.x,positionK.y);
									Display_Enigme(e,ecran);
									SDL_BlitSurface(e->sk, NULL, ecran, &positionK);
									SDL_Flip(ecran);
									break;

								case SDL_MOUSEBUTTONDOWN:
									printf("Pressed.");
									clcheck=0;
									break;
							}

						}
					}
			break;

			}
			case SDL_QUIT:
			{
				SDL_Quit();//return 0;
			}
		}
		printf("sortie");
		}
	}
}
