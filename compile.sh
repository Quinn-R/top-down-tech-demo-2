clear

clear

clear

g++ main.cpp inc/common.h inc/sfmlLoop.h inc/character.h inc/collideObject.h inc/stickers.h src/sfmlLoop.cpp src/character.cpp src/collideObject.cpp src/stickers.cpp -o obj/run -lsfml-graphics -lsfml-window -lsfml-system

cd obj

./run

cd ..
