#include <iostream>
using namespace std;

#include "Capteur.h"

// Constructeur par défaut
Capteur::Capteur() {
    latitude = 0;
    longitude = 0;
    defaillant = false;
}

// Constructeur avec paramètres
Capteur::Capteur(long lat, long lon, bool def) {
    latitude = lat;
    longitude = lon;
    defaillant = def;
}

// Destructeur
Capteur::~Capteur() {
    // Code du destructeur, s'il est nécessaire
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