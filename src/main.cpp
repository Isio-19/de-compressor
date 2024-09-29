#include <iostream>
#include <string>
#include <bitset>
#include <filesystem>
#include <map>

#include "../include/classeListe.hpp"
#include "../include/classeArbre.hpp"

bool checkFileExists(std::string fileName);
void compress(std::string & inputFileName, std::string & outputFileName); 
void decompress(std::string & inputFileName, std::string & outputFileName); 

bool checkFileExists(std::string fileName) {
    if (FILE *file = fopen(fileName.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
} 

void compress(std::string & inputFileName, std::string & outputFileName) {
    double taux_compression = 0;
    arbre arbre(inputFileName);
    liste liste;
    int taille = 0;

    char *contentFichier = liste.readfile(inputFileName, taille);
    // std::cout << "Le contenu du fichier est : " << contentFichier << std::endl;

    arbre.codage();
    // std::cout << "Resultat de codes[] : ";
    arbre.affichageCodes();

    std::string messageApresComp = arbre.codage(contentFichier, taille, taux_compression);
    // std::cout << "Le message avant la compression : " << contentFichier << std::endl;
    // std::cout << "Le message apres la compression : " << messageApresComp << std::endl;
    // std::cout << "Le taux de compression est de : " << taux_compression << std::endl;

    int tailleCompr =  messageApresComp.length();

    char *tabChar = arbre.binaire(messageApresComp, tailleCompr);

    for(int i = 0; i<tailleCompr/8; i++)
        std::cout << tabChar[i];

    arbre.ecrireDansFichier(tabChar, outputFileName);
}

void decompress(std::string & inputFileName, std::string & outputFileName) {

}

int main(int argc, char* argv[]){
    if (argc != 4) {
        std::cout << "Mauvaise utilisation de la fonctionnalite du programme: prog {-c | -d} inputFile outputFile" << std::endl;
        exit(1);
    }

    enum Action {
        COMPRESS,
        DECOMPRESS
    };

    std::map<std::string, Action> action = {
        {"-c", COMPRESS}, 
        {"-d", DECOMPRESS},
    };

    if (std::string(argv[1]) != "-c" && std::string(argv[1]) != "-d") {
        std::cout << "Action non reconnue, veuillez utiliser -c ou -d" << std::endl;
        exit(1);    
    }

    Action chosenAction = action[std::string(argv[1])];

    // check if the input file exists
    std::string nomFichierBase = argv[2];
    if (!checkFileExists(nomFichierBase)) {
        std::cout << "Le fichier source n'existe pas." << std::endl;
        exit(1);
    }

    // create the output directory, if needed
    std::string nomFichierDestination = argv[3];
    
    std::filesystem::path path = std::filesystem::path(nomFichierDestination);
    if (path.has_parent_path()) {
        std::string directory = path.parent_path();
        if (!checkFileExists(directory))
            std::filesystem::create_directories(directory);         
    }

    // switch between compress and uncompress
    if (chosenAction == COMPRESS) 
        compress(nomFichierBase, nomFichierDestination);
        return 0;

    decompress(nomFichierBase, nomFichierDestination);
    return 0;
}