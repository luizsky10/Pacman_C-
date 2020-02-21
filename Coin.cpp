#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Coin.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h> 

	Coin::Coin(){
			x=1;
			y=1;
			quadro = 0;
			tempo = 0;
			coin = al_load_bitmap("sprite.png");
	}

	Coin::Coin(int a, int b){
		x=a;
		y=b;
		quadro=0;
		tempo = 0;
		coin = al_load_bitmap("sprite.png");

	}
	Coin::~Coin(){  
    }
    	
	
    int Coin::getquadro(){
		return quadro;
	}
	int Coin::gettempo(){
		return tempo;
	}
	int Coin::getx(){
		return x;
	}
	int Coin::gety(){
		return y;			
	}
	void Coin::setx(int a){
		x=a;
	}
	void Coin::sety(int a){
		y=a;
	}
	void Coin::settempo(int a){
		tempo = a;
	}
	void Coin::setquadro(int a){
		quadro=a;

	}

	void Coin::draw(){						
		if(quadro > 3){
			quadro = 0;
		}		
		int momento = quadro * 25;	// o momento recebe o quadro atual * 50 para encontrar qual a região que será exibida 
				
		al_draw_bitmap_region(coin, momento, 0, 25, 25, x, y, 0);  // Printo o atual momento da moeda
		quadro++;	// incremento o quadro;	
		}
		void Coin::setativa(bool a){
			exibir = a;
		}
		bool Coin::getativa(){
			return exibir;
		}
