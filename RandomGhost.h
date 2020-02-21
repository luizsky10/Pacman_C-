#include <allegro5/allegro.h>
#ifndef RandomGhost_H
#define RandomGhost_H
#include "Ghost.h"
using namespace std;

class RandomGhost : public Ghost{
	
	public:
		RandomGhost();
		virtual ~RandomGhost();
		
	
		int get_intention();
		
		void set_intention(int);
		

		
	
	// Virtual
		virtual void getDirection(int mat[][20], Ghost **, Character*);
		virtual void MoveG(int mat[][20], Ghost **);
	private:	
		int intention =0;
};




#endif