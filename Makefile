Halma-Game: utilitaire.o donnees_partie.o partie.o jeu.o main.o
	gcc -o Halma-Game utilitaire.o donnees_partie.o partie.o jeu.o main.o
	rm -rf *.o

utilitaire.o: utilitaire.c
	gcc -o utilitaire.o -c utilitaire.c -W -Wall

donnees_partie.o: donnees_partie.c
	gcc -o donnees_partie.o -c donnees_partie.c -W -Wall

partie.o: partie.c
	gcc -o partie.o -c partie.c -W -Wall

jeu.o: jeu.c
	gcc -o jeu.o -c jeu.c -W -Wall

main.o: main.c
	gcc -o main.o -c main.c -W -Wall

clear:
	rm -rf *.o

