/*************************************************************************
                Attribut  -  Manipule les attributs
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet AUdrey 
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

using namespace std;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//Constructeur par défaut
Attribut::Attribut() {
	attributID = "";
	unit = "";
	description = "";
}

//Constructeur avec paramètres
Attribut::Attribut(string ID, string un, string descr) {
	attributID = ID;
	unit = un;
	description = descr;
}

//-------------------------------------------Getters
string Attribut::getAttributID() const {
	return attributID;
}

string Attribut::getUnit() const {
	return unit;
}

string Attribut::getDescription() const {
	return description;
}

//-------------------------------------------Setters
void Attribut::setAttributID(string ID) {
	attributID = ID;
}

void Attribut::setUnit(string un) {
	unit = un;
}

void Attribut::setDescription(string descr) {
	description = descr;
}

//Destructeur
Attribut::~Attribut() {
}

