#include <iostream>
using namespace std;

class Attribut {
private:
	string attributID;
	string unit;
	string description;

public:
	Attribut();

	Attribut(string ID, string un, string descr);

	~Attribut();

	string getAttributID();

	string getUnit();

	string getDescription();

	void setAttributID(string ID);

	void setUnit(string un);

	void setDescription(string descr);

};