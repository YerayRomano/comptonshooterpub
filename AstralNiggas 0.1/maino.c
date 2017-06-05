#include <jo/jo.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static int ship_sprite_id = 0;
static int pause_id = 0;
int bolas = 32;
int pausa = 0;
int nidoran = 0;
int score;
int cargar = 1;
static int bolitas_sprite_id [32];
int ship_paso_x = 0;
int ship_paso_y = 0;
int primigenio = 0;
struct bolita_pos {
	int sprite;
	int primigenio;
	int x;
	int y;
	int paso_x;
	int paso_y;
	float zoom;
};
struct elemento_scroll {
	int sprite;
	int x;
	int y;
};
struct enem_desarmado {
	int sprite;
	int primigenio;
	int x;
	int y;
	int paso_x;
	int score;
	int paso_y;
	float zoom;
	int muerto;
};
int ultimo = 25;
int primero = 0;
struct elemento_scroll medio;
int level = 0;
struct bolita_pos bolitas [32];
struct enem_desarmado enemigos [20];
int vida_img [10];
char *fichero;
int bolita_act = 0;
int bolicontador = 0;
int cont = 0;
int conty = 0;
int muertos = 0;
int arrancado = 0;
int locka = 0;
int vidas = 3;
int scroll = 0;
int vivo = 1;
int cargado = 0;
int contato = 0;
char *lectura;
int top = 0;
int niggafucka = 0;
static int ship_pos_x = -120;
static int ship_pos_y = 0;
static int vida_ico = 0;
static int cruz = 0;
int migos = 0;
int vector [4] = {0,1,0,1};
int backup = 0;
int revisado = 0;
int ultima_temp = 0;
int temperatura = 2;
struct elemento_salpicadero {
	int sprite;
	int x;
	int y;
	int visible;
};
struct elemento_salpicadero heat;
struct elemento_salpicadero niveles [8];
int alien = 0;
int nivel = 0;
int pasos = 0;
int infierno = 0;
int saltarin [4] = {4,3,7,3};
struct elemento_scroll techo [26];
struct elemento_scroll suelo [26];
int goomba = 0;
jo_backup_device dev;
int cargar_puntuacion(jo_backup_device dev) {
	if (!jo_backup_mount(dev)) {
		return -1;
	}
	if(!jo_backup_file_exists(dev,"MANDRIL")) {
		jo_backup_unmount(dev);
		return -2;
	} else {
		lectura = (char *) jo_backup_load_file_contents(dev, "MANDRIL", JO_NULL);
		sscanf(lectura,"%d",&top);
	}
	jo_backup_unmount(dev);
	return top;
}
int guardar_puntuacion(jo_backup_device dev) {
	if (!jo_backup_mount(dev)) {
		return -1;
	}
	sprintf(&lectura,"%d",score);
	jo_backup_save_file_contents(dev,"MANDRIL","pajero",lectura,sizeof(lectura));
	jo_backup_unmount(dev);
}
void compactar_array_bolitas() {
	int i;
	int j;
	for(i=0;i<(bolas-1);i++) {
		if(bolitas[i].sprite == 0) {
			j = i;
		}
		if(bolitas[i].sprite != 0 && j != 0) {
			bolitas [j] = bolitas [i];
			bolitas [i].sprite = 0;
			j = i;
		}
	}
}
int contar_bolitas() {
	int i;
	for(i=0;i<(bolas-1);i++) {
		if(bolitas[i].sprite == 0) {
			break;
		}
	}
	return i;
}
void cargar_nivel() {
	int el_creado = 0;
	if(cargar == 0) {
		return;
	}
	switch(nivel) {
		case 0:
			cont = 0;
			cargado = 0;
			while(cont < 5) {
				if(arrancado == 0)
					enemigos [cont].sprite = jo_sprite_add_tga(JO_ROOT_DIR, "BYDO.TGA", JO_COLOR_Green);
				enemigos [cont].x = 50;
				enemigos [cont].y = -40+60*cont;
				enemigos [cont].paso_x = enemigos [cont].x;
				enemigos [cont].paso_y = enemigos [cont].y;
				enemigos [cont].primigenio = 1;
				if(cont >= 2)
					enemigos [cont].muerto = 1;
				enemigos [cont].score = 200;
				cont++;
			}
			migos = cont;
			arrancado = 1;
			cargar = 0;
			cargado = 1;
		break;
		case 1:
			cont = 0;
			cargado = 0;
			while(cont < 5) {
				switch(el_creado) {
					case 0:
						enemigos [cont].x = 50;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
					case 1:
						enemigos [cont].x = 180;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
					case 2:
						enemigos [cont].x = 240;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
					case 3:
						enemigos [cont].x = 300;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
				}
				enemigos [cont].score = 200;
				el_creado++;
				cont++;
			}
			migos = cont;
			cargar = 0;
			cargado = 1;
		break;
		case 2:
			cont = 0;
			cargado = 0;
			while(cont < 5) {
				switch(el_creado) {
					case 0:
						enemigos [cont].x = 50;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
					case 1:
						enemigos [cont].x = 180;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
					case 2:
						enemigos [cont].x = 240;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
					case 3:
						enemigos [cont].x = 300;
						enemigos [cont].y = -20;
						enemigos [cont].muerto = 0;
					break;
				}
				enemigos [cont].score = 200;
				el_creado++;
				cont++;
			}
			migos = cont;
			cargar = 0;
			cargado = 1;
		break;
	}
}
void decrementar_temperatura() {
	if(bolicontador == 0) {
		while(contato < 9) {
			niveles [contato].visible = 0;
			contato++;
		}
	}
	if(bolicontador < 8) {
		infierno = 0;
	}
	if(bolicontador >= 4) {
		niveles [(bolicontador+1) / 4].visible = 0;
	} else {
		niveles [0].visible = 0;
		niveles [1].visible = 0;
	}
}
void comprobar_colisiones() {
	for(cont=0;cont<migos;cont++) {
		if((enemigos [cont].x >= (ship_pos_x - 26) && enemigos [cont].x <= (ship_pos_x + 26)) && (enemigos [cont].y >= (ship_pos_y - 10) && enemigos [cont].y <= (ship_pos_y + 10)) && enemigos [cont].muerto == 0) {
			vivo = 0;
			vidas--;
			if(score > top) {
				revisado = 0;
			}
			if(revisado == 0) {
				guardar_puntuacion(dev);
				revisado = 1;
			}
			muertos++;
			enemigos [cont].muerto = 1;
			if(vidas > 0) {
				ship_pos_x = -120;
				ship_pos_y = 0;
				nivel = 0;
				cargar = 1;
				vivo = 1;
			}
			decrementar_temperatura();
		}
		if(cont < bolas) {
			if((enemigos [cont].x >= (bolitas[cont].x - 18) && enemigos [cont].x <= (bolitas[cont].x + 18)) && (enemigos [cont].y >= (bolitas [cont].y - 10) && enemigos [cont].y <= (bolitas [cont].y + 10)) && enemigos [cont].muerto == 0 && enemigos [cont].x <= 180) {
				if(enemigos [cont].muerto == 0) {
					score += enemigos [cont].score;
					enemigos [cont].muerto = 1;
					muertos++;
				}
			}
		}
	}
}
void			my_draw(void)
{
	jo_printf(0, 0,"score=%d-top=%s-temeratura=%d",score,"fefa",niveles[0].visible);
	if (pausa != 1) {
		comprobar_colisiones();
	}
	if(vidas == 0) {
		jo_sprite_draw3D(nidoran, 0, 0, 500);
	}
	if(vivo == 1)
		if(primigenio == 0) {
			ship_paso_x = ship_pos_x;
			ship_paso_y = ship_pos_y;
			primigenio = 1;
		}
		if(vivo == 1)
			jo_sprite_draw3D(ship_sprite_id, ship_pos_x, ship_pos_y, 500);
	cont = 0;
	while(cont < bolas || cont < migos || cont < 26) {
		if(cont < bolas) {
				if(bolitas[cont].sprite != 0) {
				if(bolitas [cont].x >= 180) {
					locka = 1;
					jo_sprite_free_from(bolitas_sprite_id[cont]);
					decrementar_temperatura();
					bolitas[cont].sprite = 0;
					bolitas[cont].x = 0;
					bolitas[cont].y = 0;
					bolitas[cont].zoom = 0;
					compactar_array_bolitas();
					bolicontador = contar_bolitas();
					locka = 0;
					continue;
				}
				if(pausa == 0) {
					if(bolitas[cont].primigenio == 1) {
						bolitas[cont].primigenio = 0;
					} else {
						bolitas[cont].x += 2;
					}
				}
				jo_sprite_draw3D(bolitas_sprite_id[cont],bolitas[cont].x,bolitas[cont].y,500);
			}
		}
		if(cont == (bolas-1)) {
			temperatura = (bolicontador+1) / 2;
			if(temperatura == 8) {
				infierno = 1;
			}
			for(contato = 0;contato < temperatura;contato++) {
				niveles [contato].visible = 1;
			}
			ultima_temp = contato;
		}
		jo_sprite_draw3D(heat.sprite,heat.x,heat.y,500);
		if(cont < 26) {
			jo_sprite_draw3D(suelo[cont].sprite,suelo[cont].x,suelo[cont].y,500);
			jo_sprite_draw3D(techo[cont].sprite,techo[cont].x,techo[cont].y,500);
		}
		jo_sprite_draw3D(vida_ico,niveles[7].x+10,niveles[7].y,500);
		jo_sprite_draw3D(cruz,niveles[7].x+30,niveles[7].y,500);
		jo_sprite_draw3D(vida_img[vidas],niveles[7].x+50,niveles[7].y,500);
		if(cont < migos) {
				if(enemigos[cont].muerto == 0) {
					if(enemigos [cont].x <= -180) {
						enemigos [cont].muerto = 1;
						muertos++;
						continue;
					}
					if(pausa == 0) {
						if(enemigos [cont].primigenio == 1) {
							enemigos [cont].primigenio = 0;
						} else {
							if(niggafucka % 2 == 0)
								switch(nivel) {
									case 0:
										enemigos [cont].x -= 1;
									break;
									case 1:
										enemigos [cont].x -= 1;
										pasos++;
										if(vector [cont] == 0) {
											if(enemigos [cont].y < 40) {
												enemigos [cont].y += 2;
											} else {
												vector [cont] = 1;
											}
										} else {
											if(enemigos [cont].y > -40) {
												enemigos [cont].y -= 2;
											} else {
												vector [cont] = 0;
											}
										}
									break;
									case 2:
										enemigos [cont].x -= 1;
										pasos++;
										if(vector [cont] == 0) {
											if(enemigos [cont].y < 40) {
												enemigos [cont].y += saltarin [cont];
											} else {
												vector [cont] = 1;
											}
										} else {
											if(enemigos [cont].y > -40) {
												enemigos [cont].y -= saltarin [cont];
											} else {
												vector [cont] = 0;
											}
										}
									break;
								}
						}
						if(enemigos [cont].muerto != 1)
							jo_sprite_draw3D(enemigos[cont].sprite,enemigos[cont].x,enemigos[cont].y,500);
					} 
				}
		}
		if(muertos == 2 && nivel == 0) {
			muertos = 0;
			cargar = 1;
			nivel++;
		}
		if(muertos == 4 && nivel == 1) {
			muertos = 0;
			cargar = 1;
			nivel++;
		}
		cont++;
		if(niveles [cont].visible == 1) {
			if(infierno == 1) {
				if(niggafucka % 2 == 0){
					jo_sprite_draw3D(niveles[cont].sprite,niveles[cont].x,niveles[cont].y,500);
				}
			} else {
				jo_sprite_draw3D(niveles[cont].sprite,niveles[cont].x,niveles[cont].y,500);
			}
		}
	}
	if(niveles [cont].visible == 1) {
		if(infierno == 1) {
			if(niggafucka % 2 == 0){
				jo_sprite_draw3D(niveles[cont].sprite,niveles[cont].x,niveles[cont].y,500);
			} else {
				jo_sprite_draw3D(niveles[cont].sprite,niveles[cont].x,niveles[cont].y,500);
			}
		}
	}
	if(niggafucka == 200000) {
			niggafucka = 0;
	}
	niggafucka++;
	if(pausa == 1) {
		jo_sprite_draw3D(pause_id,0,0,500);
	}
}

