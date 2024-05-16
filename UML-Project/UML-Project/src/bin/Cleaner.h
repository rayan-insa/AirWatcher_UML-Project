#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include <ctime>

using namespace std;

class Cleaner {
private:
    long latitude;
    long longitude;
    time_t timestamp_start;
    time_t timestamp_stop;
    string fournisseur;
    string id; // Nouvel attribut

public:
    // Constructeurs
    Cleaner();
    Cleaner(const string& id, long latitude, long longitude, const time_t timestamp_start, const time_t timestamp_stop, const string& fournisseur);

    // Destructeur
    ~Cleaner();

    // Getters
    long getLatitude() const;
    long getLongitude() const;
    time_t getTimestampStart() const;
    time_t getTimestampStop() const;
    string getFournisseur() const;
    string getId() const; // Nouvelle méthode pour obtenir l'ID

    // Setters
    void setLatitude(long latitude);
    void setLongitude(long longitude);
    void setTimestampStart(const time_t timestamp_start);
    void setTimestampStop(const time_t timestamp_stop);
    void setFournisseur(const string& fournisseur);
    void setId(const string& id); // Nouvelle méthode pour définir l'ID
};

#endif // CLEANER_H
