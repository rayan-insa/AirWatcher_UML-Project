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

Model::Model (  )
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Model>" << endl;
#endif
    controller = Controller();
    gouv = Gouvernement();
    ifstream file("dataset/users.csv");

    if (!file.is_open())
    {
        cerr << "Error: Could not open file users.csv" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        size_t pos = line.find(';');
        if (pos != string::npos) {
            string user = line.substr(0, pos);
            string sensor = line.substr(pos + 1);
            Particulier particulier = Particulier(user, 0, true);
            Capteur capteur = Capteur(sensor, 0, 0, true, particulier);
            listeParticuliers.push_back(particulier);
            listeCapteurs.push_back(capteur);
        }
    }
    file.close();

    ifstream file2("dataset/sensors.csv");
    if (!file2.is_open())
    {
        cerr << "Error: Could not open file users.csv" << endl;
        return;
    }
    string line;
    while (getline(file2, line))
    {
        stringstream ss(line);
        string id;
        string latitude;
        string longitude;

        if (getline(ss, id, ';') && getline(ss, latitude, ';') && getline(ss, longitude, ';')) {

            long lat = stol(latitude);
            long lon = stol(longitude);
            for (int i=0; i<listeCapteurs.size(); i++) {
                if (listeCapteurs[i].getId() == id) {
                    listeCapteurs[i].setLatitude(lat);
                    listeCapteurs[i].setLongitude(lon);
                }
                else {
                    Capteur capteur = Capteur(id, lat, lon, false, Gouvernement());
                    listeCapteurs.push_back(capteur);
                }
            }

        }
    }
    file.close();


    ifstream file3("dataset/providers.csv");
    if (!file3.is_open())
    {
        cerr << "Error: Could not open file providers.csv" << endl;
        return;
    }
    string line;
    while (getline(file3, line))
    {
        size_t pos = line.find(';');
        if (pos != string::npos) {
            string provider = line.substr(0, pos);
            string sensor = line.substr(pos + 1);
            Fournisseur fournisseur = Fournisseur(provider);
            Cleaner cleaner = Cleaner(sensor, 0, 0, NULL, NULL, fournisseur);
            listeFournisseurs.push_back(fournisseur);
            listeCleaners.push_back(cleaner);
        }
    }
    file3.close();

    
    ifstream file4("dataset/cleaners.csv");
    if (!file4.is_open())
    {
        cerr << "Error: Could not open file cleaners.csv" << endl;
        return;
    }
    string line;
    while (getline(file4, line))
    {
        stringstream ss(line);
        string id;
        string latitude;
        string longitude;
        string time_stamp_start;
        string time_stamp_end;

        if (getline(ss, id, ';') && getline(ss, latitude, ';') && getline(ss, longitude, ';') && getline(ss, time_stamp_start, ';') && getline(ss, time_stamp_end, ';')){

            long lat = stol(latitude);
            long lon = stol(longitude);
            tm tm1={};
            istringstream ss(time_stamp_start);
            ss >> get_time(&tm1, "%Y-%m-%d %H:%M:%S");
            time_t start = mktime(&tm1);
            tm tm2={};
            istringstream ss2(time_stamp_end);
            ss2 >> get_time(&tm2, "%Y-%m-%d %H:%M:%S");
            time_t end = mktime(&tm2);


            for (int i=0; i<listeCleaners.size(); i++) {
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
