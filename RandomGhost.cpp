#include <allegro5/allegro.h>
#include "RandomGhost.h"
#include<time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
		
	


	RandomGhost::RandomGhost(){
				intention =0;
	}
	
	RandomGhost::~RandomGhost(){
	}

		int RandomGhost::get_intention(){
			return intention;
		}
		void RandomGhost::set_intention(int a){
			intention = a;
		}

		 void RandomGhost::getDirection(int mat[][20], Ghost **g1, Character *c1){
			 	srand(time(NULL));
			 	// 1 = Down; 2 = Up; 3 = Left; 4 = Right
			 
			 	if(get_direction() == 1 || get_direction() == 2 || get_direction() == 3 || get_direction() == 4  || mat[getx()/25][gety()/25 +1] == 0 || mat[getx()/25][gety()/25 -1] == 0 || mat[getx()/25 -1][gety()/25] 
				   		|| mat[getx()/25 +1][gety()/25] == 0){
					intention = rand() % 5;
					cout <<"Intention "<<intention << endl;
				}
			 
			 	for(int i=0; i++; i<3){
					if(get_direction() == 1 && g1[i]->getx() == getx() && g1[i]->gety()-25 == gety()){
						set_direction(2);
						if(get_direction() == 2 && mat[getx()/25][gety()/25 -1] == 1 && mat[getx()/25 -1][gety()/25] == 0)
							set_direction(3);
						else if(get_direction () == 3 && mat[getx()/25 -1][gety()/25] == 1 && mat[getx()/25 +1][gety()/25] == 0 )
							set_direction(4);
					
					}
			 		if(get_direction() == 2 && g1[i]->getx() == getx() && g1[i]->gety()+25 == gety()){
						set_direction(1);
						if(get_direction()==1 && mat[getx()/25][gety()/25 +1] == 1 &&  mat[getx()/25 -1][gety()/25] == 0 )
							set_direction(3);
						else if(get_direction()==3 && mat[getx()/25 -1][gety()/25] == 1 && mat[getx()/25 +1][gety()/25] == 0 )
							set_direction(4);
		 
					}	
					if(get_direction() == 3 && g1[i]->getx()+25 == getx() && g1[i]->gety() == gety()){
						set_direction(1);
						if(get_direction()==1 && mat[getx()/25][gety()/25 +1] == 1 && mat[getx()/25][gety()/25 -1] == 0)
							set_direction(2);
						else if(get_direction() == 2 && mat[getx()/25][gety()/25 - 1] == 1 && mat[getx()/25 +1][gety()/25] == 0)
							set_direction(4);
					}
					if(get_direction() == 4 && g1[i]->getx()-25 == getx() && g1[i]->gety() == gety())
						set_direction(1);
						if(get_direction() == 1 && mat[getx()/25][gety()/25 +1] == 1 && mat[getx()/25][gety()/25 -1] == 0)
							set_direction(2);
						else if(get_direction() == 2 && mat[getx()/25][gety()/25 -1] == 1 && mat[getx()/25 -1][gety()/25] == 0)
							set_direction(3);
				}
		 }


		void RandomGhost::MoveG(int mat[][20], Ghost **g1){
			int movespeed = 25;
			
				switch(get_direction()){			// De acordo com a direção movimenta o fantasma
				case 1:
					if(mat[getx()/25][gety()/25 +1] == 0){
						sety(gety() + movespeed);}
	
						if(intention == 4 && mat[getx()/25+1][gety()/25 ] == 0){
							set_direction(4);}
						else if(intention == 3 && mat[getx()/25-1][gety()/25 ] == 0){
							set_direction(3);}
						else if(mat[getx()/25 -1][gety()/25 ] == 0){
							set_direction(3);}
						else if(mat[getx()/25+1][gety()/25 ] == 0){
							set_direction(4);}							
		
						break;
				case 2:
					if(mat[getx()/25][gety()/25 -1] == 0){
						sety(gety() - movespeed);}

					if(intention == 3 && mat[getx()/25-1][gety()/25 ] == 0){
							set_direction(3);}
					else if(intention == 4 && mat[getx()/25+1][gety()/25 ] == 0){
							set_direction(4);}
					else if(mat[getx()/25 -1][gety()/25 ] == 0){
							set_direction(3);}
					else if(mat[getx()/25+1][gety()/25 ] == 0){
							set_direction(4);}				
	
						break;
				case 3:
					if(mat[getx()/25 -1][gety()/25] == 0)
						setx(getx() - movespeed);					
						
						if(intention == 2 && mat[getx()/25][gety()/25 -1] == 0){
							set_direction(2);
						}
						else if(intention == 1 && mat[getx()/25][gety()/25 +1] == 0){
							set_direction(1);}
						else if(mat[getx()/25][gety()/25 +1] == 0){
							set_direction(1);}	
						else if(mat[getx()/25][gety()/25 -1] == 0){
							set_direction(2);
						}	
							
						
						
					break;
				case 4:
					if(mat[getx()/25 +1][gety()/25] == 0){
						setx(getx() + movespeed);}
							
						if(intention == 2 && mat[getx()/25][gety()/25 -1] == 0){
							set_direction(2);
						}
						else if (intention == 1 && mat[getx()/25][gety()/25 +1] == 0){
							set_direction(1);}
						else if (mat[getx()/25][gety()/25 +1] == 0){
							set_direction(1);}
	
						else if(mat[getx()/25][gety()/25 -1] == 0){
							set_direction(2);}						
							
					break;					
			}
			if(get_direction() == 1){        // Desenha o personagem de acordo com a intenção
				draw_GhostDown();
			}
			if(get_direction() == 2){
				draw_GhostUp();
			}
			if(get_direction() == 3){
				draw_GhostLeft();
			}		
			if(get_direction() == 4){
				draw_GhostRight();
			}
			
			
		}
		
