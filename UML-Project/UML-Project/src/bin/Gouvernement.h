/*************************************************************************
                Gouvernement  -  Manipule le gouvernement
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet Audrey 
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

    Gouvernement ( );
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
