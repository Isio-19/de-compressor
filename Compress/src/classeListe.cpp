#include "classeListe.hpp"

using namespace std;

liste::liste(){
    tete = NULL;
    nb_noeuds = 0;
}

void liste::inserer_tete(noeud *n){
    n -> suivant = tete;                //pour pointer vers à ce que pointe tete, donc le noeud suivant
    tete = n;                           //change tete pour qu'il pointe vers le nouveau noeud
    nb_noeuds++;    
}

void liste::inserer_tete(const char c, int effectif){
    noeud *noeudInsert = new noeud(c, effectif, NULL, NULL, NULL);
    this -> inserer_tete(noeudInsert);
}

void liste::inserer_caracteres(char *s, int taille){
    int tabEffectif[256];
    for(int i = 0; i<256; i++)                      //création du tableau des effectifs et initialisation à 0
        tabEffectif[i] = 0;                         
    for(int i = 0; i<taille; i++) 
        tabEffectif[int(s[i])]++;                   //incrémentation du tableau
    for(int i = 0; i<256; i++)
        if(tabEffectif[i] != 0)
            inserer_tete(char(i), tabEffectif[i]);
}

void liste::affichageListe(){
    if(tete != NULL){
        noeud *noeudAffichage = tete;
        while(noeudAffichage -> suivant != NULL){
            cout << noeudAffichage -> c << noeudAffichage -> occ << " ";
            noeudAffichage = noeudAffichage -> suivant;
        }
        cout << endl << "Fin de la liste" << endl;
    }
    else cout << "La liste est nulle!" << endl;
}

noeud *liste::supprimer_p_petit(){
    /*if(tete == NULL) return NULL;
    int occ_PP = tete -> occ;
    noeud *noeudPrecedent = NULL;
    noeud *noeudPP = NULL;
    noeud *noeudActuel = tete;
    while(noeudActuel){
        if((noeudActuel -> occ) < occ_PP){
            occ_PP = noeudActuel -> occ;
            noeudPP = noeudPrecedent;
        }
        noeudPrecedent = noeudActuel;
        noeudActuel = noeudActuel -> suivant;
    }
    if(noeudPP == NULL){
        noeudActuel = tete;
        tete = tete -> suivant;
        nb_noeuds--;
        return noeudActuel;
    }
    noeudActuel = noeudPP -> suivant;
    noeudPP -> suivant = noeudPP -> suivant -> suivant;
    nb_noeuds--;
    return noeudActuel;*/

    if(tete==NULL) return NULL;
    int plusPetiteOcc = tete -> occ;
    noeud *pred = NULL;
    noeud *ppred = NULL;
    noeud *C = tete;
    while(C){
        if(C -> occ < plusPetiteOcc){            //ici, C correspond au noeudActuel
            plusPetiteOcc = C -> occ;
            ppred=pred;
        }
        pred = C;
        C = C -> suivant;
    }
    if (ppred == NULL){                 //hors de la boucle, C correspond au noeud plus petit
        C = tete;                       //on mets C à ce que pointe tete, donc le noeud le plus petit puisque ppred n'a pas été actualisé
        tete = tete -> suivant;         //et on 'coupe' le chemin de tete à C
        nb_noeuds--;
        return C;
    }
    else{
        C = ppred -> suivant;                               //C est égal au noeud suivant du noeud qui se trouve avant le noeud PP (donc C == PP) 
        ppred -> suivant = ppred -> suivant -> suivant;     //on casse la liaison entre pred et le plus petit
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