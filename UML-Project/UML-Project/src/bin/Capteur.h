/*************************************************************************
                Capteur  -  Manipule les capteurs
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet AUdrey 
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.h) ------------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <iostream>

//---------------------------------------------------Includes personnels
using namespace std;
#include "Utilisateur.h"

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Capteur
{
//----------------------------------------------------------------- PUBLIC
public:
//-------------------------------------------- Constructeurs - destructeur
	Capteur();
	// Mode d'emploi : constructeur par défaut de Capteur
	//
	// Contrat :

	Capteur(string id, double lat, double lon, bool def, Utilisateur user);
	// Mode d'emploi : constructeur de Capteur avec paramètres
	//
	// Contrat : lat et lon sont des longs et def est un booléen

	~Capteur();
	// Mode d'emploi : destructeur de Capteur
	//
	// Contrat :

//----------------------------------------------------- Méthodes publiques

	string getId() const;
	// Mode d'emploi : retourne l'id du capteur

	Utilisateur getUser() const;
	// Mode d'emploi : retourne l'utilisateur du capteur

	double getLatitude() const;
	// Mode d'emploi : retourne la latitude du capteur

	double getLongitude() const;
	// Mode d'emploi : retourne la longitude du capteur

	bool getDefaillant() const;
	// Mode d'emploi : retourne si le capteur est défaillant ou non

	void setLatitude(double lat);
	// Mode d'emploi : définit la latitude du capteur

	void setLongitude(double lon);
	// Mode d'emploi : définit la longitude du capteur

	void setDefaillant(bool def);
	// Mode d'emploi : définit si le capteur est défaillant ou non

	bool operator==(const Capteur& capteur2) const;
	// Mode d'emploi : surcharge de l'opérateur == pour comparer deux capteurs

	Capteur findCapteur(string id);
	// Mode d'emploi : retourne le capteur correspondant à l'id

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Attributs protégés
	string id;
	double latitude;
	double longitude;
	bool defaillant;
	Utilisateur user;
};

#endif // CAPTEUR_H