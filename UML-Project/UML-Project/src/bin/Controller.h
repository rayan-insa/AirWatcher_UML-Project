/*************************************************************************
                        Controller  -  Manipule le Controller
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface de la classe <Controller> (fichier Controller.h) ----------------
#if ! defined ( CONTROLLER_H )
#define CONTROLLER_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <string>
//---------------------------------------------------Includes personnels
using namespace std;
#include "Model.h"
#include "View.h"
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controller>
//
//
//------------------------------------------------------------------------

class Controller
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    
    // Mode d'emploi : 
    // écrire ici le mode d'emploi de la méthode

    Model getModel() const;
    // Mode d'emploi : 
    // Cette méthode retourne l'objet Model associé au Controller.
    // Elle est constante pour garantir qu'elle ne modifie pas l'objet Controller.
    // Elle ne prend aucun paramètre.
    // Elle renvoie l'objet Model associé au Controller.

    View getView() const;
    // Mode d'emploi : 
    // Cette méthode retourne l'objet View associé au Controller.
    // Elle est constante pour garantir qu'elle ne modifie pas l'objet Controller.
    // Elle ne prend aucun paramètre.
    // Elle renvoie l'objet View associé au Controller.

//-------------------------------------------- Constructeurs - destructeur
    
    Controller ( Model model, View vue );
    // Mode d'emploi : constructeur par défaut de Controller
    //
    // Contrat :

    ~Controller ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Model model;
View vue;
};

#endif // Controller_H
