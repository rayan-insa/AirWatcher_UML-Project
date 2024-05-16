#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include <ctime>
#include "Fournisseur.h"

using namespace std;

class Cleaner {
private:
    string id;
    long latitude;
    long longitude;
    time_t timestamp_start;
    time_t timestamp_stop;
    Fournisseur fournisseur;

public:
    // Constructeurs
    Cleaner();
    Cleaner(const string& id, long latitude, long longitude, const time_t timestamp_start, const time_t timestamp_stop, Fournisseur fournisseur);

    // Destructeur
    ~Cleaner();

    // Getters
    long getLatitude() const;
    long getLongitude() const;
    time_t getTimestampStart() const;
    time_t getTimestampStop() const;
    Fournisseur getFournisseur() const;
    string getId() const; // Nouvelle méthode pour obtenir l'ID

    // Setters
    void setId(const string& id);
    void setLatitude(long latitude);
    void setLongitude(long longitude);
    void setTimestampStart(const time_t timestamp_start);
    void setTimestampStop(const time_t timestamp_stop);
    void setFournisseur(Fournisseur fournisseur);
};

#endif // CLEANER_H
