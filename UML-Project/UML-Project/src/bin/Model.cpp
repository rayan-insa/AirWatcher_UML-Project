/*************************************************************************
                Model  -  Manipule le Model
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Model> (fichier Model.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Model.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


Controller Model::getController() const {
    return controller;
}

Gouvernement Model::getGouvernement() const {
    return gouv;
}

vector<Particulier> Model::getListeParticuliers() const {
    return listeParticuliers;
}

vector<Capteur> Model::getListeCapteurs() const {
    return listeCapteurs;
}

vector<Cleaner> Model::getListeCleaners() const {
    return listeCleaners;
}

vector<Fournisseur> Model::getListeFournisseurs() const {
    return listeFournisseurs;
}

vector<Mesure> Model::getListeMesures() const {
    return listeMesures;
}

Model::Model (  )
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Model>" << endl;
#endif
}

Model::Model ( Controller controller, Gouvernement gouv,  vector<Particulier> listeParticuliers, vector<Capteur> listeCapteurs, vector<Cleaner> listeCleaners, vector<Fournisseur> listeFournisseurs )
 : controller(controller), gouv(gouv), listeParticuliers(listeParticuliers), listeCapteurs(listeCapteurs), listeCleaners(listeCleaners), listeFournisseurs(listeFournisseurs)
{
#ifdef MAP
    cout << "Appel au constructeur de <Model>" << endl;
#endif
} //----- Fin de Model


Model::~Model ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Model>" << endl;
#endif
} //----- Fin de ~Model

vector<Capteur> Model::get_liste_capteurs_fiables(){
    // Cette fonction permet de donner la liste des capteurs dignes de confiance. 
    // Un capteur est considéré comme digne de confiance si son attribut defaillant = True. 
    // Retourne : un vecteur de capteurs dignes de confiance.
    vector<Capteur> liste_capteurs_fiables;
    for (int i = 0; i < listeCapteurs.size(); i++){
        Capteur capteur = listeCapteurs[i];
        if (capteur.getDefaillant()){
            liste_capteurs_fiables.push_back(capteur);
        }
    }
    return liste_capteurs_fiables;
}

vector<Capteur> Model::get_liste_capteurs_date(time_t date){
    // Cette fonction permet de donner la liste des capteurs qui contiennent des mesures à la date donnée en paramètre. 
    // Retourne : un vecteur de capteurs qui contiennent des mesures à la date donnée.
    vector<Capteur> liste_capteurs_date;
    for (int i = 0; i < listeMesures.size(); i++){
        Mesure mesure = listeMesures[i];
        if (mesure.getDate() == date && find(liste_capteurs_date.begin(), liste_capteurs_date.end(), mesure.getCapteur()) == liste_capteurs_date.end()){
            liste_capteurs_date.push_back(mesure.getCapteur());
        }
    }
    return liste_capteurs_date;
}

double Model::trouver_distance(long lat1, long lon1, long lat2, long lon2){
    // Cette fonction permet de calculer la distance entre deux points géographiques. 
    // Retourne : la distance entre les deux points.
    return sqrt(pow(lat1 - lat2, 2) + pow(lon1 - lon2, 2));
}

double Model::getValeurDateType(Capteur capteur, time_t date, string type){
    // Cette fonction permet de donner la valeur d’un type de mesure à une date donnée pour un capteur donné.
    for (int i=0; i<listeMesures.size(); i++){
        Mesure mesure = listeMesures[i];
        if (mesure.getDate() == date && mesure.getCapteur() == capteur && mesure.getTypeMesure() == type){
            return mesure.getValeur();
        }
    }
}


vector<double> Model::getIndiceATMO(long latitude, long longitude, time_t date, int rayon = 0){
    // Cette fonction permet de donner la moyenne des différents indicateur ATMO à un moment et un temps donné. 
    // Pour ce calcul, l’algorithme choisit parmi les capteurs dignes de confiance et qui contiennent des mesures à la date donnée en paramètre. 
    // Il effectue ensuite une moyenne pondérée de tous les capteurs situés dans un rayon de ”rayon” fois la distance du capteur le plus proche. 
    // Le rayon est initialisé à 0 si l’utilisateur cherche la valeur à un point précis.
    // Retourne : un tableau de 4 valeurs correspondant à la moyenne des indices O3, SO2, NO2 et PM10.

    vector<Capteur> liste_capteurs_fiables;
    liste_capteurs_fiables = get_liste_capteurs_fiables();

    vector<Capteur> liste_capteurs_date;
    liste_capteurs_date = get_liste_capteurs_date(date);

    vector<Capteur> liste_capteurs;
    for (int i = 0; i < liste_capteurs_fiables.size(); i++){
        if (find(liste_capteurs_date.begin(), liste_capteurs_date.end(), liste_capteurs_fiables[i]) != liste_capteurs_date.end()){
            liste_capteurs.push_back(*(liste_capteurs_fiables.begin() + i));
        }
    }

    vector<Capteur> capteurs_proches;
    for (int i = 0; i < liste_capteurs.size(); i++){
        Capteur capteur = liste_capteurs[i];
        double distance = trouver_distance(latitude, longitude, capteur.getLatitude(), capteur.getLongitude());
        if (distance < rayon){
            capteurs_proches.push_back(capteur);
        }
    }

    if (capteurs_proches.empty()){
        return vector<double>();
    }

    double somme_val_O3 = 0;
    double somme_val_SO2 = 0;
    double somme_val_NO2 = 0;
    double somme_val_PM10 = 0;
    double diviseur = 0;
    
    for (int i=0; i < capteurs_proches.size(); i++){
        double val_O3 = capteurs_proches[i].getValeurDateType(date, 'O3');
        somme_val_O3 += val_O3 * (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
        double val_SO2 = capteurs_proches[i].getValeurDateType(date, 'SO2');
        somme_val_SO2 += val_SO2 * (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
        double val_NO2 = capteurs_proches[i].getValeurDateType(date, 'NO2');
        somme_val_NO2 += val_NO2 * (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
        double val_PM10 = capteurs_proches[i].getValeurDateType(date, 'PM10');
        somme_val_PM10 += val_PM10 * (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
        diviseur += (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
    }

    somme_val_O3 /= diviseur;
    somme_val_SO2 /= diviseur;
    somme_val_NO2 /= diviseur;
    somme_val_PM10 /= diviseur;

    vector<double> moyenne_indice = {somme_val_O3, somme_val_SO2, somme_val_NO2, somme_val_PM10};
    return moyenne_indice;
}

