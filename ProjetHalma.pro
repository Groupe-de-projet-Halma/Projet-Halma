TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    utilitaire.c \
    jeu.c \
    partie.c \
    donnees_partie.c

HEADERS += \
    utilitaire.h \
    jeu.h \
    partie.h \
    donnees_partie.h
