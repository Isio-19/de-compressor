#ifndef classeNoeud
#define classeNoeud

#include <iostream>
#include <string>

class noeud{
    private:
        friend class liste;
        friend class arbre;
        int occ;
        char c;
        noeud *fg;
        noeud *fd;
        noeud *suivant;
    public:
        noeud(const char a_c, int a_occ, noeud *a_suiv, noeud *a_fg, noeud *a_fd);
        void visiter(char code[20], int size, std::string codes[256]);
        void afficheNoeud();
};

#endif