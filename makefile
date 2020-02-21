
COMPILADOR=g++

CFLAGS=-Wall

LDFLAGS=-L/usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5` 

INCLUDE=-I/usr/local/include/allegro5

CODES=Tijolo.h Tijolo.cpp Coin.h Coin.cpp Player.h Player.cpp Character.h Character.cpp Ghost.h Ghost.cpp RandomGhost.h RandomGhost.cpp main.cpp 

EXE=load

all: projeto

clean:
	rm -rf *.o $(EXE)

projeto: $(CODES)
	$(COMPILADOR) $(CODES) -o $(EXE) $(INCLUDE) $(CFLAGS) $(LDFLAGS)


