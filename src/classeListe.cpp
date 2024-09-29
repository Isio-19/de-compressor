#include "../include/classeListe.hpp"

using namespace std;

liste::liste() {
    tete = NULL;
    nb_noeuds = 0;
}

void liste::inserer_tete(noeud *n) {
    // pour pointer vers à ce que pointe tete, donc le noeud suivant
    n -> suivant = tete;                
    // change tete pour qu'il pointe vers le nouveau noeud
    tete = n;                           
    nb_noeuds++;    
}

void liste::inserer_tete(const char c, int effectif) {
    noeud *noeudInsert = new noeud(c, effectif, NULL, NULL, NULL);
    this -> inserer_tete(noeudInsert);
}

void liste::inserer_caracteres(char *s, int taille) {
    int tabEffectif[256];
    for(int i = 0; i<256; i++)                      
        // création du tableau des effectifs et initialisation à 0
        tabEffectif[i] = 0;                         

    for(int i = 0; i<taille; i++) 
        // incrémentation du tableau
        tabEffectif[int(s[i])]++;
    
    for(int i = 0; i<256; i++)
        if(tabEffectif[i] != 0)
            inserer_tete(char(i), tabEffectif[i]);
}

void liste::affichageListe() {
    if(tete != NULL) {
        noeud *noeudAffichage = tete;
        while(noeudAffichage -> suivant != NULL){
            cout << noeudAffichage -> c << noeudAffichage -> occ << " ";
            noeudAffichage = noeudAffichage -> suivant;
        }
        cout << endl << "Fin de la liste" << endl;
    }
    else cout << "La liste est nulle!" << endl;
}

noeud *liste::supprimer_p_petit() {
    if (tete==NULL) 
        return NULL;

    int plusPetiteOcc = tete -> occ;
    noeud *pred = NULL;
    noeud *ppred = NULL;
    noeud *C = tete;
    while (C) {
        // ici, C correspond au noeudActuel
        if(C -> occ < plusPetiteOcc){            
            plusPetiteOcc = C -> occ;
            ppred=pred;
        }
        pred = C;
        C = C -> suivant;
    }
    // hors de la boucle, C correspond au noeud plus petit
    if (ppred == NULL) {                 
        // on mets C à ce que pointe tete, donc le noeud le plus petit puisque ppred n'a pas été actualisé
        C = tete;                       
        // et on 'coupe' le chemin de tete à C
        tete = tete -> suivant;         
        nb_noeuds--;
        return C;
    }
    else {
        // C'est égal au noeud suivant du noeud qui se trouve avant le noeud PP (donc C == PP) 
        C = ppred -> suivant;                               
        // on casse la liaison entre pred et le plus petit
        ppred -> suivant = ppred -> suivant -> suivant;     
        nb_noeuds--;
        return C;
    }
}


noeud *liste::la_tete(){
    return tete;
}

char *liste::readfile(const string & filename, int & taille){
    ifstream f(filename);
    f.seekg(0, ios::end);
    taille = int(f.tellg());
    char *s = new char[taille];
    f.seekg(0, ios::beg);
    f.read(s, taille);
    f.close();

    return s;
}

int liste::nb_noeudsfonc(){
    return nb_noeuds;
}