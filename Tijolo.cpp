#include <iostream>
#include <string.h>
#include <vector>
#include "Tijolo.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>


	Tijolo::Tijolo(){  // Construtor Padrao
		x=1;
		y=1;	
		tijolo = al_load_bitmap("block.png");		
				
	
		}
	
	Tijolo::Tijolo(int a, int b){   // Construtor Normal
		x=a;
		y=b;
		tijolo = al_load_bitmap("block.png");	
	}
	Tijolo::Tijolo(const Tijolo &obj){  // Construtor de Cópia
		x= obj.x;
		y=obj.y;
		tijolo = al_load_bitmap("block.png");	
	}	
	Tijolo::~Tijolo(){
	}	
	
	void Tijolo::desenhaTijolo(){
		//x*20;
		//y*30;		
		al_init_image_addon();

		al_draw_bitmap(tijolo, x, y, 0);
	}

	int Tijolo::getx(){
		return x;
	}
	int Tijolo::gety(){
		return y;
	}
	void Tijolo::setx(int a){
		x = a;
	}
	void Tijolo::sety(int a){
		y = a;
	}
	







