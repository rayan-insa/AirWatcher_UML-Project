#include <iostream>
using namespace std;

#include "Mesure.h"

// Constructeur par défaut
Mesure::Mesure() {
    date = 0;
    valeur = 0;
}

// Constructeur avec paramètres
Mesure::Mesure(time_t date, long val) {
    this->date = date;
    valeur = val;
}

// Destructeur
Mesure::~Mesure() {
    // Code du destructeur, s'il est nécessaire
}

// Méthode pour obtenir la date de la mesure
time_t Mesure::getDate() {
    return date;
}

// Méthode pour obtenir la valeur de la mesure
long Mesure::getValeur() {
    return valeur;
}

// Méthode pour définir la date de la mesure
void Mesure::setDate(time_t newDate) {
    date = newDate;
}

// Méthode pour définir la valeur de la mesure
void Mesure::setValeur(long val) {
    valeur = val;
}