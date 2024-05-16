#include <iostream>
using namespace std;
#include <ctime>

class Mesure {
private:
	time_t date;
	long valeur;

public:
	Mesure();

	Mesure(time_t date, long val);

	~Mesure();

	time_t getDate();

	long getValeur();

	void setDate(time_t newDate);

	void setValeur(long val);
};