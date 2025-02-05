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
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#define PI 3.14159265358979323846

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Model::setGouvernement(const Gouvernement & gouvernement)
{
    this->gouv = gouvernement;
}

void Model::setListeParticuliers(const vector<Particulier> & liste)
{
    this->listeParticuliers = liste;
}

void Model::setListeCapteurs(const vector<Capteur> & liste)
{
    this->listeCapteurs = liste;
}

void Model::setListeCleaners(const vector<Cleaner> & liste)
{
    this->listeCleaners = liste;
}

void Model::setListeFournisseurs(const vector<Fournisseur> & liste)
{
    this->listeFournisseurs = liste;
}

void Model::setListeMesures(const vector<Mesure> & liste)
{
    this->listeMesures = liste;
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
    
    gouv = Gouvernement();
    ifstream file("../dataset/users.csv");

    if (!file.is_open())
    {
        cerr << "Error: Could not open file users.csv" << endl;
        return;
    }
    string line1;
    while (getline(file, line1))
    {
        size_t pos = line1.find(';');
        if (pos != string::npos) {
            string user = line1.substr(0, pos);
            string sensor = line1.substr(pos + 1);
            Particulier particulier = Particulier(user, 0, true);
            Capteur capteur = Capteur(sensor, 0, 0, true, particulier);
            listeParticuliers.push_back(particulier);
            listeCapteurs.push_back(capteur);
        }
    }
    file.close();

    ifstream file2("../dataset/sensors.csv");
    if (!file2.is_open())
    {
        cerr << "Error: Could not open file sensors.csv" << endl;
        return;
    }
    string line2;
    while (getline(file2, line2))
    {
        stringstream ss(line2);
        string id;
        string latitude;
        string longitude;

        if (getline(ss, id, ';') && getline(ss, latitude, ';') && getline(ss, longitude, ';')) {
            
            double lat = stod(latitude);
            double lon = stod(longitude);
            
            bool flag = false;
            for(unsigned int i = 0; i < listeCapteurs.size(); i++) {
                if (listeCapteurs[i].getId() == id) {
                    listeCapteurs[i].setLatitude(lat);
                    listeCapteurs[i].setLongitude(lon);
                    flag = true;
                    break;
                }
            }
            if(!flag) {  
                Capteur capteur = Capteur(id, lat, lon, false, Gouvernement());
                listeCapteurs.push_back(capteur);
                }

        }
    }

    file.close();


    ifstream file3("../dataset/providers.csv");
    if (!file3.is_open())
    {
        cerr << "Error: Could not open file providers.csv" << endl;
        return;
    }
    string line3;
    while (getline(file3, line3))
    {
        size_t pos = line3.find(';');
        if (pos != string::npos) {
            string provider = line3.substr(0, pos);
            string sensor = line3.substr(pos + 1);
            Fournisseur fournisseur = Fournisseur(provider);
            time_t time = 0;
            Cleaner cleaner = Cleaner(sensor, 0, 0, time, time, fournisseur);
            listeFournisseurs.push_back(fournisseur);
            listeCleaners.push_back(cleaner);
        }
    }
    file3.close();

    
    ifstream file4("../dataset/cleaners.csv");
    if (!file4.is_open())
    {
        cerr << "Error: Could not open file cleaners.csv" << endl;
        return;
    }
    string line4;
    while (getline(file4, line4))
    {
        stringstream ss(line4);
        string id;
        string latitude;
        string longitude;
        string time_stamp_start;
        string time_stamp_end;

        if (getline(ss, id, ';') && getline(ss, latitude, ';') && getline(ss, longitude, ';') && getline(ss, time_stamp_start, ';') && getline(ss, time_stamp_end, ';')){

            double lat = stod(latitude);
            double lon = stod(longitude);
            tm tm1={};
            istringstream ss(time_stamp_start);
            ss >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
            time_t start = mktime(&tm1);
            tm tm2={};
            istringstream ss2(time_stamp_end);
            ss2 >> get_time(&tm2, "%Y-%m-%d %H:%M:%S");
            time_t end = mktime(&tm2);


            for (unsigned int i=0; i<listeCleaners.size(); i++) {
                if (listeCleaners[i].getId() == id) {
                    listeCleaners[i].setLatitude(lat);
                    listeCleaners[i].setLongitude(lon);
                    listeCleaners[i].setTimestampStart(start);
                    listeCleaners[i].setTimestampStop(end);
                }
                else {
                    Cleaner cleaner = Cleaner(id, lat, lon, start, end, Fournisseur());
                    listeCleaners.push_back(cleaner);
                }
            }
        }
    }
    file4.close();

    ifstream file5("../dataset/measurements.csv");
    if (!file5.is_open())
    {
        cerr << "Error: Could not open file measures.csv" << endl;
        return;
    }
    string line5;
    while (getline(file5, line5))
    {
        stringstream ss(line5);
        string sensor;
        string date;
        string type;
        string value;

        if (getline(ss, date, ';') && getline(ss, sensor, ';') && getline(ss, type, ';') && getline(ss, value, ';')){

            tm tm1={};
            istringstream ss(date);
            ss >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
            time_t time = mktime(&tm1);
            double val = stod(value);
            for (unsigned int i=0; i<listeCapteurs.size(); i++) {
                if (listeCapteurs[i].getId() == sensor) {
                    Mesure mesure = Mesure(time, type, val, listeCapteurs[i]);
                    listeMesures.push_back(mesure);
                }
            }
        }
    }
    file5.close();

}


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
    for (unsigned int i = 0; i < listeCapteurs.size(); i++){
        Capteur capteur = listeCapteurs[i];
        if (capteur.getDefaillant() == 0){
            liste_capteurs_fiables.push_back(capteur);
        }
    }
    return liste_capteurs_fiables;
}

