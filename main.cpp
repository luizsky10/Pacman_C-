#include <iostream>
#include <string.h>
#include <vector>
#include "Tijolo.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include "Coin.h"
#include <stdlib.h>
#include <stdio.h>
#include "Character.h"
#include <allegro5/allegro_native_dialog.h>
#include "Ghost.h"
#include "RandomGhost.h"
#include "time.h"

using namespace std;


vector<Tijolo> t1;    // Variavel global referente ao objeto tijolo
vector<Coin> c1;      // Variavel global referente ao objeto Moeda 

void constroiMatriz(int matriz[][20]){
FILE *arq;
	char num[400];//tamanho total da matriz	
	arq=fopen("mapa.txt","r"); 
	if(arq==NULL){
		exit(1);
	} // checa se pode abrir arquivo
	for(int i=0;i<20;i++){	
 		 fgets(num,400,arq);
		 for(unsigned int j=0;j<strlen(num);j++){   // Percorre a matriz verificando se é 0 ou 1 a posição i/j
			if(num[j]=='1'){
				matriz[j][i]=1;}
			if(num[j]=='0'){
				matriz[j][i]=0;}
		 }
	}
	fclose(arq);  // Fecha o arquivo
}

void inicializaMatriz(int matriz[][20]){  // Inicializa a matriz
	int a, b; 
	for (a=0;a<20;a++){
		for (b=0;b<20;b++){
			matriz[a][b]=0;
		}
	}
}

void incrementaTijolo(int mat[][20], vector<Tijolo> &t1){ //Percorre o mapa(matriz), verifica quantos tijolos o mapa possui e incrementa o vector dos blocos
	Tijolo aux;
	for(int i=0; i<20;i++){
		for(int j=0; j<20; j++){
			if(mat[i][j] == 1){					
				aux.setx(i*25);
				aux.sety(j*25);
				t1.push_back(aux);				
			}									
		}
	}
}
void incrementaCoin(int mat[][20], vector<Coin> &c1){   // Percorre o mapa(matriz), verifica quantas moedas o mapa possui e incrementa o vector das moedas
	Coin aux;
	for(int i=0; i<20;i++){
		for(int j=0; j<20; j++){
			if(mat[i][j] == 0){
				aux.setx(i*25);
				aux.sety(j*25);				
				c1.push_back(aux);					
				c1[i].setativa(true);
			}		
		}
	}
}


const float FPS = 45;
const int SCREEN_W = 800;
const int SCREEN_H = 600;


