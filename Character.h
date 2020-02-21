#ifndef CHARACTER_H
#define CHARACTER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Player.h"
class Character : public Player{
	public:
					// Construtores
		Character();
		Character(char*, int, int, bool, bool, bool, bool, int, int);
		Character(Character&);
		~Character();
        			// Get e set

		void draw_characterRight();
		void draw_characterLeft();
		void draw_characterUp();
		void draw_characterDown();
		
	
		//bool coalizao(int&);

	private:
		ALLEGRO_BITMAP *characterLeft;
		ALLEGRO_BITMAP *characterRight;
		ALLEGRO_BITMAP *characterUp;
		ALLEGRO_BITMAP *characterDown;
};

#endif