vector<Capteur> Model::get_liste_capteurs_date(time_t date){
    // Cette fonction permet de donner la liste des capteurs qui contiennent des mesures à la date donnée en paramètre. 
    // Retourne : un vecteur de capteurs qui contiennent des mesures à la date donnée.
    vector<Capteur> liste_capteurs_date;
    for (unsigned int i = 0; i < listeMesures.size(); i++){
        Mesure mesure = listeMesures[i];
        if (mesure.getDate() == date && find(liste_capteurs_date.begin(), liste_capteurs_date.end(), mesure.getCapteur()) == liste_capteurs_date.end()){
            liste_capteurs_date.push_back(mesure.getCapteur());
        }
    }
    return liste_capteurs_date;
}

double Model::trouver_distance(double lat1, double lon1, double lat2, double lon2){
    // Convert the latitudes and longitudes from degrees to radians.
    lat1 = lat1 * PI / 180;
    lon1 = lon1 * PI / 180;
    lat2 = lat2 * PI / 180;
    lon2 = lon2 * PI / 180;

    // Earth's radius in kilometers
    double R = 6371.0;

    // Calculate the differences between the coordinates
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Haversine formula
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Calculate the distance
    double distance = R * c;

    return distance;
}

double Model::getValeurDateType(Capteur capteur, time_t date, string type){
    // Cette fonction permet de donner la valeur d’un type de mesure à une date donnée pour un capteur donné.
    for (unsigned int i=0; i<listeMesures.size(); i++){
        Mesure mesure = listeMesures[i];
        if (mesure.getDate() == date && mesure.getCapteur() == capteur && mesure.getTypeMesure() == type){
            return mesure.getValeur();
        }
    }

    return -1;
}


