/*************************************************************************
                Fournisseur  -  Classe des fournisseurs
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eléonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel

using namespace std;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Fournisseur>
//
//
//------------------------------------------------------------------------

class Fournisseur {

//------------------------------------------------------------------ PRIVE
private:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string nom;
    int nbCommandes;
    vector<string> historiqueCommandes;

//----------------------------------------------------------------- PUBLIC
public:

    //-------------------------------------------- Constructeurs - destructeur

    Fournisseur();
    // Mode d'emploi : constructeur par défaut de Fournisseur

    Fournisseur(const string& nom);
    // Mode d'emploi : constructeur paramétré de Fournisseur

    ~Fournisseur();
    // Mode d'emploi : destructeur par défaut de Fournisseurs

    //----------------------------------------------------- Méthodes publiques

    // -------------------------------------------- Getters
    string getNom() const;
    // Mode d'emploi : 
    // Obtient le nom du fournisseur

    int getNbCommandes() const;
    // Mode d'emploi :
    // Obtient le nombre de commandes du fournisseur

    vector<string> getHistoriqueCommandes() const;
    // Mode d'emploi :
    // Obtient l'historique des commandes du fournisseur
    

    // -------------------------------------------- Setters
    void setNom(const string& nom);
    // Mode d'emploi :
    // Définit le nom du fournisseur

    void setNbCommandes(int nbCommandes);
    // Mode d'emploi :
    // Définit le nombre de commandes du fournisseur

    void setHistoriqueCommandes(const vector<string>& historiqueCommandes);
    // Mode d'emploi :
    // Définit l'historique de commandes du fournisseur

    // -------------------------------------------- Methodes
    void ajouterCommande(const string& commande);
    // Mode d'emploi :
    // Ajoute une commande à l'historique du fournisseur

    void afficherInfos() const;
    // Mode d'emploi :
    // Affiche les informations du fournisseur
};

#endif // FOURNISSEUR_H
