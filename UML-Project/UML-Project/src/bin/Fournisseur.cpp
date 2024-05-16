#include <iostream>
#include <string>
#include <vector>
#include "Fournisseur.h"

using namespace std;

// Constructeur par défaut
Fournisseur::Fournisseur() : nom(""), nbCommandes(0), historiqueCommandes() {}

// Constructeur avec paramètres
Fournisseur::Fournisseur(const string& nom) : nom(nom), nbCommandes(0), historiqueCommandes() {}

// Destructeur par defaut
Fournisseur::~Fournisseur() {}

// Getters
string Fournisseur::getNom() const {
    return nom;
}

int Fournisseur::getNbCommandes() const {
    return nbCommandes;
}

vector<string> Fournisseur::getHistoriqueCommandes() const {
    return historiqueCommandes;
}

// Setters
void Fournisseur::setNom(const string& nom) {
    this->nom = nom;
}

void Fournisseur::setNbCommandes(int nbCommandes) {
    this->nbCommandes = nbCommandes;
}

void Fournisseur::setHistoriqueCommandes(const vector<string>& historiqueCommandes) {
    this->historiqueCommandes = historiqueCommandes;
}

// Méthode pour ajouter une commande à l'historique
void Fournisseur::ajouterCommande(const string& commande) {
    historiqueCommandes.push_back(commande); //augmente dynamiquement la taille du vecteur si besoin
    nbCommandes++;
}

// Affichage des informations du fournisseur
void Fournisseur::afficherInfos() const {
    cout << "Nom: " << nom << endl;
    cout << "Nombre de commandes: " << nbCommandes << endl;
    cout << "Historique des commandes: ";
    for (int i = 0; i < this->nbCommandes; i++) {
        cout << this->historiqueCommandes[i] << ", ";
    }
    cout << endl;
}