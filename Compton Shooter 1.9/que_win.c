//juegos de compton
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int segundos;
int bucle;
int mj;
int contato()
{
  SDL_Init(SDL_INIT_TIMER);
  segundos = 0;  
  while(bucle == 1) {
    printf("segundos=%d\n",segundos);
    SDL_Delay(1000);
    segundos++;
  }
      
}
int main(int argc,char **argv)
{
	SDL_Surface *tela;
	SDL_Surface *minuto;
	SDL_Surface *ecra;
	SDL_Surface *muerto;
	SDL_Surface *menu;
	FILE *hola;
	SDL_Surface *game;
	FILE *compro;
	div_t divide;
	SDL_Surface *suelo;
	SDL_Surface *shot;
	SDL_Surface *mapa0;
	SDL_Surface *mapa1;
	SDL_Surface *bote0;
	SDL_Surface *bote1;
	SDL_Rect fijo0;
	SDL_Rect estampida;
	SDL_Rect fijo1;
	SDL_Rect botella1;
	SDL_Rect botella2;
	SDL_Rect curry;
	SDL_Thread *fio;
	SDL_AudioSpec menace;
	Uint8 buff;
	Uint32 tama;
	int alea;
	int acceso;
	int pausa;
	int aleatorio;
	int resta;	
	int tmp;
	int actualizar;
	int x_1;
	int x_2;
	int uno;
	int dos;
	int uoeno;
	int hilos;
	int sonido;
	int x_raton;
	int y_raton;
	int pasos;
	SDL_Rect estampa;
	SDL_Event invita;
	SDL_Event juego;
	Uint8 r ,g ,b;
	Uint32 color;
	long tempo;
	struct {
		int x ,y;
		int bpp;
		char *acel;
	} espec;
	struct {
		long fio;
		long dental;
	} brasil;
	int fijo_x , fijo_y;
	int raton_x , raton_y;
	int cont , paridad;
	int conty;
	int entero;
	int mismo;
	int sordo;
	int jpg;
	hilos = 1;
	sonido = 0;
	jpg = 1;
	fijo_x = 1024;
	fijo_y = 768;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	if(jpg == 1) {
	    IMG_Init(IMG_INIT_JPG);
	}
	printf("compton shooter para windows\n");
	printf("programador: Yeray Romano\n");
	printf("responsable de compilacion: David Ojeda\n");
	inito:	
	if(jpg == 1) {
	  menu = IMG_Load("leopardo.jpg");
	  printf("compton esta en la puta casa\n");
	} else {
	    menu = SDL_LoadBMP("leopardo.bmp");
	}
	if(!menu) {
		printf("error linea 23 no se pudo encontar eusebio.bmp\n");
		exit(0);
	}
	espec.bpp = (int) menu->format->BitsPerPixel;
	espec.x = 1024;
	espec.y = 768;
	cont = 0;
	paridad = 0;
	while(cont <= 2) {
		switch(cont) {
			case 0:
				entero = SDL_VideoModeOK(espec.x,espec.y,espec.bpp,SDL_HWSURFACE);
				if(entero == 0) {
					printf("modo de video no disponible\n");
					cont++;
				} else {
					if(entero >= espec.bpp) {
						espec.acel = "hardware";						
						cont = 2;
					} else {
						printf("no se puede usar la paleta esperada\n");
						exit(-1);
					}
				}
			break;
			case 1:
				entero = SDL_VideoModeOK(espec.x,espec.y,espec.bpp,SDL_SWSURFACE);
				if(entero == 0) {
					printf("modo de video no disponible\n");
					cont++;
				} else {
					if(entero >= espec.bpp) {
						espec.acel = "software";						
						cont = 2;
					} else {
						printf("no se puede usar la paleta esperada\n");
						exit(-1);
					}
				}
			break;
			case 2:
				printf("se va a intentar abrir la ventana\n");
				cont++;
			break;
			default:
				printf("what tqe fuck\n");
				exit(-1);
			break;
		}
	}
	if(espec.acel == "hardware") {
		tela = SDL_SetVideoMode(espec.x,espec.y,espec.bpp,SDL_HWSURFACE);
	}
	if(espec.acel = "software") {
		tela = SDL_SetVideoMode(espec.x,espec.y,espec.bpp,SDL_SWSURFACE);
	}
	SDL_WM_SetCaption("Comptom Shooter 0.1",NULL);
	SDL_WM_SetIcon(SDL_LoadBMP("crip.bmp"),NULL);
	if(!tela) {
		printf("aunque no se esperaba no se pudo realizar aceleracion por\t%s",espec.acel);
		exit(-1);
	}
	resta = tela->h - menu->h;
	divide = div(resta,2);	
	estampa.x = 0;
	estampa.y = divide.quot;
	estampa.w = menu->w;
	estampa.h = menu->h;
	SDL_BlitSurface(menu,NULL,tela,&estampa);
	SDL_UpdateRects(tela,1,&estampa);
	SDL_Delay(3000);
	SDL_FillRect(tela,&estampa,0);
	SDL_UpdateRects(tela,1,&estampa);	
	SDL_FreeSurface(menu);
	menu = SDL_LoadBMP("NWA.bmp");
	if(!menu) {
		printf("donde esta NWA\n");
		exit(-1);
	} else {
		if(menu->w <= espec.x) {
			espec.x = menu->w;
		} else {
			printf("error de fondo\n");
			exit(-1);
		}
		if(menu->h <= espec.y) {
			espec.y = menu->h;
		} else {
			printf("error de fondo\n");
			exit(-1);
		}
		if(menu->format->BitsPerPixel <= espec.bpp) {
			espec.bpp = menu->format->BitsPerPixel;
		} else {
			printf("no aondes en los colores\n");
			exit(-1);		
		}
	}
	estampa.x = 0;
	resta = tela->h - menu->h;
	divide = div(resta,2);
	estampa.y = divide.quot; 	
	estampa.w = espec.x;
	estampa.h = espec.y;
	SDL_BlitSurface(menu,NULL,tela,&estampa);
	SDL_UpdateRects(tela,1,&estampa);
	SDL_Delay(3000);
	SDL_FillRect(tela,&estampa,0);
	SDL_UpdateRects(tela,1,&estampa);
	SDL_FreeSurface(menu);	
	menu = SDL_LoadBMP("compton.bmp");
	if(!menu) {
		printf("donde esta compton\n");
		exit(-1);
	} else {
		if(menu->w <= espec.x) {
			espec.x = menu->w;
		} else {
			printf("error de fondo\n");
			exit(-1);
		}
		if(menu->h <= espec.y) {
			espec.y = menu->h;
		} else {
			printf("error de fondo\n");
			exit(-1);
		}
		if(menu->format->BitsPerPixel <= espec.bpp) {
			espec.bpp = menu->format->BitsPerPixel;
		} else {
			printf("no aondes en los colores\n");
			exit(-1);		
		}
	}
	divide = div(menu->h,2);
	uoeno = div(divide.quot,3).quot;
	resta = fijo_y - menu->h;
	divide = div(resta,2);
	SDL_BlitSurface(menu,NULL,tela,&estampa);
	SDL_UpdateRects(tela,1,&estampa);
	conty = 0;
	curry.w = menu->w;
	curry.h = uoeno;
	curry.x = 0;
	while(conty <= 4) {
	  curry.y = conty*uoeno + divide.quot;
	  SDL_FillRect(tela,&curry,SDL_MapRGB(tela->format,0,0,254));
	  SDL_UpdateRects(tela,1,&curry);
	  SDL_Delay(400);
	  SDL_BlitSurface(menu,NULL,tela,&estampa);
	  SDL_UpdateRects(tela,1,&estampa);
	  conty++;
	}
	if(sonido == 1) {
	  SDL_LoadWAV("dopeman.wav",&menace,&buff,&tama);	
	  sordo = Mix_OpenAudio(menace.freq,menace.format,menace.channels,menace.size);
	  if(sordo == -1) {
	    printf("modo de sonido no compatible\n");
	    exit(-1);
	  }
	}
	compton:
	SDL_PumpEvents();
	SDL_WaitEvent(&invita);
	switch(invita.type) {
		case SDL_KEYDOWN:
			if(invita.key.keysym.sym == SDLK_ESCAPE) {
				SDL_FreeSurface(menu);
				exit(-1);
			}			
			goto outta;
		break;
		default:
			goto compton;
		break;
	}	
	outta:
	SDL_FreeSurface(menu);	
	menu = SDL_LoadBMP("disparame.bmp");
	espec.x = 1024;
	espec.y = 768;	
	if(!menu) {
		printf("donde esta compton\n");
		exit(-1);
	} else {
		if(menu->w <= espec.x) {
			espec.x = menu->w;
		} else {
			printf("error de fondo\n");
			exit(-1);
		}
		if(menu->h <= espec.y) {
			espec.y = menu->h;
		} else {
			printf("error de fondo\n");
			exit(-1);
		}
		if(menu->format->BitsPerPixel <= espec.bpp) {
			espec.bpp = menu->format->BitsPerPixel;
		} else {
			printf("no aondes en los colores\n");
			exit(-1);		
		}
	}
	estampa.w = espec.x;
	estampa.h = espec.y;
	estampa.x = 0;
	estampa.y = 0;
	SDL_BlitSurface(menu,NULL,tela,&estampa);
	SDL_UpdateRects(tela,1,&estampa);
	SDL_WarpMouse(512-15,384-15);
	suelo = SDL_LoadBMP("suelo.bmp");
	if(!suelo) {
		printf("donde esta el suelo\n");
		SDL_FreeSurface(tela);
		exit(-1);	
	}	
	estampa.x = 0;
	estampa.y = menu->h - suelo->h;
	estampa.w = suelo->w;
	estampa.h = suelo->h;
	SDL_BlitSurface(suelo,NULL,tela,&estampa);
	SDL_UpdateRects(tela,1,&estampa);
	compro = fopen("pantalla.bmp","rb");
	if(!compro) {
		SDL_LockSurface(tela);
		SDL_SaveBMP(tela,"pantalla.bmp");
		SDL_UnlockSurface(tela);
	}
	mapa0 = SDL_LoadBMP("ladrillo.bmp");
	if(!mapa0) {
		printf("donde esta el ladrillo\n");
		SDL_FreeSurface(tela);
		exit(-1);
	}
	alea = 200;
	fijo0.x = alea;
	x_1 = alea;
	fijo0.y = menu->h - mapa0->h - suelo->h;
	fijo0.w = mapa0->w;
	fijo0.h = mapa0->h;
	SDL_BlitSurface(mapa0,NULL,tela,&fijo0);
	SDL_UpdateRects(tela,1,&fijo0);
	mapa1 = SDL_LoadBMP("llanta.bmp");
	if(!mapa1) {
		printf("donde esta tu llanta\n");
		SDL_FreeSurface(tela);
		exit(-1);
	}
	x_2 = rand() % 400 + 300;
	printf("x_2=%d\n",x_2);
	fijo1.x = x_2;
	fijo1.y = menu->h - mapa1->h - suelo->h;
	fijo1.w = mapa1->w;
	fijo1.h = mapa1->h;
	SDL_BlitSurface(mapa1,NULL,tela,&fijo1);
	SDL_UpdateRects(tela,1,&fijo1);
	bote0 = SDL_LoadBMP("botella.bmp");
	bote1 = SDL_LoadBMP("botella.bmp");
	if(!bote0) {
		printf("un borracho se ha bebido las botellas\n");
		SDL_FreeSurface(tela);
		exit(-1);
	}
	if(!bote1) {
		printf("un borracho se ha bebido las botellas\n");
		SDL_FreeSurface(tela);
		exit(-1);
	}
	botella1.x = fijo0.x + 8;
	botella1.y = fijo0.y - bote0->h;
	botella1.w = fijo0.w;
	botella1.h = fijo0.h;
	botella2.x = fijo1.x + 8;
	botella2.y = fijo1.y - bote1->h;
	botella2.w = fijo1.w;
	botella2.h = fijo1.h;
	SDL_BlitSurface(bote0,NULL,tela,&botella1);
	SDL_UpdateRects(tela,1,&botella1);
	SDL_BlitSurface(bote1,NULL,tela,&botella2);
	SDL_UpdateRects(tela,1,&botella2);
	uno = 0;
	dos = 0;
	cont = 0;		
	actualizar = 0;	
	ecra = SDL_LoadBMP("pantalla.bmp");
	if(!ecra) {
		printf("no hay fondo\n");
		exit(-1);
	}		
	if(hilos == 0) {
	  brasil.fio = time(NULL);
	} else {
	  bucle = 1;
	  fio = SDL_CreateThread(contato,NULL);
	}
	while(cont <= 1) {
		SDL_PumpEvents();		
		SDL_WaitEvent(&juego);
		switch(juego.type) {
			case SDL_KEYDOWN:
				if(invita.key.keysym.sym == SDLK_ESCAPE) {
					SDL_FreeSurface(menu);
					exit(-1);
				}
				if(invita.key.keysym.sym == SDLK_SPACE) {
					if(pausa == 1) {
						printf("juego pausado\n");
					} else {
						printf("sigue demostrando que eres un OG\n");
					}
				}
			break;
			case SDL_MOUSEBUTTONDOWN:
				printf("has pulsado el raton\n");
				SDL_GetMouseState(&x_raton,&y_raton);
				if(y_raton >= botella1.y) {
					if(y_raton <= (botella1.y + bote0->h)) {					
						if(x_raton >= botella1.x) {						
							if(x_raton <= (botella1.x + bote0->w)) {							
								printf("tocado\n");
								cont++;
								actualizar = 1;
								uno = 1;
							}
						}
					}
				}
				if(y_raton >= botella2.y) {
					if(y_raton <= (botella2.y + bote0->h)) {					
						if(x_raton >= botella2.x) {						
							if(x_raton <= (botella2.x + bote0->w)) {							
								printf("tocado\n");
								cont++;
								actualizar = 1;
								dos = 2;
							}
						}
					}
				}
				printf("entrada_n=%d\n",cont);
				if(actualizar == 1) {
					estampa.x = 0;
					estampa.y = 0;
					estampa.w = ecra->w;
					estampa.h = ecra->h;					
					SDL_BlitSurface(ecra,NULL,tela,&estampa);
					SDL_UpdateRects(tela,1,&estampa);
					SDL_BlitSurface(mapa0,NULL,tela,&fijo0);
					SDL_UpdateRects(tela,1,&fijo0);
					SDL_BlitSurface(mapa1,NULL,tela,&fijo1);
					SDL_UpdateRects(tela,1,&fijo1);					
					if(uno == 0) {
						SDL_BlitSurface(bote0,NULL,tela,&botella1);
						SDL_UpdateRects(tela,1,&botella1);
					}
					if(dos == 0) {
						SDL_BlitSurface(bote1,NULL,tela,&botella2);
						SDL_UpdateRects(tela,1,&botella2);					
					}
					actualizar = 0;				
				}
			break;
		}
	}
	if(hilos == 0) {
	  brasil.dental = time(NULL);
	  tempo = brasil.dental - brasil.fio;
	} else {
	  bucle = 0;
	  tempo = (long) segundos;
	}
	hola = fopen("hola.txt","w");
	fprintf(hola,"%ld",tempo);
    printf("segundos=%ld\n",tempo);	
	estampa.x = 0;
	estampa.y = 0;
	estampa.w = minuto->w;
	estampa.h = minuto->h;	
	if(tempo <= 10) {
		minuto = SDL_LoadBMP("game1.bmp");
		if(!minuto) {
			printf("no podemos felicitarte\n");
			SDL_FreeSurface(tela);
			exit(-1);
		}
		SDL_BlitSurface(minuto,NULL,tela,&estampa);
		SDL_UpdateRects(tela,1,&estampa);
	} else {
		minuto = SDL_LoadBMP("tupac.bmp");
		if(!muerto) {
			printf("no has ganado\n");
			SDL_FreeSurface(tela);
		}
		SDL_BlitSurface(minuto,NULL,tela,&estampa);
		SDL_UpdateRects(tela,1,&estampa);
		printf("estas muerto");
		goto vida;
	}
	estampa.x = 0;
	estampa.y = 0;
	estampa.w = minuto->w;
	estampa.h = minuto->h;	
	vida:	
	SDL_Delay(4000);
	SDL_FreeSurface(minuto);
	minuto = SDL_LoadBMP("final.bmp");
	if(!minuto) {
		printf("donde estan los creditos\n");
		SDL_FreeSurface(tela);
	}
	SDL_BlitSurface(minuto,NULL,tela,&estampa);
	SDL_UpdateRects(tela,1,&estampa);
	SDL_Delay(10000);
	printf("hasta pronto\n");
	SDL_FreeSurface(tela);	
}
