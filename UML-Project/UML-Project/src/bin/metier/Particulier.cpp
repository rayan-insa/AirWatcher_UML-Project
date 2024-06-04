/*************************************************************************
                Particulier  -  Manipule les Particuliers
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Réalisation de la classe <Particulier> (fichier Particulier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
//------------------------------------------------------ Include personnel
#include "Particulier.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Particulier::Particulier ( )
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Particulier>" << endl;
#endif
}

Particulier::Particulier ( string login, int points, bool fiable ) : Utilisateur ( login )
{
#ifdef MAP
    cout << "Appel au constructeur de <Particulier>" << endl;
#endif

this->login = login;
this->points = 0;
this->fiable = true;
} //----- Fin de Particulier

int Particulier::getPoints()
{
    return this->points;
}

bool Particulier::getFiable()
{
    return this->fiable;
}

Particulier::~Particulier ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Particulier>" << endl;
#endif
} //----- Fin de ~Particulier