vector<double> Model::getIndiceATMO(double latitude, double longitude, time_t date, int rayon){
    // Cette fonction permet de donner la moyenne des différents indicateur ATMO à un moment et un temps donné. 
    // Pour ce calcul, l’algorithme choisit parmi les capteurs dignes de confiance et qui contiennent des mesures à la date donnée en paramètre. 
    // Il effectue ensuite une moyenne pondérée de tous les capteurs situés dans un rayon de ”rayon” fois la distance du capteur le plus proche. 
    // Le rayon est initialisé à 0 si l’utilisateur cherche la valeur à un point précis.
    // Retourne : un tableau de 4 valeurs correspondant à la moyenne des indices O3, SO2, NO2 et PM10.

    vector<Capteur> liste_capteurs_fiables;
    liste_capteurs_fiables = get_liste_capteurs_fiables();
    vector<Capteur> liste_capteurs_date;
    liste_capteurs_date = get_liste_capteurs_date(date);
    liste_capteurs_date = get_liste_capteurs_date(date);

    vector<Capteur> liste_capteurs;
    for (unsigned int i = 0; i < liste_capteurs_fiables.size(); i++){
        if (find(liste_capteurs_date.begin(), liste_capteurs_date.end(), liste_capteurs_fiables[i]) != liste_capteurs_date.end()){
            liste_capteurs.push_back(*(liste_capteurs_fiables.begin() + i));
        }
    }

    vector<Capteur> capteurs_proches;
    for (unsigned int i = 0; i < liste_capteurs.size(); i++){
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
    
    for (unsigned int i=0; i < capteurs_proches.size(); i++){
        double val_O3 = getValeurDateType(capteurs_proches[i], date, "O3");
        somme_val_O3 += val_O3 * (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
        double val_SO2 = getValeurDateType(capteurs_proches[i], date, "SO2");
        somme_val_SO2 += val_SO2 * (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
        double val_NO2 = getValeurDateType(capteurs_proches[i], date, "NO2");
        somme_val_NO2 += val_NO2 * (rayon - trouver_distance(latitude, longitude, capteurs_proches[i].getLatitude(), capteurs_proches[i].getLongitude()));
        double val_PM10 = getValeurDateType(capteurs_proches[i], date, "PM10");
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

string Model::calculer_indice_ATMO(double val_O3, double val_SO2, double val_NO2, double val_PM10){
    // Cette fonction permet de calculer l’indice ATMO à partir des valeurs de O3, SO2, NO2 et PM10.
    // Retourne : l’indice ATMO.
    if (val_O3 == -1 || val_SO2 == -1 || val_NO2 == -1 || val_PM10 == -1){
        return("Aucune donnée pour cette période et cette zone");
    }
    else if (val_O3 > 800.0 || val_SO2 > 1600.0 || val_NO2 > 340.0 || val_PM10 > 200.0){
        return("Extrêmement dangereux");
    }
    else if (val_O3 > 380.0 || val_SO2 > 750.0 || val_NO2 > 340.0 || val_PM10 > 150.0){
        return("Extrêmement mauvais");
    }
    else if (val_O3 > 240.0 || val_SO2 > 500.0 || val_NO2 > 230.0 || val_PM10 > 100.0){
        return("Très mauvais");
    }
    else if (val_O3 > 130.0 || val_SO2 > 350.0 || val_NO2 > 120.0 || val_PM10 > 50.0){
        return("Mauvais");
    }
    else if (val_O3 > 100.0 || val_SO2 > 200.0 || val_NO2 > 90.0 || val_PM10 > 40.0){
        return("Dégradé");
    }
    else if (val_O3 > 50.0 || val_SO2 > 100.0 || val_NO2 > 40.0 || val_PM10 > 20.0){
        return("Moyen");
    }
    else {
        return("Bon");
    }
}

string Model::getAirQuality(double latitude, double longitude, time_t date_debut, time_t date_fin, int rayon = 0){
    // Cette fonction permet de donner la qualité de l’air sur une période donnée sur une zone circulaire donnée. 
    // Elle utilise getIndiceATMO. 
    // Le rayon est initialisé à 0 si l’utilisateur cherche la valeur à un point précis, la date fin est initialisée à date debut si l’utilisateur souhaite la qualité de l’air un jour précis.
    // Retourne : la qualité de l’air.
    
    struct tm* original_timeinfo = localtime(&date_debut);
    
    int augmenter = 0;
    if (original_timeinfo->tm_hour > 12) {
         augmenter = 1; // Add one day
    }
    struct tm* timeinfo = localtime(&date_debut);
    timeinfo->tm_hour = 12;
    timeinfo->tm_min = 0;
    timeinfo->tm_sec = 0;
    time_t date = mktime(timeinfo);
    
    if (augmenter) {
        date += 24 * 60 * 60; // Add one day
    }
    
    //time_t date = date_debut;
    int nb_jour = 0;
    double val_O3 = 0;
    double val_SO2 = 0;
    double val_NO2 = 0;
    double val_PM10 = 0;
    int empty = 1;
    while (date < date_fin){
        vector<double> liste_indice_ATMO = getIndiceATMO(latitude, longitude, date, rayon);
        if (liste_indice_ATMO.empty()){
            date += 24 * 60 * 60;
            continue;
        }
        //printf("liste_indice_ATMO : %f %f %f %f\n", liste_indice_ATMO[0], liste_indice_ATMO[1], liste_indice_ATMO[2], liste_indice_ATMO[3]);
        val_O3 += liste_indice_ATMO[0];
        val_SO2 += liste_indice_ATMO[1];
        val_NO2 += liste_indice_ATMO[2];
        val_PM10 += liste_indice_ATMO[3];
        nb_jour++;
        date += 24 * 60 * 60;
        empty = 0;
    }

    if (empty == 1){
        val_O3 = -1;
        val_SO2 = -1;
        val_NO2 = -1;
        val_PM10 = -1;
    }
    else{
        val_O3 /= nb_jour;
        val_SO2 /= nb_jour;
        val_NO2 /= nb_jour;
        val_PM10 /= nb_jour;
    }

    printf("liste_indice_ATMO : O3 %f SO2 %f NO2 %f PM10 %f\n", val_O3, val_SO2, val_NO2, val_PM10);
    string qualite_air = calculer_indice_ATMO(val_O3, val_SO2, val_NO2, val_PM10);
    return qualite_air;
}


vector<double> Model::getMoyenneMesures(Capteur capteur){
    // Cette fonction permet de calculer la moyenne des mesures d'un capteur donné.
    vector<double> moyenne;
    double moy_O3 = 0;
    double moy_SO2 = 0;
    double moy_NO2 = 0;
    double moy_PM10 = 0;
    int count_O3 = 0;
    int count_SO2 = 0;
    int count_NO2 = 0;
    int count_PM10 = 0;
    
    for (unsigned int i=0; i<listeMesures.size(); i++){
        if (listeMesures[i].getCapteur() == capteur){
            if (listeMesures[i].getTypeMesure() == "O3"){
                moy_O3 += listeMesures[i].getValeur();
                count_O3++;
            }
            else if (listeMesures[i].getTypeMesure() == "SO2"){
                moy_SO2 += listeMesures[i].getValeur();
                count_SO2++;
            }
            else if (listeMesures[i].getTypeMesure() == "NO2"){
                moy_NO2 += listeMesures[i].getValeur();
                count_NO2++;
            }
            else if (listeMesures[i].getTypeMesure() == "PM10"){
                moy_PM10 += listeMesures[i].getValeur();
                count_PM10++;
            }
        }
    }

    moyenne.push_back(moy_O3 / count_O3);
    moyenne.push_back(moy_SO2 / count_SO2);
    moyenne.push_back(moy_NO2 / count_NO2);
    moyenne.push_back(moy_PM10 / count_PM10);

    return moyenne;
}

Data Model::trouverCapteursDefaillants(double marge_erreur, double distance, double ratio_incoherence){
    // Cette fonction permet de définir un capteur comme potentiellement défaillant. 
    
    vector<Capteur> capteurs_analyse;
    vector<Capteur> capteurs_defaillants;
    vector<Capteur> capteurs_potentiels;
    vector<double> ratio_capt_potentiels;
    for (unsigned int i=0; i<listeCapteurs.size(); i++){
        Capteur capteur = listeCapteurs[i];
        if (capteur.getDefaillant() == 0){
            capteurs_analyse.push_back(capteur);
        }
        else if (capteur.getDefaillant() == 1){
            capteurs_defaillants.push_back(capteur);
        }
        else {
            capteurs_potentiels.push_back(capteur);
        }

    }

    for (unsigned int i=0; i<capteurs_analyse.size(); i++){
        //printf("capteurs_analyse : %s\n", capteurs_analyse[i].getId().c_str());
        Capteur capteur = capteurs_analyse[i];
        vector<Capteur> capteurs_proximites;
        int nb_capteurs_proximites = 0;

        for (unsigned int j=0; j<listeCapteurs.size(); j++){
            double calc_distance = trouver_distance(capteur.getLatitude(), capteur.getLongitude(), listeCapteurs[j].getLatitude(), listeCapteurs[j].getLongitude());
            //printf("calc_distance : %f\n", calc_distance);
            if (capteur.getId() != listeCapteurs[j].getId() && listeCapteurs[j].getDefaillant() == 0 && calc_distance < distance){
                capteurs_proximites.push_back(listeCapteurs[j]);
                nb_capteurs_proximites++;
            }            
        }

        if (capteurs_proximites.size() != 0) {
            int count_incoherent = 0;
            for (unsigned int k=0; k<capteurs_proximites.size(); k++){
                Capteur capteur2 = capteurs_proximites[k];
                vector<double> moyenne_mes_capteur = getMoyenneMesures(capteur);
                vector<double> moyenne_mes_capteur2 = getMoyenneMesures(capteur2);

                for (int l=0; l<4; l++){
                    if (abs(moyenne_mes_capteur[l] - moyenne_mes_capteur2[l]) > marge_erreur){
                        count_incoherent ++;
                    }
                }
            }
            //printf("count_incoherent/nb_capt : %f %f\n", (double)count_incoherent/(double)nb_capteurs_proximites, ratio_incoherence);
            if (nb_capteurs_proximites != 0 && (double)count_incoherent / (double)nb_capteurs_proximites >= ratio_incoherence){
                capteurs_potentiels.push_back(capteur);
                ratio_capt_potentiels.push_back((double)count_incoherent / (double)nb_capteurs_proximites);
                capteur.setDefaillant(-1);
            }


        }
    }

    Data liste_capt = {capteurs_defaillants, capteurs_potentiels, ratio_capt_potentiels};
    return liste_capt;
}
