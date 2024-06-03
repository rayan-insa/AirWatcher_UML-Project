/*************************************************************************
                Mesure  -  Manipule les mesures
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet AUdrey 
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
using namespace std;
#include "Mesure.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Constructeur par défaut
Mesure::Mesure() {
    date = 0;
    valeur = 0;
    capteur = Capteur();
}

// Constructeur avec paramètres
Mesure::Mesure(time_t date, string type, long val, Capteur capt) {
    this->date = date;
    type_mesure = type;
    valeur = val;
    capteur = capt;
}

// Destructeur
Mesure::~Mesure() {
}

//---------------------------------------------------------- Getters

// Méthode pour obtenir la date de la mesure
time_t Mesure::getDate() const {
    return date;
}

// Méthode pour obtenir le type de la mesure
string Mesure::getTypeMesure() const {
    return type_mesure;
}

// Méthode pour obtenir la valeur de la mesure
long Mesure::getValeur() const {
    return valeur;
}

// Méthode pour obtenir le capteur de la mesure
Capteur Mesure::getCapteur() const {
    return capteur;
}


//---------------------------------------------------------- Setters

// Méthode pour définir la date de la mesure
void Mesure::setDate(time_t newDate) {
    date = newDate;
}

// Méthode pour définir le type de la mesure
void Mesure::setTypeMesure(string type) {
    type_mesure = type;
}

// Méthode pour définir la valeur de la mesure
void Mesure::setValeur(long val) {
    valeur = val;
}

// Methode pour définir le capteur de la mesure
void Mesure::setCapteur(Capteur capt) {
    capteur = capt;
}

//---------------------------------------------------------- Surcharge d'opérateurs

// Surcharge de l'opérateur <<
ostream & operator<<(ostream & os, const Mesure & mesure) {
    os << "Mesure du " << ctime(&mesure.date) << "Type : " << mesure.type_mesure << " Valeur : " << mesure.valeur << " Capteur : " << mesure.capteur.getId();
    return os;
}