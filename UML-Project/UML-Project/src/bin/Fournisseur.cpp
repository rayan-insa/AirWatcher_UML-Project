/*************************************************************************
                Fournisseur  -  Classe des fournisseurs
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eléonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <vector>
//------------------------------------------------------ Include personnel
#include "Fournisseur.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

// Constructeur par défaut
Fournisseur::Fournisseur() : nom(""), nbCommandes(0), historiqueCommandes() {} //----- Fin de Fournisseur

// Constructeur avec paramètres
Fournisseur::Fournisseur(const string& nom) : nom(nom), nbCommandes(0), historiqueCommandes() {} //----- Fin de Fournisseur

// Destructeur par defaut
Fournisseur::~Fournisseur() {} //----- Fin de ~Fournisseur

//----------------------------------------------------- Méthodes publiques

// -------------------------------------------- Getters
string Fournisseur::getNom() const 
    // Renvoie le nom du fournisseur.
    // Retourne : le nom du fournisseur.
{
    return nom;
}

int Fournisseur::getNbCommandes() const 
// Renvoie le nombre de commandes du fournisseur.
// Retourne : le nombre de commandes du fournisseur.
{
    return nbCommandes;
}

vector<string> Fournisseur::getHistoriqueCommandes() const 
// Renvoie l'historique de commandes du fournisseur.
// Retourne : l'historique de commandes du fournisseur.
{
    return historiqueCommandes;
}

// -------------------------------------------- Setters
void Fournisseur::setNom(const string& nom) 
// Définit le nom du fournisseur.
// nom : le nouveau nom du fournisseur.
{
    this->nom = nom;
}

void Fournisseur::setNbCommandes(int nbCommandes) 
// Définit le nombre de commandes du fournisseur.
// nbCommandes : le nouveau nombre de commandes du fournisseur.
{
    this->nbCommandes = nbCommandes;
}

void Fournisseur::setHistoriqueCommandes(const vector<string>& historiqueCommandes) 
// Définit l'historique du fournisseur.
// historiqueCommandes : le nouvel historique de commandes du fournisseur.
{
    this->historiqueCommandes = historiqueCommandes;
}

// -------------------------------------------- Methodes
void Fournisseur::ajouterCommande(const string& commande) 
// Ajoute une commande à l'historique du fournisseur.
// commande : la commande à ajouter à l'historique.
{
    historiqueCommandes.push_back(commande); //augmente dynamiquement la taille du vecteur si besoin
    nbCommandes++;
}


void Fournisseur::afficherInfos() const 
// Affichage des informations du fournisseur
{
    cout << "Nom: " << nom << endl;
    cout << "Nombre de commandes: " << nbCommandes << endl;
    cout << "Historique des commandes: ";
    for (int i = 0; i < this->nbCommandes; i++) {
        cout << this->historiqueCommandes[i] << ", ";
    }
    cout << endl;
}