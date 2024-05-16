#include <iostream>
#include <string>
#include <vector>
#include "Fournisseur.h"

using namespace std;

class Fournisseur {
private:
    string nom;
    int nbCommandes;
    vector<string> historiqueCommandes;

public:
    // Constructeur par défaut
    Fournisseur() : nom(""), nbCommandes(0) {}

    // Constructeur avec paramètres
    Fournisseur(const string& nom) : nom(nom), nbCommandes(0), historiqueCommandes() {}

    // Getters
    string getNom() const {
        return nom;
    }

    int getNbCommandes() const {
        return nbCommandes;
    }

    vector<string> getHistoriqueCommandes() const {
        return historiqueCommandes;
    }

    // Setters
    void setNom(const string& nom) {
        this->nom = nom;
    }

    void setNbCommandes(int nbCommandes) {
        this->nbCommandes = nbCommandes;
    }

    void setHistoriqueCommandes(const vector<string>& historiqueCommandes) {
        this->historiqueCommandes = historiqueCommandes;
    }

    // Méthode pour ajouter une commande à l'historique
    void ajouterCommande(const string& commande) {
        historiqueCommandes.push_back(commande); //augmente dynamiquement la taille du vecteur si besoin
        nbCommandes++;
    }

    // Affichage des informations du fournisseur
    void afficherInfos() const {
        cout << "Nom: " << nom << endl;
        cout << "Nombre de commandes: " << nbCommandes << endl;
        cout << "Historique des commandes: ";
        for (int i = 0; i < this->nbCommandes; i++) {
            cout << this->historiqueCommandes[i] << ", ";
        }
        cout << endl;
    }
};