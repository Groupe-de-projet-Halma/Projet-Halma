Halma-Game: utilitaire.o donnees_partie.o partie.o jeu.o main.o
	gcc -o Halma-Game utilitaire.o donnees_partie.o partie.o jeu.o main.o -Wall
	rm -rf *.o

utilitaire.o: utilitaire.c
	gcc -o utilitaire.o -c utilitaire.c -Wall

donnees_partie.o: donnees_partie.c
	gcc -o donnees_partie.o -c donnees_partie.c -Wall

partie.o: partie.c
	gcc -o partie.o -c partie.c -Wall

jeu.o: jeu.c
	gcc -o jeu.o -c jeu.c -Wall

main.o: main.c
	gcc -o main.o -c main.c -Wall

clear:
	rm -rf *.o

