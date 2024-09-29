#include "../include/classeNoeud.hpp"

noeud::noeud(const char a_c = '\0', int a_occ = 0, noeud *a_suiv = NULL, noeud *a_fg = NULL, noeud *a_fd = NULL){
    c = a_c;
    occ = a_occ;
    suivant = a_suiv;
    fg = a_fg;
    fd = a_fd;
}

void noeud::visiter(char code[20], int size, std::string codes[256]){
    if(this -> fg != NULL){
        code[size] = '0';
        this -> fg -> visiter(code, size+1, codes);
    }
    if(this -> fd != NULL){
        code[size] = '1';
        this -> fd -> visiter(code, size+1, codes);
    }   
    if(this -> c != '\0'){
        for(int i = 0; i<size; i++)
            codes[int(this -> c)] += code[i];
    }
}

void noeud::afficheNoeud(){
    std::cout << this -> c;
    std::cout << this -> occ << std::endl;
}