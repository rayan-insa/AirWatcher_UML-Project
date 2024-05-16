/*************************************************************************
                        View  -  Manipule le View
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface de la classe <View> (fichier View.h) ----------------
#if ! defined ( VIEW_H )
#define VIEW_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <string>
//---------------------------------------------------Includes personnels
using namespace std;
#include "Controller.h"
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <View>
//
//
//------------------------------------------------------------------------

class View
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    int getEntreeUtilisateur() const;
    // Mode d'emploi : 
    // écrire ici le mode d'emploi de la méthode

    string getTexteVueCourante() const;
    // Mode d'emploi : 
    // écrire ici le mode d'emploi de la méthode

    void afficherVue() const;
    // Mode d'emploi : 
    // écrire ici le mode d'emploi de la méthode

    void setTexteVueCourante(string texteVueCourante);
    // Mode d'emploi : 
    // écrire ici le mode d'emploi de la méthode



//-------------------------------------------- Constructeurs - destructeur

    View ( );
    // Mode d'emploi : constructeur par défaut de View
    //
    // Contrat :

    View ( string texteVueCourante, int entreeUtilisateur, Controller controller );
    // Mode d'emploi : constructeur par défaut de View
    //
    // Contrat :

    virtual ~View ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string texteVueCourante;
int entreeUtilisateur;
Controller controller;
};

#endif // View_H
