/*************************************************************************
                View  -  Manipule le View
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <View> (fichier View.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
//------------------------------------------------------ Include personnel
using namespace std;
#include "View.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


string View::getTexteVueCourante() const
{
    return this->texteVueCourante;
}

string View::getEntreeUtilisateur() const
{
    return this->entreeUtilisateur;
}

void View::setTexteVueCourante(string texteVueCourante)
{   
    this->texteVueCourante = texteVueCourante;
}

void View::afficherVue()
{   
    cout << this->texteVueCourante << endl;
    cin >> this->entreeUtilisateur;
}

void View::afficherVueSansEntreeUtilisateur() const
{
    cout << this->texteVueCourante << endl;
}

View::View ( ) {
#ifdef MAP
    cout << "Appel au constructeur par défault de <View>" << endl;
#endif
}


View::~View ()
{
#ifdef MAP
    cout << "Appel au destructeur de <View>" << endl;
#endif
} //----- Fin de ~View
