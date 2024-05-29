#include <string>
#include <iostream>

using namespace std;

//CREER UNE LISTE DES LOGINS POUR VERIF

int main(){
    while(1){
        cout << "Bienvenue sur AirWatcher - Application de gestion de capteurs qui permettent d’évaluer la qualité de l’air sur un large territoire"<< endl;
        cout << "La navigation dans l’application se fera à l’aide de votre clavier numérique, en tapant des chiffres allant de 0 à 9." << endl;
        cout << "Pour vous connecter, entrez votre login et votre mot de passe : " << endl;
        string login;
        string mdp;
        cin >> login;
        cin >> mdp;
        string idgouv = ".gouv";
        string idfournisseur = ".pro";
        string idadmin = ".admin";
        if (login.find(idgouv) != string::npos){
            //MENU GOUVERNEMENT
            cout << "Vous êtes dans le menu Gouvernement, Vous souhaitez :" << endl;
            while (1){
                cout << "1- Consulter les données brutes"<< endl;
                cout << "2- Consulter les statistiques sur les données"<< endl;
                cout << "3- Sélectionner un capteur particulier"<< endl;
                cout << "4- Sélectionner un utilisateur particulier"<< endl;
                cout << "5- Sélectionner un Cleaner particulier"<< endl;
                cout << "6- Commander un nouveau capteur"<< endl;
                cout << "7- Commander un nouveau Cleaner"<< endl;
                cout << "8- Identifier des capteurs défectueux"<< endl;
                cout << "0- Se déconnecter"<< endl;
                cout << "Rentrez le numéro de la commande que vous souhaitez exécuter :" <<endl;
                int entree;
                cin >> entree;
                if (entree == 1){

                }
                if (entree == 2){
                    
                }
                if (entree == 3){
                    
                }
                if (entree == 4){
                    
                }
                if (entree == 5){
                    
                }
                if (entree == 6){
                    
                }
                if (entree == 7){
                    
                }
                if (entree == 8){
                    
                }
                if (entree == 0){
                    cout << "Merci pour votre visite ! A bientôt sur AirWatcher !" <<endl;
                    break;
                }
            }
        }
        else if (login.find(idadmin) != string::npos){
            //MENU ADMIN
            cout << "Bienvenue" << login << ", vous souhaitez :" << endl;
            while(1){
                cout << "1- Consulter les données brutes"<< endl;
                cout << "2- Consulter les statistiques sur les données"<< endl;
                cout << "3- Sélectionner un capteur particulier"<< endl;
                cout << "4- Sélectionner un utilisateur particulier"<< endl;
                cout << "5- Sélectionner un Cleaner particulier"<< endl;
                cout << "6- Commander un nouveau capteur"<< endl;
                cout << "7- Commander un nouveau Cleaner"<< endl;
                cout << "8- Identifier des capteurs défectueux"<< endl;
                cout << "9- Inscrire un nouveau Fournisseur" << endl;
                cout << "0- Se déconnecter"<< endl;
                cout << "Rentrez le numéro de la commande que vous souhaitez exécuter :" <<endl;
                int entree;
                cin >> entree;
                if (entree == 1){

                }
                if (entree == 2){
                    
                }
                if (entree == 3){
                    
                }
                if (entree == 4){
                    
                }
                if (entree == 5){
                    
                }
                if (entree == 6){
                    
                }
                if (entree == 7){
                    
                }
                if (entree == 8){
                    
                }
                if (entree == 9){
                    
                }
                if (entree == 0){
                    cout << "Merci pour votre visite ! A bientôt sur AirWatcher !" <<endl;
                    break;
                }
            }
        }
        else if (login.find(idfournisseur) != string::npos){
            //MENU FOURNISSEUR
            cout << "Bienvenue" << login << ", vous souhaitez :" << endl;
            while(1){
                cout << "1- Voir l’historique des commandes passées"<< endl;
                cout << "2- Voir les statistiques sur les Cleaners fournis"<< endl;
                cout << "3- Voir les statistiques sur les capteurs fournis" << endl;
                cout << "0- Se déconnecter"<< endl;
                cout << "Rentrez le numéro de la commande que vous souhaitez exécuter :" <<endl;
                int entree;
                cin >> entree;
                if (entree == 1){
                    
                }
                if (entree == 2){
                    
                }
                if (entree == 3){
                    
                }
                if (entree == 0){
                    cout << "Merci pour votre visite ! A bientôt sur AirWatcher !" <<endl;
                    break;
                }
            }
        }
        else{
            //MENU PARTICULIER
            cout << "Bienvenue " << login << ", vous souhaitez :" << endl;
            while(1){
                cout << "1- Installer un capteur"<< endl;
                cout << "2- Consulter les données brutes"<< endl;
                cout << "3- Consulter les statistiques générales"<< endl;
                cout << "4- Consulter les statistiques sur ses capteurs"<< endl;
                cout << "5- Sélectionner un capteur"<< endl;
                cout << "6- Commander un nouveau capteur"<< endl;
                cout << "0- Se déconnecter"<< endl;
                cout << "Rentrez le numéro de la commande que vous souhaitez exécuter :" <<endl;
                int entree;
                cin >> entree;
                if (entree == 1){

                }
                if (entree == 2){
                    
                }
                if (entree == 3){
                    
                }
                if (entree == 4){
                    
                }
                if (entree == 5){
                    
                }
                if (entree == 6){
                    
                }
                if (entree == 0){
                    cout << "Merci pour votre visite ! A bientôt sur AirWatcher !" <<endl;
                    break;
                }
            }
        }
    }

}


