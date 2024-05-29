/*************************************************************************
                Controller  -  Manipule le Controller
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Controller> (fichier Controller.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
#include <vector>
//------------------------------------------------------ Include personnel
using namespace std;
#include "Controller.h"
#include "View.h"
#include "Model.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Getters
Model  Controller::getModel() const {
    return model;
}

View  Controller::getView() const {
    return vue;
}


void Controller::mainControllerLoop(){

    int entreeUtilisateur;

    while(1){
        string texte = "Bienvenue sur AirWatcher - Application de gestion de capteurs qui permettent d\'évaluer la qualité de l\'air sur un large territoire\r\n La navigation dans l\'application se fera à l'aide de votre clavier numérique, en tapant des chiffres allant de 0 à 9.\r\n Pour vous connecter, entrez votre login : ";
    
        this->vue.setTexteVueCourante(texte);
        this->vue.afficherVue();
        string login = this->vue.getEntreeUtilisateur();

        if(login.find(".gouv") != string::npos){
            // MENU Gouvernement
            
            while(1){
                texte = "Vous êtes dans le menu Gouvernement, Vous souhaitez :\r\n";
                texte += "1- Consulter les données brutes\r\n";
                texte += "2- Consulter les statistiques sur les données\r\n";
                texte += "3- Sélectionner un capteur particulier\r\n";
                texte += "4- Sélectionner un utilisateur particulier\r\n";
                texte += "5- Sélectionner un Cleaner particulier\r\n";
                texte += "6- Commander un nouveau capteur\r\n";
                texte += "7- Commander un nouveau Cleaner\r\n";
                texte += "8- Identifier des capteurs défectueux\r\n";
                texte += "0- Se déconnecter\r\n";
                texte += "Rentrez le numéro de la commande que vous souhaitez exécuter :";

                this->vue.setTexteVueCourante(texte);
                this->vue.afficherVue();

                entreeUtilisateur = stoi(this->vue.getEntreeUtilisateur());

                if(entreeUtilisateur == 0){
                    texte = "Merci pour votre visite ! A bientôt sur AirWatcher !";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVueSansEntreeUtilisateur();
                    break;
                }
                else if(entreeUtilisateur == 1){
                    texte = "Consulter les données brutes\r\nPAS ENCORE IMPLEMENTEE\r\n\r\n";   
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVueSansEntreeUtilisateur();
                }
            }
        }

        else if(login.find(".admin") != string::npos ){
            // MENU ADMIN
            while(1){
                texte = "Vous êtes dans le menu ADMIN, Vous souhaitez :\r\n";
                texte += "1- Consulter les données brutes\r\n";
                texte += "2- Consulter les statistiques sur les données\r\n";
                texte += "3- Sélectionner un capteur particulier\r\n";
                texte += "4- Sélectionner un utilisateur particulier\r\n";
                texte += "5- Sélectionner un Cleaner particulier\r\n";
                texte += "6- Commander un nouveau capteur\r\n";
                texte += "7- Commander un nouveau Cleaner\r\n";
                texte += "8- Identifier des capteurs défectueux\r\n";
                texte += "9- Inscrire un nouveau Fournisseur\r\n";
                texte += "0- Se déconnecter\r\n";
                texte += "Rentrez le numéro de la commande que vous souhaitez exécuter :";

                this->vue.setTexteVueCourante(texte);
                this->vue.afficherVue();

                entreeUtilisateur = stoi(this->vue.getEntreeUtilisateur());

                if(entreeUtilisateur == 0){
                    texte = "Merci pour votre visite ! A bientôt sur AirWatcher !";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVueSansEntreeUtilisateur();
                    break;
                }
                else if(entreeUtilisateur == 1){
                    texte = "Consulter les données brutes\r\nPAS ENCORE IMPLEMENTEE\r\n\r\n";   
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVueSansEntreeUtilisateur();
                }
            }
        }
        else {
            vector<Particulier> listeParticuliers = this->model.getListeParticuliers();
            cout << this->model.getListeParticuliers()[0].getLogin() << endl;
            for(unsigned int i = 0 ; i<listeParticuliers.size(); i++){
                cout << "gg" << endl;
                if(login.compare(listeParticuliers[i].getLogin()) == 0){
                    // MENU PARTICULIER
                    cout << "gg" << endl;
                    while(1){
                        cout << "gg" << endl;
                        texte = "Bienvenue " + login + ", vous souhaitez :\r\n";
                        texte += "1- Consulter les données brutes\r\n";
                        texte += "2- Consulter les statistiques sur les données\r\n";
                        texte += "3- Consulter les données de votre capteur\r\n";
                        texte += "4- Commander un nouveau capteur\r\n";
                        texte += "5- Commander un nouveau Cleaner\r\n";
                        texte += "0- Se déconnecter\r\n";
                        texte += "Rentrez le numéro de la commande que vous souhaitez exécuter :";

                        this->vue.setTexteVueCourante(texte);
                        this->vue.afficherVue();    

                        entreeUtilisateur = stoi(this->vue.getEntreeUtilisateur());

                        if(entreeUtilisateur == 0){
                            texte = "Merci pour votre visite ! A bientôt sur AirWatcher !";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            break;
                        }
                        else if(entreeUtilisateur == 1){
                            texte = "Consulter les données brutes\r\nPAS ENCORE IMPLEMENTEE\r\n\r\n";   
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                        }
                    }
                    break;
                }
            }


            vector<Fournisseur> listeFournisseurs = this->model.getListeFournisseurs();
            for(unsigned int i = 0; i<listeFournisseurs.size(); i++){
                if(login.compare(listeFournisseurs[i].getNom()) == 0){
                    // MENU FOURNISSEUR
                    while(1){
                        texte = "Bienvenue " + login + ", vous souhaitez :\r\n";
                        texte += "1- Consulter les données brutes\r\n";
                        texte += "2- Consulter les statistiques sur les données\r\n";
                        texte += "3- Consulter les données de votre capteur\r\n";
                        texte += "4- Commander un nouveau capteur\r\n";
                        texte += "5- Commander un nouveau Cleaner\r\n";
                        texte += "0- Se déconnecter\r\n";
                        texte += "Rentrez le numéro de la commande que vous souhaitez exécuter :";

                        this->vue.setTexteVueCourante(texte);
                        this->vue.afficherVue();

                        entreeUtilisateur = stoi(this->vue.getEntreeUtilisateur());

                        if(entreeUtilisateur == 0){
                            texte = "Merci pour votre visite ! A bientôt sur AirWatcher !";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            break;
                        }
                        else if(entreeUtilisateur == 1){
                            texte = "Consulter les données brutes\r\nPAS ENCORE IMPLEMENTEE\r\n\r\n";   
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                        }
                    }
                    break;
                }
            }
        }


    }
    
}


//-------------------------------------------- Constructeurs - destructeur
Controller::Controller (  )
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Controller>" << endl;
#endif

    this->model = Model();
    this->vue = View();
}



Controller::~Controller ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
} //----- Fin de ~Controller
