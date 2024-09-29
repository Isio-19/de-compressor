#include "classeListe.hpp"
#include "classeArbre.hpp"

arbre::arbre(){
    r = NULL;
}

arbre::arbre(std::string nomFichier){
    liste listeFichier;
    int taille = 0;
    char *contenuFichier = listeFichier.readfile(nomFichier, taille);
    listeFichier.inserer_caracteres(contenuFichier, taille); 
    r = construireArbre(& listeFichier);
}

noeud *arbre::construireArbre(liste *tabNoeuds){
    noeud *noeudTete;
    do{
        noeud *noeudPP1 = tabNoeuds -> supprimer_p_petit();
        noeud *noeudPP2 = tabNoeuds -> supprimer_p_petit();
        std::cout << noeudPP1 -> c << noeudPP1 -> occ << " ";
        std::cout << noeudPP2 -> c << noeudPP2 -> occ << " "; 
        noeudTete = new noeud('\0', noeudPP1 -> occ + noeudPP2 -> occ, NULL, noeudPP1, noeudPP2);
        tabNoeuds -> inserer_tete(noeudTete);
    }while(noeudTete -> suivant != NULL);
    r = noeudTete;
    std::cout << std::endl;
    return noeudTete;
}

void arbre::codage(){
    char code[20];
    int size = 0;
    r -> visiter(code, size, codes);
}

void arbre::affichageCodes(){
    std::cout << std::endl;
    for(int i = 0; i<256; i++){
        if(codes[i] != ""){
            std::cout << "codes[" << i << "] " << char(i) << " " << codes[i] << std::endl;
        }
    }
}

std::string & arbre::codage(char *s, int N, double & taux_compression){
    std::string *stringReturn = new std::string ;
    for(int i = 0; i < N; i++) *stringReturn += codes[int(s[i])];    
    double tailleOriginale = N * 8;
    double tailleStringReturn = stringReturn -> length();
    taux_compression = ((tailleOriginale-tailleStringReturn)/tailleOriginale)*100;
    return *stringReturn;
}

char *arbre::binaire(std::string stringBinaire, int & tailleString){
    int compteur = 0;
    if(tailleString%8 != 0){
        int bitRestants = 8 - tailleString % 8;
        std::string stringPlusLong = "";
        for(int i = 0; i < 256; i++)
            if(stringPlusLong.length() < codes[i].length()) 
                stringPlusLong = codes[i];                          //on trouve le code le plus long pour completer le dernier octet du string à encoder
        for(int i = 0; i < bitRestants; i++){
            stringBinaire += stringPlusLong[i];
            tailleString++;
        }
    }
    char *tabBits = new char[tailleString/8];
    while(compteur < tailleString){                               //pour encoder tout le string 
        std::bitset<8> bitAChar(0);
        std::string morceauBinaire = stringBinaire.substr(compteur, 8);
        for(int i = 0; i<8; i++){
            std::string echantillonage = morceauBinaire.substr(i, 1);
            if(echantillonage == "1") bitAChar[7 - i] = 1;
        }
        char charObtenu = bitAChar.to_ulong();
        tabBits[compteur/8] = charObtenu;
        compteur += 8;
    }
    return tabBits;
}

void arbre::ecrireDansFichier(char *chaineAEcrire, std::string & destination){
    std::string nomFichier = destination;
    std::ofstream MyFile(nomFichier);
    MyFile << chaineAEcrire;
    MyFile.close();
}