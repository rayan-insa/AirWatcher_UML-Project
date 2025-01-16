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
Capteur::Capteur(string id, double lat, double lon, bool def, Utilisateur user) {
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
double Capteur::getLatitude() const {
    return latitude;
}

// Méthode pour obtenir la longitude
double Capteur::getLongitude() const {
    return longitude;
}

// Méthode pour vérifier si le capteur est défaillant
bool Capteur::getDefaillant() const {
    return defaillant;
}

//---------------------------------------------------------- Setters

// Méthode pour définir la latitude
void Capteur::setLatitude(double lat) {
    latitude = lat;
}

// Méthode pour définir la longitude
void Capteur::setLongitude(double lon) {
    longitude = lon;
}

// Méthode pour définir si le capteur est défaillant ou non
void Capteur::setDefaillant(bool def) {
    defaillant = def;
}

// Méthode pour trouver un capteur
Capteur Capteur::findCapteur(string id) {
    if(id == this->id) {
        return *this;
    }
    else {
        return Capteur();
    }
}

//---------------------------------------------------------- Surcharge d'opérateurs

// Méthode pour comparer deux capteurs
bool Capteur::operator==(const Capteur& capteur2) const {
    return id == capteur2.getId();
}

ostream & operator<<(ostream & os, const Capteur & capteur) {
    os << "Capteur " << capteur.getId() << " : lat " << capteur.getLatitude() << " - long " << capteur.getLongitude() << " - defaill " << capteur.getDefaillant() << " - user " << capteur.getUser().getLogin();
    return os;
}