/*************************************************************************
                Utilisateur  -  Manipule les Utilisateur
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ----------------
#if ! defined ( UTILISATEUR_H )
#define UTILISATEUR_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <string>

//---------------------------------------------------Includes personnels

using namespace std; 


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
//
//
//------------------------------------------------------------------------

class Utilisateur
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string getLogin();
    // Mode d'emploi :
    //



//-------------------------------------------- Constructeurs - destructeur
    
    Utilisateur ( );
    // Mode d'emploi : constructeur par défaut de Utilisateur
    //
    // Contrat :
    
    Utilisateur ( string login );
    // Mode d'emploi : constructeur par défaut de Gouvernement
    //
    // Contrat :

    virtual ~Utilisateur ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string login;
};

#endif // Utilisateur_H
