#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fournisseur {
private:
    string nom;
    int nbCommandes;
    vector<string> historiqueCommandes;

public:
    // Constructeur par défaut
    Fournisseur();

    // Constructeur avec paramètres
    Fournisseur(const string& nom);

    // Destructeur par défaut
    ~Fournisseur();

    // Getters
    string getNom() const;
    int getNbCommandes() const;
    vector<string> getHistoriqueCommandes() const;

    // Setters
    void setNom(const string& nom);
    void setNbCommandes(int nbCommandes);
    void setHistoriqueCommandes(const vector<string>& historiqueCommandes);

    // Méthode pour ajouter une commande à l'historique
    void ajouterCommande(const string& commande);

    // Affichage des informations du fournisseur
    void afficherInfos() const;
};

#endif // FOURNISSEUR_H
