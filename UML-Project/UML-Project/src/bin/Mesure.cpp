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
}

// Constructeur avec paramètres
Mesure::Mesure(time_t date, long val) {
    this->date = date;
    valeur = val;
}

// Destructeur
Mesure::~Mesure() {
}

//---------------------------------------------------------- Getters

// Méthode pour obtenir la date de la mesure
time_t Mesure::getDate() const {
    return date;
}

// Méthode pour obtenir la valeur de la mesure
long Mesure::getValeur() const {
    return valeur;
}

//---------------------------------------------------------- Setters

// Méthode pour définir la date de la mesure
void Mesure::setDate(time_t newDate) {
    date = newDate;
}

// Méthode pour définir la valeur de la mesure
void Mesure::setValeur(long val) {
    valeur = val;
}