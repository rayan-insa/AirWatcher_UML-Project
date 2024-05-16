#include <iostream>
using namespace std;

class Capteur
{
private:
	long latitude;
	long longitude;
	bool defaillant;

public:
	Capteur();

	Capteur(long lat, long lon, bool def);

	~Capteur();

	long getLatitude();

	long getLongitude();

	bool getDefaillant();

	void setLatitude(long lat);

	void setLongitude(long lon);

	void setDefaillant(bool def);

};