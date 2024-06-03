/*************************************************************************
                Cleaner  -  Classe des cleaners
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eléonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <ctime>
//------------------------------------------------------ Include personnel
#include "Fournisseur.h"
#include "Cleaner.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

// Constructeur par défaut
Cleaner::Cleaner() : id(""), latitude(0), longitude(0), timestamp_start(), timestamp_stop(), fournisseur("") {} //----- Fin de Cleaner

// Constructeur avec paramètres
Cleaner::Cleaner(const string& id, double latitude, double longitude, const time_t timestamp_start, const time_t timestamp_stop, Fournisseur fournisseur)
    : id(id), latitude(latitude), longitude(longitude), timestamp_start(timestamp_start), timestamp_stop(timestamp_stop), fournisseur(fournisseur) {} //----- Fin de Cleaner

// Destructeur par défaut
Cleaner::~Cleaner() {} //----- Fin de ~Cleaner

//----------------------------------------------------- Méthodes publiques

// -------------------------------------------- Getters
string Cleaner::getId() const 
// Renvoie l'id du cleaner.
// Retourne : l'id du cleaner.
{
    return id;
}

double Cleaner::getLatitude() const 
// Renvoie la latitude du cleaner.
// Retourne : la latitude du cleaner.
{
    return latitude;
}

double Cleaner::getLongitude() const 
// Renvoie la longitude du cleaner.
// Retourne : la longitude du cleaner.
{
    return longitude;
}

time_t Cleaner::getTimestampStart() const 
// Renvoie le temps de début du cleaner.
// Retourne : le temps de début du cleaner.
{
    return timestamp_start;
}

time_t Cleaner::getTimestampStop() const 
// Renvoie le temps de fin du cleaner.
// Retourne : le temps de fin du cleaner.
{
    return timestamp_stop;
}

Fournisseur Cleaner::getFournisseur() const 
// Renvoie le fournisseur du cleaner.
// Retourne : l'objet fournisseur correspondant.
{
    return fournisseur;
}

// -------------------------------------------- Setters
void Cleaner::setId(const string& id) 
// Définit l'id du cleaner.
// id : le nouvel id du cleaner.
{
    this->id = id;
}

void Cleaner::setLatitude(double latitude) 
// Définit la latitude du cleaner.
// latitude : la nouvelle latitude du cleaner.
{
    this->latitude = latitude;
}

void Cleaner::setLongitude(double longitude) 
// Définit la longitude du cleaner.
// longitude : la nouvelle longitude du cleaner.
{
    this->longitude = longitude;
}

void Cleaner::setTimestampStart(const time_t timestamp_start) 
// Définit le temps de début du cleaner.
// timestamp_start : le nouveau temps de début du cleaner.
{
    this->timestamp_start = timestamp_start;
}

void Cleaner::setTimestampStop(const time_t timestamp_stop) 
// Définit le temps de fin du cleaner.
// timestamp_stop : le nouveau temps de fin du cleaner.
{
    this->timestamp_stop = timestamp_stop;
}

void Cleaner::setFournisseur(Fournisseur fournisseur) 
// Définit le fournisseur du cleaner.
// fournisseur : le nouveau fournisseur du cleaner.
{
    this->fournisseur = fournisseur;
}

// -------------------------------------------- Methodes
void Cleaner::afficherInfos() const 
// Affichage des informations du Cleaner
{
    cout << "ID: " << id << endl;
    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    cout << "Timestamp de début: " << asctime(localtime(&timestamp_start));
    cout << "Timestamp de fin: " << asctime(localtime(&timestamp_stop));
    cout << "Fournisseur: ";
    fournisseur.afficherInfos();
}