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

	Capteur(string id, long lat, long lon, bool def, Utilisateur user);
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

	long getLatitude() const;
	// Mode d'emploi : retourne la latitude du capteur

	long getLongitude() const;
	// Mode d'emploi : retourne la longitude du capteur

	bool getDefaillant() const;
	// Mode d'emploi : retourne si le capteur est défaillant ou non

	void setLatitude(long lat);
	// Mode d'emploi : définit la latitude du capteur

	void setLongitude(long lon);
	// Mode d'emploi : définit la longitude du capteur

	void setDefaillant(bool def);
	// Mode d'emploi : définit si le capteur est défaillant ou non

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Attributs protégés
	string id;
	long latitude;
	long longitude;
	bool defaillant;
	Utilisateur user;
};

#endif // CAPTEUR_H