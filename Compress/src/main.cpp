#include <iostream>
#include <string>
#include <bitset>
#include <filesystem>

#include "../include/classeListe.hpp"
#include "../include/classeArbre.hpp"

bool checkFileExists(std::string fileName) {
    if (FILE *file = fopen(fileName.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
} 

int main(int argc, char* argv[]){
    if (argc != 3) {
        std::cout << "Mauvaise utilisation de la fonctionnalite du programme: compress inputFile outputFile" << std::endl;
        exit(1);
    }

    // check if the input file exists
    std::string nomFichierBase = argv[1];
    if (!checkFileExists(nomFichierBase)) {
        std::cout << "Le fichier source n'existe pas." << std::endl;
        exit(1);
    }

    // create the output directory, if needed
    std::string nomFichierDestination = argv[2];
    
    std::filesystem::path path = std::filesystem::path(nomFichierDestination);
    if (path.has_parent_path()) {
        std::string directory = path.parent_path();
        if (!checkFileExists(directory))
            std::filesystem::create_directories(directory);         
    }

    double taux_compression = 0;
    arbre arbre(nomFichierBase);
    liste liste;
    int taille = 0;

    char *contentFichier = liste.readfile(nomFichierBase, taille);
    // std::cout << "Le contenu du fichier est : " << contentFichier << std::endl;

    arbre.codage();
    // std::cout << "Resultat de codes[] : ";
    // arbre.affichageCodes();

    std::string messageApresComp = arbre.codage(contentFichier, taille, taux_compression);
    // std::cout << "Le message avant la compression : " << contentFichier << std::endl;
    // std::cout << "Le message apres la compression : " << messageApresComp << std::endl;
    // std::cout << "Le taux de compression est de : " << taux_compression << std::endl;

    int tailleCompr =  messageApresComp.length();

    char *tabChar = arbre.binaire(messageApresComp, tailleCompr);

    for(int i = 0; i<tailleCompr/8; i++)
        std::cout << tabChar[i];

    arbre.ecrireDansFichier(tabChar, nomFichierDestination);

    return 0;
}