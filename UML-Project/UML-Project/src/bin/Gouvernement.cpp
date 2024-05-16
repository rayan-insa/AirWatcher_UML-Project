/*************************************************************************
                Gouvernement  -  Manipule le gouvernement
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Gouvernement> (fichier Gouvernement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

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
