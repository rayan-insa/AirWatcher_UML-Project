/*************************************************************************
                Attribut  -  Manipule les attributs
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet AUdrey 
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.h) ------------
#if ! defined ( ATTRIBUT_H )
#define ATTRIBUT_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <iostream>

//---------------------------------------------------Includes personnels
using namespace std;


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------
class Attribut {

//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructeurs - destructeur

	Attribut();
	// Mode d'emploi : constructeur par défaut d'Attribut
    //
    // Contrat :

	Attribut(string ID, string un, string descr);
	// Mode d'emploi : constructeur d'Attribut avec paramètres
	//
	// Contrat : ID, un et descr sont des chaines de caractères

	~Attribut();
	// Mode d'emploi : destructeur d'Attribut
	//
	// Contrat :

//----------------------------------------------------- Méthodes publiques

	string getAttributID() const;
	// Mode d'emploi : retourne l'attributID de l'attribut

	string getUnit() const;
	// Mode d'emploi : retourne l'unit de l'attribut

	string getDescription() const;
	// Mode d'emploi : retourne la description de l'attribut

	void setAttributID(string ID);
	// Mode d'emploi : modifie l'attributID de l'attribut

	void setUnit(string un);
	// Mode d'emploi : modifie l'unit de l'attribut

	void setDescription(string descr);
	// Mode d'emploi : modifie la description de l'attribut


//------------------------------------------------------------------ PRIVE
private:

//----------------------------------------------------- Attributs protégés
	string attributID;
	string unit;
	string description;


};

#endif // ATTRIBUT_H
