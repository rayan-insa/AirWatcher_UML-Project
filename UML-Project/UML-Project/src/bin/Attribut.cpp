#include <iostream>
#include "Attribut.h"
using namespace std;

Attribut::Attribut() {
	attributID = "";
	unit = "";
	description = "";
}

Attribut::Attribut(string ID, string un, string descr) {
	attributID = ID;
	unit = un;
	description = descr;
}

string Attribut::getAttributID() const {
	return attributID;
}

string Attribut::getUnit() const {
	return unit;
}

string Attribut::getDescription() const {
	return description;
}

void Attribut::setAttributID(string ID) {
	attributID = ID;
}

void Attribut::setUnit(string un) {
	unit = un;
}

void Attribut::setDescription(string descr) {
	description = descr;
}

Attribut::~Attribut() {

}

