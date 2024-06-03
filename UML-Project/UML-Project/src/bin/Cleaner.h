/*************************************************************************
                Cleaner  -  Classe des cleaners
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eléonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#ifndef CLEANER_H
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées

//-------------------------------------------------------- Include système
#include <string>
#include <ctime>
#include "Fournisseur.h"

//------------------------------------------------------ Include personnel

using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Cleaner {

//------------------------------------------------------------------ PRIVE
private:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string id;
    double latitude;
    double longitude;
    time_t timestamp_start;
    time_t timestamp_stop;
    Fournisseur fournisseur;

//----------------------------------------------------------------- PUBLIC
public:

    //-------------------------------------------- Constructeurs - destructeur

    Cleaner();
    // Mode d'emploi : constructeur par défaut de Cleaner

    Cleaner(const string& id, double latitude, double longitude, const time_t timestamp_start, const time_t timestamp_stop, Fournisseur fournisseur);
    // Mode d'emploi : constructeur paramétré de Cleaner

    ~Cleaner();
    // Mode d'emploi : destructeur par défaut de Cleaner

    //----------------------------------------------------- Méthodes publiques

    // -------------------------------------------- Getters
    string getId() const;
    // Mode d'emploi : 
    // Obtient l'id du cleaner
    
    double getLatitude() const;
    // Mode d'emploi : 
    // Obtient la latitude du cleaner

    double getLongitude() const;
    // Mode d'emploi : 
    // Obtient la longitude du cleaner

    time_t getTimestampStart() const;
    // Mode d'emploi : 
    // Obtient le temps de début du cleaner

    time_t getTimestampStop() const;
    // Mode d'emploi : 
    // Obtient le temps de fin du cleaner

    Fournisseur getFournisseur() const;
    // Mode d'emploi : 
    // Obtient le fournisseur du cleaner


    // -------------------------------------------- Setters
    void setId(const string& id);
    // Mode d'emploi :
    // Définit l'id du cleaner
    void setLatitude(double latitude);
    // Mode d'emploi :
    // Définit la latitude du cleaner
    void setLongitude(double longitude);
    // Mode d'emploi :
    // Définit la longitude du cleaner
    void setTimestampStart(const time_t timestamp_start);
    // Mode d'emploi :
    // Définit le temps de début du cleaner
    void setTimestampStop(const time_t timestamp_stop);
    // Mode d'emploi :
    // Définit le temps de fin du cleaner
    void setFournisseur(Fournisseur fournisseur);
    // Mode d'emploi :
    // Définit le fournisseur du cleaner

    // -------------------------------------------- Methodes
    void afficherInfos() const;
    // Mode d'emploi :
    // Affiche les informations du fournisseur
};

#endif // CLEANER_H
