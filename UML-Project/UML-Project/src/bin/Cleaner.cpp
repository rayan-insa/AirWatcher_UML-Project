#include "Cleaner.h"

// Constructeur par défaut
Cleaner::Cleaner() : id(""), latitude(0), longitude(0), timestamp_start(), timestamp_stop(), fournisseur("") {}

// Constructeur avec paramètres
Cleaner::Cleaner(const string& id, long latitude, long longitude, const time_t timestamp_start, const time_t timestamp_stop, Fournisseur fournisseur)
    : id(id), latitude(latitude), longitude(longitude), timestamp_start(timestamp_start), timestamp_stop(timestamp_stop), fournisseur(fournisseur) {}

// Destructeur par défaut
Cleaner::~Cleaner() {}

// Getters
string Cleaner::getId() const {
    return id;
}

long Cleaner::getLatitude() const {
    return latitude;
}

long Cleaner::getLongitude() const {
    return longitude;
}

time_t Cleaner::getTimestampStart() const {
    return timestamp_start;
}

time_t Cleaner::getTimestampStop() const {
    return timestamp_stop;
}

Fournisseur Cleaner::getFournisseur() const {
    return fournisseur;
}

// Setters
void Cleaner::setId(const string& id) {
    this->id = id;
}

void Cleaner::setLatitude(long latitude) {
    this->latitude = latitude;
}

void Cleaner::setLongitude(long longitude) {
    this->longitude = longitude;
}

void Cleaner::setTimestampStart(const time_t timestamp_start) {
    this->timestamp_start = timestamp_start;
}

void Cleaner::setTimestampStop(const time_t timestamp_stop) {
    this->timestamp_stop = timestamp_stop;
}

void Cleaner::setFournisseur(Fournisseur fournisseur) {
    this->fournisseur = fournisseur;
}