/*************************************************************************
                Utilisateur  -  Manipule les Utilisateur
                             -------------------
    début                : 16/05/2024
    copyright            : (C) 2024 by Hanader Rayan & Dugast Eleonore  
                            & Cavagna Justine  & Soulet Audrey 
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


string Utilisateur::getLogin()
{
    return this->login;
}

Utilisateur::Utilisateur ( )
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Utilisateur>" << endl;
#endif
}

Utilisateur::Utilisateur ( string login )
{
#ifdef MAP
    cout << "Appel au constructeur de <Utilisateur>" << endl;
#endif

    this->login = login;
} //----- Fin de Utilisateur


Utilisateur::~Utilisateur ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Utilisateur>" << endl;
#endif
} //----- Fin de ~Utilisateur
