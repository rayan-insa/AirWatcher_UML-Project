/*************************************************************************
                Capteur  -  Manipule les capteurs
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet AUdrey 
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
using namespace std;
#include "Capteur.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Constructeur par défaut
Capteur::Capteur() {
    id = "";
    latitude = 0;
    longitude = 0;
    defaillant = false;
    user = Utilisateur();
}

// Constructeur avec paramètres
Capteur::Capteur(string id, long lat, long lon, bool def, Utilisateur user) {
    this->id = id;
    latitude = lat;
    longitude = lon;
    defaillant = def;
    this->user = user;
}

// Destructeur
Capteur::~Capteur() {
    // Code du destructeur, s'il est nécessaire
}


//---------------------------------------------------------- Getters

// Méthode pour obtenir l'id
string Capteur::getId() const {
    return id;
}

// Méthode pour obtenir l'utilisateur
Utilisateur Capteur::getUser() const {
    return user;
}


// Méthode pour obtenir la latitude
long Capteur::getLatitude() const {
    return latitude;
}

// Méthode pour obtenir la longitude
long Capteur::getLongitude() const {
    return longitude;
}

// Méthode pour vérifier si le capteur est défaillant
bool Capteur::getDefaillant() const {
    return defaillant;
}

//---------------------------------------------------------- Setters

// Méthode pour définir la latitude
void Capteur::setLatitude(long lat) {
    latitude = lat;
}

// Méthode pour définir la longitude
void Capteur::setLongitude(long lon) {
    longitude = lon;
}

// Méthode pour définir si le capteur est défaillant ou non
void Capteur::setDefaillant(bool def) {
    defaillant = def;
}

//---------------------------------------------------------- Surcharge d'opérateurs

// Méthode pour comparer deux capteurs
bool Capteur::operator==(const Capteur& capteur2) const {
    if (latitude == capteur2.getLatitude() && longitude == capteur2.getLongitude() && defaillant == capteur2.getDefaillant()) {
        return true;
    }
    else{ 
        return false;
    }
}