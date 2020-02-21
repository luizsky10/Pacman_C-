#include "Ghost.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

	Ghost::Ghost(){ // Construtor padrão

			GhostLeft = al_load_bitmap("ghostsgLeft.png");
			GhostRight = al_load_bitmap("ghostsgRight.png");
			GhostUp = al_load_bitmap("ghostsgUp.png");
			GhostDown = al_load_bitmap("ghostsgDown.png");
				al_convert_mask_to_alpha(GhostLeft ,al_map_rgb(0,0,0));
				al_convert_mask_to_alpha(GhostRight ,al_map_rgb(0,0,0));
				al_convert_mask_to_alpha(GhostUp ,al_map_rgb(0,0,0));
				al_convert_mask_to_alpha(GhostDown ,al_map_rgb(0,0,0));
	}

	Ghost::Ghost(char *img, int a, int b, bool f1, bool f2, bool f3, bool f4, int c, int d) : Player(a,b,f1,f2,f3,f4,c,d){	// Construtor normal

	
	}
	Ghost::Ghost(Ghost& obj) : Player(obj){
	}
	Ghost::~Ghost(){}


		void Ghost::draw_GhostLeft(){
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(GhostLeft, momento, 0, 25, 25, getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}
	void Ghost::draw_GhostRight(){
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(GhostRight, momento, 0, 25, 25,getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}
	void Ghost::draw_GhostUp(){
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(GhostUp, momento, 0, 25, 25,getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}
	void Ghost::draw_GhostDown(){
		int sentido =2;
		
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(GhostDown, momento, 0, 25, 25, getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}

		int	Ghost::get_direction(){
			return direction;
			
		}

		void Ghost::set_direction(int a){
			direction = a;
		}

