#include <allegro5/allegro.h>
#ifndef Tijolo_h
#define Tijolo_h

class Tijolo{
public:			
	Tijolo(); // C. Padrão
	Tijolo(int, int); // C. Normal
	Tijolo(const Tijolo &); // C. de Cópia
	~Tijolo(); // Destrutor	
	int getx();
	int gety();
	void setx(int);	
	void sety(int);	
	void desenhaTijolo();
	

private:
	int x,y;
	ALLEGRO_BITMAP *tijolo;	
};

#endif
