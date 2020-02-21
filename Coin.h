#include <allegro5/allegro.h>
#ifndef Coin_h
#define Coin_h
class Coin{
public:
	Coin();
	Coin(int, int);
	~Coin();
	int getquadro(); // Quadro/estado
	int gettempo();  // Tempo/Estado	
	int getx(); 
	int gety();
	
	void setx(int);
	void sety(int);
	void setquadro(int);
	void settempo(int);
	void draw();
	bool getativa();
	void setativa(bool);
	void destroi();
	
private:
	int x, y;
	ALLEGRO_BITMAP *coin;
	int quadro;
	int tempo;
	bool exibir; //Mostra o estado atual da moeda 
};

#endif
