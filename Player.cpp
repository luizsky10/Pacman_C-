#include "Player.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;										
// Construtores e Destrutores
			Player::Player(){
				x=1;
				y=1;
				quadro=0;
				tempo=0;
				mvRight = false;
				mvLeft = false;
				mvUp = false;
				mvDown =false;
				
			}

			Player::Player(int a, int b, bool f1, bool f2, bool f3, bool f4, int c, int d){
						x=a;
						y=b;
						mvRight = f1;
						mvLeft = f2;
						mvUp = f3;
						mvDown = f4;
						quadro =c;
						tempo =d;
			}
			Player::Player(Player& obj){
						x = obj.x;
						y = obj.y;
						mvRight = obj.mvRight;
						mvLeft = obj.mvLeft;
						mvUp = obj.mvUp;
						mvDown = obj.mvDown;
						quadro = obj.quadro;
						tempo = obj.tempo;
			}

			Player::~Player(){}
			/////////////////////////////////////////////////////////////////////////////////////
	
			// Get e set

			int Player::getx(){
				return x;
			}
			int Player::gety(){
				return y;
			}

			bool Player::getmvRight(){
				return mvRight;
			}
			bool Player::getmvLeft(){
				return mvLeft;
			}

			bool Player::getmvUp(){
				return mvUp;
			}

			bool Player::getmvDown(){
				return mvDown;
			}
			int Player::get_quadro(){
				return quadro;
			}
			int Player::get_tempo(){
				return tempo;
			}
			///////////////////////////////////////////////////////////////////////////////////
			void Player::set_quadro(int a){
				quadro = a;
			}
			void Player::set_tempo(int a){
				quadro = a;
			}
			
			
			
			
			void Player::setmvRight(bool s){
				mvRight = s;
			}
			void Player::setmvLeft(bool s){
				mvLeft = s;
			}
			void Player::setmvUp(bool s){
				mvUp = s;
			}
			void Player::setmvDown(bool s){
				mvDown = s;
			}

			void Player::sety(int b){
				y=b;
			}
			void Player::setx(int a){
				x=a;
			}









