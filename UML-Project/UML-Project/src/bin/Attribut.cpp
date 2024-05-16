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

string Attribut::getAttributID() {
	return attributID;
}

string Attribut::getUnit() {
	return unit;
}

string Attribut::getDescription() {
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

