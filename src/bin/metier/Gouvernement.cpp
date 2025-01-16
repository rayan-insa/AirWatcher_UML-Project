/*************************************************************************
                Gouvernement  -  Manipule le gouvernement
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Réalisation de la classe <Gouvernement> (fichier Gouvernement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Gouvernement.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Gouvernement::Gouvernement ( )
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Gouvernement>" << endl;
#endif
}

Gouvernement::Gouvernement ( string login ) : Utilisateur ( login )
{
#ifdef MAP
    cout << "Appel au constructeur de <Gouvernement>" << endl;
#endif

this->login = login;
} //----- Fin de Gouvernement


Gouvernement::~Gouvernement ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Gouvernement>" << endl;
#endif
} //----- Fin de ~Gouvernement
