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
#include <memory>
//---------------------------------------------------Includes personnels
using namespace std;

//------------------------------------------------------------------ Types

class Model;
class View;

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

    shared_ptr<Model>  getModel() const;
    // Mode d'emploi : 
    // Cette méthode retourne l'objet Model associé au Controller.
    // Elle est constante pour garantir qu'elle ne modifie pas l'objet Controller.
    // Elle ne prend aucun paramètre.
    // Elle renvoie l'objet Model associé au Controller.

    shared_ptr<View>  getView() const;
    // Mode d'emploi : 
    // Cette méthode retourne l'objet View associé au Controller.
    // Elle est constante pour garantir qu'elle ne modifie pas l'objet Controller.
    // Elle ne prend aucun paramètre.
    // Elle renvoie l'objet View associé au Controller.

//-------------------------------------------- Constructeurs - destructeur

    Controller ( );
    // Mode d'emploi : constructeur par défaut de Controller
    //
    // Contrat :

    Controller ( shared_ptr<Model>  model, shared_ptr<View>  vue );
    // Mode d'emploi : constructeur de Controller
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
shared_ptr<Model> model;
shared_ptr<View> vue;
};

#endif // Controller_H
