/*************************************************************************
                        Model  -  Manipule le Model
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface de la classe <Model> (fichier Model.h) ----------------
#if ! defined ( MODEL_H )
#define MODEL_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <vector>
#include <algorithm>
#include <cmath>
//---------------------------------------------------Includes personnels
using namespace std; 

#include "Gouvernement.h"
#include "Particulier.h"
#include "Capteur.h"
#include "Cleaner.h"
#include "Fournisseur.h"
#include "Controller.h"
#include "Mesure.h"


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Model>
//
//
//------------------------------------------------------------------------

class Model
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    View getVue() const;
    // Mode d'emploi :
    // Cette méthode retourne l'objet View associé au modèle.

    Controller getController() const;
    // Mode d'emploi :
    // Cette méthode retourne l'objet Controller associé au modèle.

    Gouvernement getGouvernement() const;
    // Mode d'emploi :
    // Cette méthode retourne l'objet Gouvernement associé au modèle.

    vector<Particulier> getListeParticuliers() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Particulier associés au modèle.

    vector<Capteur> getListeCapteurs() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Capteur associés au modèle.

    vector<Cleaner> getListeCleaners() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Cleaner associés au modèle.

    vector<Fournisseur> getListeFournisseurs() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Fournisseur associés au modèle.

    vector<Mesure> getListeMesures() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Mesure associés au modèle.

    vector<Capteur> get_liste_capteurs_fiables();
    // Mode d'emploi :
    // Cette méthode retourne la liste des capteurs fiables.

    vector<Capteur> get_liste_capteurs_date(time_t date);
    // Mode d'emploi :
    // Cette méthode retourne la liste des capteurs qui possèdent des mesures à une date donnée.

    double trouver_distance(long lat1, long lon1, long lat2, long lon2);
    // Mode d'emploi :
    // Cette méthode retourne la distance entre deux points géographiques.
    
    vector<long> getIndiceATMO(long latitude, long longitude, time_t date, int rayon = 0);
    // Mode d'emploi :
    // Cette méthode retourne l'indice ATMO à une date donnée pour une zone donnée.


//-------------------------------------------- Constructeurs - destructeur

    Model ( );
    // Mode d'emploi : constructeur par défaut de Model
    //
    // Contrat :

    Model ( Controller controller, Gouvernement gouv,  vector<Particulier> listeParticuliers, vector<Capteur> listeCapteurs, vector<Cleaner> listeCleaners, vector<Fournisseur> listeFournisseurs, vector<Mesure> listeMesures );
    // Mode d'emploi : constructeur par défaut de Model
    //
    // Contrat :

    virtual ~Model ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Controller controller;
Gouvernement gouv;
vector<Particulier> listeParticuliers;
vector<Capteur> listeCapteurs;
vector<Cleaner> listeCleaners;
vector<Fournisseur> listeFournisseurs;
vector<Mesure> listeMesures;
};

#endif // Model_H
