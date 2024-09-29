#include <iostream>
#include <string>
#include <bitset>

#include "classeListe.hpp"
#include "classeArbre.hpp"

using namespace std;

int main(int argc, char* argv[]){
    /*
        cout << endl << "------ Test pour la fonction readfile ------" << endl;
            liste listeTest;
            int taille = 0;
            char *contenueFichier = listeTest.readfile("test.txt", taille);
            cout << "Contenue du fichier test.txt : "; 
            for(int i = 0; i < taille; i++) cout << contenueFichier[i];             //le cout de contenueFichier mettait les caratères en plus à la fin du cout
            cout << endl << "Taille du fichier : " << taille << endl;
        cout << "------ Fin du test pour la fonction readfile ------" << endl << endl;
    */
    
    /*
        cout << "------ Test pour la fonction inserer-caracteres ------" << endl;
            liste listeTest1;
            int taille1 = 0;
            char *contenueFichier1 = listeTest.readfile("test.txt", taille1);
            listeTest1.inserer_caracteres(contenueFichier1, taille1);               //on insert des caractères dans une liste
            listeTest1.affichageListe();
            liste listeTest2;
            char insererVide = char(' ');
            listeTest2.inserer_caracteres(& insererVide, 0);                        //on insert aucun caractère dans une liste pour vérifier que la fonction marche bien
            listeTest2.affichageListe();
        cout << "------ Fin du test pour la fonction inserer-caracteres ------" << endl << endl;
    */

    /*
        cout << "------ Test pour la fonction supprimer_p_petit ------" << endl;
            liste listeTest3;
            int taille3 = 0;
            char *contenueFichier3 = listeTest3.readfile("test.txt", taille3);
            listeTest3.inserer_caracteres(contenueFichier3, taille3+1);
            listeTest3.affichageListe();                                            //on affiche toute la liste
            noeud *noeudSuppr = listeTest3.supprimer_p_petit();                     //on supprime le noeud avec la plus petite occurence
            listeTest3.affichageListe();                                            //on affiche la liste sans le noeud supprimé
            cout << "Le noeud supprime est : ";
            noeudSuppr->afficheNoeud();                                             //on affiche le noeud qu'on a supprimé
        cout << "------ Fin du test pour la fonction supprimer_p_petit ------" << endl << endl;
    */

    /*
        cout << "------ Test pour la focntion construire_arbre ------" << endl;
            liste listeTest4;
            int taille4;
            char *contenueFichier4 = listeTest4.readfile("test.txt", taille4);
            listeTest4.inserer_caracteres(contenueFichier4, taille4);
            listeTest4.affichageListe();
            arbre arbreTest4;                                                       //on initialise un arbre
            arbreTest4.construireArbre(& listeTest4);                                //on construit ce dernier
        cout << endl << "------ Fin du test pour la fonction construire_arbre ------" << endl << endl;
        */

    /*
        cout << "------ Test pour le constructeur d'arbre et de la fonction visiter ------" << endl;
            arbre arbreTest5("test.txt");
            liste listeTest5; int taille5 = 0;
            char *contenueFichier5 = listeTest5.readfile("test.txt", taille5);
            listeTest5.inserer_caracteres(contenueFichier5, taille5);
            arbreTest5.construireArbre(& listeTest5);
            arbreTest5.codage();
            cout << "Resultat de codes[] : ";
            arbreTest5.affichageCodes();
        cout << endl << "------ Fin du test pour le constructeur d'arbre et de la fonction visiter ------" << endl << endl;
    */

    /*
        cout << "------ Test pour la fonction codage et binaire ------" << endl;
            double taux_compression = 0;
            arbre arbreTest6("textACompresser.txt");
            liste listeTest6;
            int taille6 = 0;
            char *contenueFichier6 = listeTest6.readfile("textACompresser.txt", taille6);
            cout << "Le contenu du fichier est : " << contenueFichier6 << endl;
            arbreTest6.codage();
            cout << "Resultat de codes[] : ";
            arbreTest6.affichageCodes();
            string messageApresComp = arbreTest6.codage(contenueFichier6, taille6, taux_compression);
            cout << "Le message avant la compression : " << contenueFichier6 << endl;
            cout << "Le message apres la compression : " << messageApresComp << endl;
            cout << "Le taux de compression est de : " << taux_compression << endl;
            int tailleCompr =  messageApresComp.length();
            char *tabChar = arbreTest6.binaire(messageApresComp, tailleCompr);
            for(int i = 0; i<tailleCompr/8; i++) cout << tabChar[i];
            arbreTest6.ecrireDansFichier(tabChar, "textCompr");
        cout << endl << "------ Fin du test pour la fonction codage et binaire ------" << endl << endl;
    */

    cout << "------ Test de la recuperation des arguments ------" << endl;
        string nomFichierBase = argv[2];
        string nomFichierDestination = argv[3];
        if(string(argv[1]) == "-c"){
                double taux_compression = 0;
                arbre arbreTest7(nomFichierBase);
                liste listeTest7;
                int taille7 = 0;
                char *contenueFichier7 = listeTest7.readfile(nomFichierBase, taille7);
                cout << "Le contenu du fichier est : " << contenueFichier7 << endl;
                arbreTest7.codage();
                cout << "Resultat de codes[] : ";
                arbreTest7.affichageCodes();
                string messageApresComp = arbreTest7.codage(contenueFichier7, taille7, taux_compression);
                cout << "Le message avant la compression : " << contenueFichier7 << endl;
                cout << "Le message apres la compression : " << messageApresComp << endl;
                cout << "Le taux de compression est de : " << taux_compression << endl;
                int tailleCompr =  messageApresComp.length();
                char *tabChar = arbreTest7.binaire(messageApresComp, tailleCompr);
                for(int i = 0; i<tailleCompr/8; i++) cout << tabChar[i];
                arbreTest7.ecrireDansFichier(tabChar, nomFichierDestination);
        }
        else if(string(argv[1]) == "-d"){
            cout << "Vous allez decompresser le fichier " << nomFichierBase << " pour le mettre dans " << nomFichierDestination << endl;
        }
        else{
            cout << "Le type d'action demande n'est pas reconnu" << endl;
        }

    cout << endl << "------ Fin de la recuperation des arguments  ------" << endl << endl;
    return 0;
}