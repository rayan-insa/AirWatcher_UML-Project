/*************************************************************************
                Mesure  -  Manipule les mesures
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet AUdrey 
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.h) ------------
#if ! defined ( MESURE_H )
#define MESURE_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <iostream>
#include <ctime>
#include "Capteur.h"

//---------------------------------------------------Includes personnels
using namespace std;


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Mesure {
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs - destructeur
	Mesure();
	// Mode d'emploi : constructeur par défaut de Mesure
	//
	// Contrat :

	Mesure(time_t date, string type_mesure, double val, Capteur capteur);
	// Mode d'emploi : constructeur de Mesure avec paramètres
	//
	// Contrat : date est un time_t et val est un double

	~Mesure();
	// Mode d'emploi : destructeur de Mesure
	//
	// Contrat :

//----------------------------------------------------- Méthodes publiques

	time_t getDate() const;
	// Mode d'emploi : retourne la date de la mesure

	string getTypeMesure() const;
	// Mode d'emploi : retourne le type de la mesure

	double getValeur() const ;
	// Mode d'emploi : retourne la valeur de la mesure

	Capteur getCapteur() const;
	// Mode d'emploi : retourner le Capteur associé à la mesure

	void setDate(time_t newDate);
	// Mode d'emploi : définit la date de la mesure

	void setTypeMesure(string type);
	// Mode d'emploi : définit le type de la mesure

	void setValeur(double val);
	// Mode d'emploi : définit la valeur de la mesure

	void setCapteur(Capteur capteur);
	// Mode d'emploi : définit le Capteur associé à la mesure

//------------------------------------------------- Surcharge d'opérateurs

	friend ostream & operator<<(ostream & os, const Mesure & mesure);


//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Attributs protégés

	time_t date;
	string type_mesure;
	double valeur;
	Capteur capteur;

};

#endif // MESURE_H