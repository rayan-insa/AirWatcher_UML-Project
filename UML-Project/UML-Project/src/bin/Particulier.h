/*************************************************************************
                        Particulier  -  Manipule les Particuliers
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface de la classe <Particulier> (fichier Particulier.h) ----------------
#if ! defined ( PARTICULIER_H )
#define PARTICULIER_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <string>
//---------------------------------------------------Includes personnels
#include "Utilisateur.h"
using namespace std; 


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Particulier>
//
//
//------------------------------------------------------------------------

class Particulier : public Utilisateur
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    int getPoints();
    // Mode d'emploi : 
    // 

    bool getFiable();
    // Mode d'emploi :
    //

//-------------------------------------------- Constructeurs - destructeur

    Particulier ( string login, int points, bool fiable );
    // Mode d'emploi : constructeur par défaut de Gouvernement
    //
    // Contrat :

    virtual ~Particulier ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int points;
bool fiable;
};

#endif // Gouvernement_H
