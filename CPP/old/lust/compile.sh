rm ./*.o
g++ -c lust.cpp -o lust.o -lm -g
ld -r -b binary -o file.o resources/embeded/file.txt
ld -r -b binary -o file2.o resources/embeded/file2.txt
ld -r -b binary -o file3.o resources/embeded/file3.txt
ld -r -b binary -o password.o resources/embeded/password
ld -r -b binary -o musica.o resources/embeded/musica
ld -r -b binary -o splash.o resources/embeded/splash
ld -r -b binary -o img1.o resources/embeded/img1
ld -r -b binary -o img2.o resources/embeded/img2
ld -r -b binary -o img3.o resources/embeded/img3
ld -r -b binary -o kissing.o resources/embeded/kissing
ld -r -b binary -o kissing2.o resources/embeded/kissing2

g++ -g ./*.o -o lust `sdl2-config --cflags --libs` -lm -lSDL2 -lSDL2_image -lpthread

rm ./*.o