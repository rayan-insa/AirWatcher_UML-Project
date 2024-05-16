/*************************************************************************
                        Gouvernement  -  Manipule le gouvernement
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface de la classe <Gouvernement> (fichier Gouvernement.h) ----------------
#if ! defined ( GOUVERNEMENT_H )
#define GOUVERNEMENT_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système

//---------------------------------------------------Includes personnels
#include "Utilisateur.h"
using namespace std; 


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Gouvernement>
//
//
//------------------------------------------------------------------------

class Gouvernement : public Utilisateur
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // decla methode 1
    // Mode d'emploi : 
    // écrire ici le mode d'emploi de la méthode



//-------------------------------------------- Constructeurs - destructeur

    Gouvernement ( string login );
    // Mode d'emploi : constructeur par défaut de Gouvernement
    //
    // Contrat :

    virtual ~Gouvernement ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

#endif // Gouvernement_H
