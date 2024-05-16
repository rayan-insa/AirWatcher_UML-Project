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

	Mesure(time_t date, long val);
	// Mode d'emploi : constructeur de Mesure avec paramètres
	//
	// Contrat : date est un time_t et val est un long

	~Mesure();
	// Mode d'emploi : destructeur de Mesure
	//
	// Contrat :

//----------------------------------------------------- Méthodes publiques

	time_t getDate() const;
	// Mode d'emploi : retourne la date de la mesure

	long getValeur() const ;
	// Mode d'emploi : retourne la valeur de la mesure

	void setDate(time_t newDate);
	// Mode d'emploi : définit la date de la mesure

	void setValeur(long val);
	// Mode d'emploi : définit la valeur de la mesure


//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Attributs protégés

	time_t date;
	long valeur;


};

#endif // MESURE_H