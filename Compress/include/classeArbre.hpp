#ifndef classeArbre
#define classeArbre

#include <fstream>
#include <iostream>
#include <string>
#include <bitset>
#include "classeListe.hpp"

class arbre{
    private:
        noeud *r;
        std::string codes[256];
    public:
        arbre();
        arbre(std::string nomFichier);
        noeud *construireArbre(liste *tabNoeuds);
        void codage();
        void affichageCodes();
        std::string & codage(char *s, int N, double & taux_compression);
        char *binaire(std::string stringBinaire, int & tailleString);
        void ecrireDansFichier(char *chaineAEcrire, std::string & destination);
};

#endif