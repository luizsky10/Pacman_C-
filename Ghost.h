#ifndef GHOST_H
#define GHOST_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Player.h"
#include "Character.h"


class Ghost : public Player{
	
	public:
		//CONSTRUTORES
		Ghost();
		Ghost(char *, int, int, bool, bool, bool, bool, int, int);
		Ghost(Ghost&);
		 virtual ~Ghost();
		
		void draw_GhostRight();
		void draw_GhostLeft();
		void draw_GhostUp();
		void draw_GhostDown();
	
	// Get
		int	get_direction();	

	// Set
		void set_direction(int);

	///////////////////////////////////////////
		virtual void getDirection(int mat[][20], Ghost **, Character*)=0;
		virtual void MoveG(int mat[][20], Ghost **)=0;
	

	
	
	private:
		ALLEGRO_BITMAP *GhostLeft;
		ALLEGRO_BITMAP *GhostRight;
		ALLEGRO_BITMAP *GhostUp;
		ALLEGRO_BITMAP *GhostDown;
		int direction;

};




#endif