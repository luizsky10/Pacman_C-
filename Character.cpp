#include "Character.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

	Character::Character(){     // Construtor padrão
				characterLeft = al_load_bitmap("playerleft.png");
				characterRight = al_load_bitmap("playerright.png");
				characterUp = al_load_bitmap("playerup.png");
				characterDown = al_load_bitmap("playerdown.png");
				al_convert_mask_to_alpha(characterLeft ,al_map_rgb(0,0,0));
				al_convert_mask_to_alpha(characterRight ,al_map_rgb(0,0,0));
				al_convert_mask_to_alpha(characterUp ,al_map_rgb(0,0,0));
				al_convert_mask_to_alpha(characterDown ,al_map_rgb(0,0,0));
	}

	Character::Character(char* img, int a, int b, bool f1, bool f2, bool f3, bool f4, int c, int d) : Player(a,b,f1,f2,f3,f4,c,d){	// Construtor normal
			characterLeft = al_load_bitmap("playerleft.png");
			characterRight = al_load_bitmap("playerright.png");
			characterUp = al_load_bitmap("playerup.png");
			characterDown = al_load_bitmap("playerdown.png");
			al_convert_mask_to_alpha(characterLeft ,al_map_rgb(0,0,0));
			al_convert_mask_to_alpha(characterRight ,al_map_rgb(0,0,0));
			al_convert_mask_to_alpha(characterUp ,al_map_rgb(0,0,0));
			al_convert_mask_to_alpha(characterDown ,al_map_rgb(0,0,0));
	
	}
	Character::Character(Character& obj) : Player(obj){
			characterLeft = al_load_bitmap("playerleft.png");
			characterRight = al_load_bitmap("playerright.png");
			characterUp = al_load_bitmap("playerup.png");
			characterDown = al_load_bitmap("playerdown.png");
			al_convert_mask_to_alpha(characterLeft ,al_map_rgb(0,0,0));
			al_convert_mask_to_alpha(characterRight ,al_map_rgb(0,0,0));
			al_convert_mask_to_alpha(characterUp ,al_map_rgb(0,0,0));
			al_convert_mask_to_alpha(characterDown ,al_map_rgb(0,0,0));
	}
	Character::~Character(){}
	
	
	void Character::draw_characterLeft(){
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(characterLeft, momento, 0, 25, 25, getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}
	void Character::draw_characterRight(){
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(characterRight, momento, 0, 25, 25,getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}
	void Character::draw_characterUp(){
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(characterUp, momento, 0, 25, 25,getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}
	void Character::draw_characterDown(){
		if(get_quadro() > 2){
			set_quadro(0);
		}
		int momento = get_quadro() * 25;	// o momento recebe o quadro atual * 25 para encontrar qual a região que será exibida 
		al_draw_bitmap_region(characterDown, momento, 0, 25, 25, getx(),gety(), 0);  // Printo o atual momento da personagem
		set_quadro(get_quadro() +1);	// incremento o quadro;	
		}

		
		

	


	





