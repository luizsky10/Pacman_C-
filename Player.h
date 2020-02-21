#ifndef PLAYER_H 
#define PLAYER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Player{
	
	public:
		Player();
		Player(int, int, bool, bool, bool, bool, int, int);
		Player(Player&);
		~Player();		
	
		int getx();
		int gety();
		int get_quadro();
		int get_tempo();
		
		bool getmvRight();
		bool getmvLeft();
		bool getmvUp();
		bool getmvDown();
		
		void setx(int);
		void sety(int);
		void set_quadro(int);
		void set_tempo(int);
		
		void setmvRight(bool);
		void setmvLeft(bool);
		void setmvUp(bool);
		void setmvDown(bool);
	
	private:
		int quadro;
		int tempo;
		int x,y;
		bool mvRight,mvLeft,mvUp, mvDown;
};




#endif