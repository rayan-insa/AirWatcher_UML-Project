/*************************************************************************
                Utilisateur  -  Manipule les Utilisateur
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
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
