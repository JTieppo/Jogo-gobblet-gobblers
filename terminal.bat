@echo off
gcc -I\allegro\include\ -c main.c
gcc -I\allegro\include\ main.o -o Jogo-Gobblet-Gobblers.exe .\liballegro_monolith.dll.a
Jogo-Gobblet-Gobblers