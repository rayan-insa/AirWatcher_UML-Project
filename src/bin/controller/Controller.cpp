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
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
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
                    this->vue.afficherVue();
                    this->vue.afficherVueSansEntreeUtilisateur();
                }
                else if(entreeUtilisateur == 2){
                            texte = "Consulter la qualité de l'air\r\n\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            //this->vue.afficherVue();
                            texte = "latitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlatitude = this->vue.getEntreeUtilisateur();
                            long latitude = stol(strlatitude);

                            texte = "longitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlongitude = this->vue.getEntreeUtilisateur();
                            long longitude = stol(strlongitude);

                            texte = "date de début :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_debut = this->vue.getEntreeUtilisateur();
                            tm tm1={};
                            istringstream ss(strdate_debut);
                            ss >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
                            time_t date_debut = mktime(&tm1);
                            printf("date_debut : %s\n", asctime(localtime(&date_debut)));

                            texte = "date de fin :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_fin = this->vue.getEntreeUtilisateur();
                            tm tm2={};
                            istringstream ss2(strdate_fin);
                            ss2 >> get_time(&tm2, "%Y-%m-%d %H:%M:%S");
                            time_t date_fin = mktime(&tm2);
                            printf("date_fin: %s\n", asctime(localtime(&date_fin)));

                            texte = "rayon :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strrayon = this->vue.getEntreeUtilisateur();
                            int rayon = stoi(strrayon);
                            printf("rayon : %d\n", rayon);

                            string airQuality = this->model.getAirQuality(latitude, longitude, date_debut, date_fin, rayon);
                            texte = "La qualité de l'air est : " + airQuality + "\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                }
                else if(entreeUtilisateur == 8){
                    texte = "Identifier des capteurs défectueux :\r\n";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVueSansEntreeUtilisateur();

                    texte = "Entrez la marge d'erreur souhaitée :";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVue();
                    string marge_erreur_str = this->vue.getEntreeUtilisateur();
                    double marge_erreur = stod(marge_erreur_str);

                    texte = "Entrez la distance maximum souhaitée :";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVue();
                    string distance_str = this->vue.getEntreeUtilisateur();
                    double distance = stod(distance_str);

                    texte = "Entrez le ratio d'incohérence souhaité :";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVue();
                    string ratio_incoherence_str = this->vue.getEntreeUtilisateur();
                    double ratio_incoherence = stod(ratio_incoherence_str);
                    
                    //double marge_erreur = 20;
                    //double distance = 100;
                    //double ratio_incoherence = 0.4;
                    Data liste_capteurs = this->model.trouverCapteursDefaillants(marge_erreur, distance, ratio_incoherence);
                    vector<Capteur> liste_capteurs_defectueux = liste_capteurs.capteurs_defaillants;
                    vector<Capteur> liste_capteurs_potentiellement_defectueux = liste_capteurs.capteurs_potentiels;
                    vector<double> ratio_capt_def = liste_capteurs.ratio_capt_potentiels;
                    cout << "Il y a : " << liste_capteurs_defectueux.size() << " capteurs defaillants" << endl;
                    cout << "Il y a : " << liste_capteurs_potentiellement_defectueux.size() << " capteurs potentiellement defaillants" << endl;
                    while (1){
                        texte = "Choississez une option : \r\n";
                        texte += "1- Consulter les capteurs defaillants\r\n";
                        texte += "2- Consulter les capteurs potentiellement defaillants\r\n";
                        texte += "3- retour\r\n";
                        this->vue.setTexteVueCourante(texte);
                        this->vue.afficherVue();
                        entreeUtilisateur = stoi(this->vue.getEntreeUtilisateur());
                        if(entreeUtilisateur == 3){
                            break;
                        }
                        else if(entreeUtilisateur == 1){
                            texte = "Consulter les capteurs defaillants : \r\n";   
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            for (unsigned int i = 0; i < liste_capteurs_defectueux.size(); i++){
                                cout << liste_capteurs_defectueux[i] << endl;
                            }
                        }
                        else if(entreeUtilisateur == 2){
                            texte = "Consulter les capteurs potentiellement defaillants : \r\n";   
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            for (unsigned int i = 0; i < liste_capteurs_potentiellement_defectueux.size(); i++){
                                cout << liste_capteurs_potentiellement_defectueux[i] << "- ratio d'incoherence : " << ratio_capt_def[i] << endl;
                            }
                        }
                    }
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
                else if(entreeUtilisateur == 2){
                            texte = "Consulter la qualité de l'air\r\n\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            //this->vue.afficherVue();
                            texte = "latitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlatitude = this->vue.getEntreeUtilisateur();
                            long latitude = stol(strlatitude);

                            texte = "longitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlongitude = this->vue.getEntreeUtilisateur();
                            long longitude = stol(strlongitude);

                            texte = "date de début :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_debut = this->vue.getEntreeUtilisateur();
                            tm tm1={};
                            istringstream ss(strdate_debut);
                            ss >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
                            time_t date_debut = mktime(&tm1);
                            printf("date_debut : %s\n", asctime(localtime(&date_debut)));

                            texte = "date de fin :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_fin = this->vue.getEntreeUtilisateur();
                            tm tm2={};
                            istringstream ss2(strdate_fin);
                            ss2 >> get_time(&tm2, "%Y-%m-%d %H:%M:%S");
                            time_t date_fin = mktime(&tm2);
                            printf("date_fin: %s\n", asctime(localtime(&date_fin)));

                            texte = "rayon :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strrayon = this->vue.getEntreeUtilisateur();
                            int rayon = stoi(strrayon);
                            printf("rayon : %d\n", rayon);

                            string airQuality = this->model.getAirQuality(latitude, longitude, date_debut, date_fin, rayon);
                            texte = "La qualité de l'air est : " + airQuality + "\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                }
                else if(entreeUtilisateur == 8){
                    texte = "Identifier des capteurs défectueux :\r\n";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVueSansEntreeUtilisateur();

                    texte = "Entrez la marge d'erreur souhaitée :";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVue();
                    string marge_erreur_str = this->vue.getEntreeUtilisateur();
                    double marge_erreur = stod(marge_erreur_str);


                    texte = "Entrez la distance maximum souhaitée :";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVue();
                    string distance_str = this->vue.getEntreeUtilisateur();
                    double distance = stod(distance_str);

                    texte = "Entrez le ratio d'incohérence souhaité :";
                    this->vue.setTexteVueCourante(texte);
                    this->vue.afficherVue();
                    string ratio_incoherence_str = this->vue.getEntreeUtilisateur();
                    double ratio_incoherence = stod(ratio_incoherence_str);
                    
                    //double marge_erreur = 20;
                    //double distance = 100;
                    //double ratio_incoherence = 0.4;
                    Data liste_capteurs = this->model.trouverCapteursDefaillants(marge_erreur, distance, ratio_incoherence);
                    vector<Capteur> liste_capteurs_defectueux = liste_capteurs.capteurs_defaillants;
                    vector<Capteur> liste_capteurs_potentiellement_defectueux = liste_capteurs.capteurs_potentiels;
                    vector<double> ratio_capt_def = liste_capteurs.ratio_capt_potentiels;
                    cout << "Il y a : " << liste_capteurs_defectueux.size() << " capteurs defaillants" << endl;
                    cout << "Il y a : " << liste_capteurs_potentiellement_defectueux.size() << " capteurs potentiellement defaillants" << endl;
                    while (1){
                        texte = "Choississez une option : \r\n";
                        texte += "1- Consulter les capteurs defaillants\r\n";
                        texte += "2- Consulter les capteurs potentiellement defaillants\r\n";
                        texte += "3- retour\r\n";
                        this->vue.setTexteVueCourante(texte);
                        this->vue.afficherVue();
                        entreeUtilisateur = stoi(this->vue.getEntreeUtilisateur());
                        if(entreeUtilisateur == 3){
                            break;
                        }
                        else if(entreeUtilisateur == 1){
                            texte = "Consulter les capteurs defaillants : \r\n";   
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            for (unsigned int i = 0; i < liste_capteurs_defectueux.size(); i++){
                                cout << liste_capteurs_defectueux[i] << endl;
                            }
                        }
                        else if(entreeUtilisateur == 2){
                            texte = "Consulter les capteurs potentiellement defaillants : \r\n";   
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            for (unsigned int i = 0; i < liste_capteurs_potentiellement_defectueux.size(); i++){
                                cout << liste_capteurs_potentiellement_defectueux[i] << "- ratio d'incoherence : " << ratio_capt_def[i] << endl;
                            }
                        }
                    }
                }
            }
        }
        else {
            printf("entreeUtilisateur : %d\n", entreeUtilisateur);
            vector<Particulier> listeParticuliers = this->model.getListeParticuliers();
            //cout << this->model.getListeParticuliers()[0].getLogin() << endl;
            for(unsigned int i = 0 ; i<listeParticuliers.size(); i++){
                //cout << "gg" << endl;
                if(login.compare(listeParticuliers[i].getLogin()) == 0){
                    // MENU PARTICULIER
                    //cout << "gg" << endl;
                    while(1){
                        //cout << "gg" << endl;
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
                        else if(entreeUtilisateur == 2){
                            texte = "Consulter la qualité de l'air\r\n\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            //this->vue.afficherVue();
                            texte = "latitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlatitude = this->vue.getEntreeUtilisateur();
                            double latitude = stod(strlatitude);

                            texte = "longitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlongitude = this->vue.getEntreeUtilisateur();
                            double longitude = stod(strlongitude);

                            texte = "date de début :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_debut = this->vue.getEntreeUtilisateur();
                            tm tm1={};
                            istringstream ss(strdate_debut);
                            ss >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
                            time_t date_debut = mktime(&tm1);
                            printf("date_debut : %s\n", asctime(localtime(&date_debut)));

                            texte = "date de fin :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_fin = this->vue.getEntreeUtilisateur();
                            tm tm2={};
                            istringstream ss2(strdate_fin);
                            ss2 >> get_time(&tm2, "%Y-%m-%d %H:%M:%S");
                            time_t date_fin = mktime(&tm2);
                            printf("date_fin: %s\n", asctime(localtime(&date_fin)));

                            texte = "rayon :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strrayon = this->vue.getEntreeUtilisateur();
                            int rayon = stoi(strrayon);
                            printf("rayon : %d\n", rayon);

                            string airQuality = this->model.getAirQuality(latitude, longitude, date_debut, date_fin, rayon);
                            texte = "La qualité de l'air est : " + airQuality + "\r\n";
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
                        else if (entreeUtilisateur == 2){
                            texte = "Consulter la qualité de l'air\r\n\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVueSansEntreeUtilisateur();
                            //this->vue.afficherVue();
                            texte = "latitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlatitude = this->vue.getEntreeUtilisateur();
                            long latitude = stol(strlatitude);

                            texte = "longitude :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strlongitude = this->vue.getEntreeUtilisateur();
                            long longitude = stol(strlongitude);

                            texte = "date de début :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_debut = this->vue.getEntreeUtilisateur();
                            tm tm1={};
                            istringstream ss(strdate_debut);
                            ss >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
                            time_t date_debut = mktime(&tm1);
                            printf("date_debut : %s\n", asctime(localtime(&date_debut)));

                            texte = "date de fin :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strdate_fin = this->vue.getEntreeUtilisateur();
                            tm tm2={};
                            istringstream ss2(strdate_fin);
                            ss2 >> get_time(&tm2, "%Y-%m-%d %H:%M:%S");
                            time_t date_fin = mktime(&tm2);
                            printf("date_fin: %s\n", asctime(localtime(&date_fin)));

                            texte = "rayon :\r\n";
                            this->vue.setTexteVueCourante(texte);
                            this->vue.afficherVue();
                            string strrayon = this->vue.getEntreeUtilisateur();
                            int rayon = stoi(strrayon);
                            printf("rayon : %d\n", rayon);

                            string airQuality = this->model.getAirQuality(latitude, longitude, date_debut, date_fin, rayon);
                            texte = "La qualité de l'air est : " + airQuality + "\r\n";
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
Controller::Controller()
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Controller>" << endl;
#endif

    this->model = Model();
    this->vue = View();
}



Controller::~Controller()
{
#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
} //----- Fin de ~Controller
