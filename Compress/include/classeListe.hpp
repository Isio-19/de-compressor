#ifndef classeListe
#define classeListe

#include <fstream>
#include <iostream>
#include <string>
#include "classeNoeud.hpp"

class liste{
    
    private:
        noeud *tete;
        int nb_noeuds;
    public: 
        liste();
        void inserer_tete(noeud *n);
        void inserer_tete(char c, int effectif);
        void inserer_caracteres(char *s, int taille);
        void affichageListe();
        noeud *supprimer_p_petit();
        noeud *la_tete();
        char *readfile(const std::string & filename, int & taille);
        int nb_noeudsfonc();
};

#endif