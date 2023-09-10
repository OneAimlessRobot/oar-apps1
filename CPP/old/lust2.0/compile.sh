rm ./*.o



g++ -c lust.cpp -o resources/objects/lust.o -lm -lSDL2 -lSDL2_image -lpthread -g

./buildObjects.sh

g++ -g ./resources/objects/*.o -o lust `sdl2-config --cflags --libs` -lm -lSDL2 -lSDL2_image -lpthread

rm ./*.o