void			my_gamepad(void)
{
	if (!jo_is_pad1_available())
		return ;
	if (jo_is_pad1_key_pressed(JO_KEY_LEFT) && pausa == 0 && ship_pos_x > -128) {
		ship_pos_x -= 2;
		ship_paso_x -=2;
	}
	if (jo_is_pad1_key_pressed(JO_KEY_RIGHT) && pausa == 0 && ship_pos_x < 130) {
		ship_pos_x += 2;
		ship_paso_x += 2;
	}
	if (jo_is_pad1_key_pressed(JO_KEY_UP) && pausa == 0) {
		if(ship_paso_y > -62) {
			ship_pos_y -= 2;
			ship_paso_y -= 2;
		}
	}
	if (jo_is_pad1_key_pressed(JO_KEY_DOWN) && pausa == 0) {
		if(ship_paso_y < 62) {
			ship_pos_y += 2;
			ship_paso_y += 2;
		}
	}
	if(jo_is_pad1_key_pressed(JO_KEY_B) && pausa == 0 && vivo == 1) {
		if(bolicontador != 15 && locka == 0) {
			bolitas_sprite_id [bolicontador] = jo_sprite_add_tga(JO_ROOT_DIR, "BOLITA.TGA", JO_COLOR_Green);
			bolitas[bolicontador].sprite = bolitas_sprite_id [bolicontador];
			bolitas [bolicontador].x = ship_pos_x + 13;
			bolitas[bolicontador].primigenio = 1;
			bolitas [bolicontador].y = ship_pos_y;
			bolicontador++;
		}
		cont = 0;
		while(cont < 300000) {
			cont++;
		}
	}
	if(jo_is_pad1_key_pressed(JO_KEY_START)) {
		pausa = !pausa;
		cont = 0;
		while(cont < 400000) {
			cont++;
		}
	}
}
void			jo_main(void)
{
	jo_core_init(JO_COLOR_Black);
	backup = cargar_puntuacion(dev);
	nidoran = jo_sprite_add_tga(JO_ROOT_DIR, "OVA.TGA", JO_COLOR_Green);
	for(cont=0;cont<26;cont++) {
		techo [cont].sprite = jo_sprite_add_tga(JO_ROOT_DIR, "TECHO.TGA", JO_COLOR_Green);
		techo [cont].x = -228 + (16 * cont);
		techo [cont].y = -84;
		suelo [cont].sprite = jo_sprite_add_tga(JO_ROOT_DIR, "SUELO.TGA", JO_COLOR_Green);;
		suelo [cont].x = -228 + (16 * cont);
		suelo [cont].y = 84;
	}
	cont = 0;
	heat.sprite = jo_sprite_add_tga(JO_ROOT_DIR, "HEAT.TGA", JO_COLOR_Green);
	vida_ico = jo_sprite_add_tga(JO_ROOT_DIR, "VIDAS.TGA", JO_COLOR_Green);
	cruz = jo_sprite_add_tga(JO_ROOT_DIR, "QUAN.TGA", JO_COLOR_Green);
	heat.x = -80;
	heat.y = 70;
	heat.visible = 1;
	for(cont=0;cont<4;cont++) {
		switch(cont) {
			case 0:
				fichero ="A0.TGA";
			break;
			case 1:
				fichero ="A1.TGA";
			break;
			case 2:
				fichero ="A2.TGA";
			break;
			case 3:
				fichero ="A3.TGA";
			break;
		}
		vida_img [cont] = jo_sprite_add_tga(JO_ROOT_DIR,fichero, JO_COLOR_Green);
	}
	for(cont=0;cont<8;cont++) {
		niveles [cont].sprite = jo_sprite_add_tga(JO_ROOT_DIR, "LEVEL.TGA", JO_COLOR_Green);
		niveles [cont].y = 105;
		if(cont == 0) {
			niveles [cont].x = heat.x + 9;
		} else {
			niveles [cont].x = (niveles [cont-1].x + 10);
		}
		heat.y = 105;
		heat.visible = 0;
	}
	ship_sprite_id = jo_sprite_add_tga(JO_ROOT_DIR, "NAVE.TGA", JO_COLOR_Green);
	pause_id = jo_sprite_add_tga(JO_ROOT_DIR, "PAUSE.TGA", JO_COLOR_Green);
	jo_core_add_callback(my_gamepad);
	jo_core_add_callback(my_draw);
	jo_core_add_callback(cargar_nivel);
	jo_core_run();
}