int main(){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// INICIALIZANDO FUNÇÕES DA ALLEGRO E DE EVENTOS
	
	ALLEGRO_EVENT_QUEUE *fila_evento = NULL; // Criação do ponteiro de evento
	ALLEGRO_TIMER *timer = NULL;// Criação do ponteiro temporizador
   // Necessário para eventos do teclado
	cout <<"Teste"<<endl;
	al_init();   // Básica do allegro
	al_init_image_addon(); 	// Adicionar Imagens
	al_init_font_addon();
	    if (!al_init_ttf_addon()){
        	cout<<("Falha ao inicializar add-on allegro_ttf");
        return -1;
    }
	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(SCREEN_W, SCREEN_H);
	al_install_keyboard();
	ALLEGRO_FONT *fonte = NULL;
	fonte = al_load_font("arial.ttf", 20, 0);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// FIM DAS INICIALIZAÇÕES DO ALLEGRO
	
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// MATRIZES!!!
	
	int mat[20][20]; 		// Declaração da Matriz
   	inicializaMatriz(mat);		// Inicializa a Matriz
   	constroiMatriz(mat);		// Constroi a Matriz
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// FIM MATRIZES
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// INICIO DA CONSTRUÇÃO DOS BLOCOS E DAS MOEDAS
	
	unsigned int i;
	incrementaTijolo(mat, t1);   //Verifica e armazena quantos tijolos estao no mapa
	incrementaCoin(mat, c1);      // Verifica e armazena quantas Moedas estao no mapa

	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	// DIVERSOS NECESSÁRIOS
	Character C;
	C.setx(25);
	C.sety(25);
	int intention =0;
	int sentido =2;
	RandomGhost RG[4];
	Ghost *g1[4];
	g1[0] = &RG[0];
	g1[1] = &RG[1];
	g1[2] = &RG[2];
	g1[3] = &RG[3];
	g1[0]->setx(425);
	g1[0]->sety(450);
	g1[1]->setx(25);
	g1[1]->sety(450);
	g1[2]->setx(450);
	g1[2]->sety(25);
	g1[3]->setx(25);
	g1[3]->sety(25);
	
	
	//g1[1]->setx(400);
	//g1[1]->sety(450);
	g1[0]->set_direction(1);
	g1[1]->set_direction(1);
	g1[2]->set_direction(1);
	g1[3]->set_direction(1);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CRIAÇÃO DOS EVENTOS
	
	bool the_end = false;
	fila_evento = al_create_event_queue();
	timer = al_create_timer(7.0/ FPS);
   

	al_register_event_source(fila_evento, al_get_display_event_source(display));//Evento da Tela
	al_register_event_source(fila_evento, al_get_timer_event_source(timer));//Evento de tempo
    cout << "Teste2"<<endl;
	al_register_event_source(fila_evento, al_get_keyboard_event_source());//Evento de Teclado
	
	cout << "Teste"<<endl;
	int movespeed = 25;
	//int state = NULL;
	ALLEGRO_EVENT events;
	int cont =0;

	char texto[50] = " ";
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// LOOP PRINCIPAL
al_start_timer(timer);
	Coin caux;				//Objeto moeda auxiliar para apagar dinamicamente as moedas
	while(!the_end){						// Loop de Eventos
		cout <<C.getx() << " " << C.gety()<<endl;
		al_wait_for_event(fila_evento, &events);
		if(events.type == ALLEGRO_EVENT_TIMER) {
			al_clear_to_color(al_map_rgb(0,0,0));	
			for(i=0;i<t1.size();i++){   //Printa os tijolos
						t1[i].desenhaTijolo();
		    }
			cout <<mat[C.getx()/25][C.gety()/25+1]<<endl;
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
			
			
			switch(intention){			// De acordo com a intenção movimenta o personagem
				case 0:
					if(mat[C.getx()/25][C.gety()/25 +1] == 0){
						C.sety(C.gety() + movespeed);
					}	
					break;
					case 1:
					if(mat[C.getx()/25][C.gety()/25 -1] == 0)
						C.sety(C.gety() - movespeed);
					break;
				case 2:
					if(mat[C.getx()/25 -1][C.gety()/25] == 0)
						C.setx(C.getx() - movespeed);					
					break;
				case 3:
					if(mat[C.getx()/25 +1][C.gety()/25] == 0)
						C.setx(C.getx() + movespeed);					
					break;					
			}
			for(i=0;i<c1.size();i++){    //PRINTA AS MOEDAS	
				for(i=0;i<c1.size();i++){    //PRINTA AS MOEDAS
					if(c1[i].getx() == C.getx() && c1[i].gety() == C.gety()){
						if(c1[i].getativa() == true)
							cont++;
						c1[i].setativa(false);	
					}					
					if(c1[i].getativa() == true)
						c1[i].draw();
		  		 }
			}

			al_draw_textf(fonte, al_map_rgb(255, 255, 255), 700, 100, ALLEGRO_ALIGN_CENTRE, "Score: %d %s", cont, texto); // Printa o placar
			//cout <<"Intenção"<<intention<<endl;
			cout << "Placar"<<cont<<endl;
			if(intention == 0){        // Desenha o personagem de acordo com a intenção
				C.draw_characterDown();
			}
			if(intention == 1){
				C.draw_characterUp();
			}
			if(intention == 2){
				C.draw_characterLeft();
			}		
			if(intention == 3){
				C.draw_characterRight();
			}
		g1[0]->getDirection(mat, g1, &C);
		g1[0]->MoveG(mat, g1);
		g1[1]->getDirection(mat, g1, &C);
		g1[1]->MoveG(mat, g1);
		g1[2]->getDirection(mat, g1, &C);
		g1[2]->MoveG(mat, g1);
		g1[3]->getDirection(mat, g1, &C);
		g1[3]->MoveG(mat, g1);	
		for(int i=0;i<4;i++){
			if(C.getx() == g1[i]->getx() && C.gety() == g1[i]->gety())
				the_end = true;
		}
		
		
		}else{
			switch(events.keyboard.keycode){			// Recebe as entradas do teclado e seta o sentido de acordo com a entrada
				case ALLEGRO_KEY_DOWN:
						intention = 0;					
						break;
					case ALLEGRO_KEY_UP:
						intention =1;
						break;
					case ALLEGRO_KEY_RIGHT:
						intention =3;
						break;
					case ALLEGRO_KEY_LEFT:
						intention =2;
						break;
					case ALLEGRO_KEY_ESCAPE:
						the_end = true;
						break;
				}
		}
		
		
		
		//al_draw_textf(font20, al_map_rgb(255,255,0),700,250,0,"Score: %d", cont);
		al_flip_display(); // Mostra a tela	s
	}
	al_destroy_display(display);
	al_destroy_event_queue(fila_evento);//Destroi o ponteiro fila de eventos
	al_destroy_timer(timer);
	//al_destroy_font(font20);				  
	return 0;
}


