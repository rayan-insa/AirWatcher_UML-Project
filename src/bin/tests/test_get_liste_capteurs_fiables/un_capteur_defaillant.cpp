#include "Model.h"
#include "test_helpers.h"
#include "aucun_capteur_fiable.cpp"

void test_un_capteur_defaillant() {
    Model model;

    // Setup
    Capteur capteur1 = Capteur("c1", 1.03, 2.45, true, Utilisateur());
    Capteur capteur2 = Capteur("c2", 1.03, 2.45, false, Utilisateur());
    Capteur capteur3 = Capteur("c3", 1.03, 2.45, false, Utilisateur());

    std::vector<Capteur> listeCapteurs = {};

    listeCapteurs.push_back(capteur1);
    listeCapteurs.push_back(capteur2);
    listeCapteurs.push_back(capteur3);

    model.setListeCapteurs(listeCapteurs);

    // Execute
    std::vector<Capteur> result = model.get_liste_capteurs_fiables();

    // Test
    test_assert(result.size() == 2, "get_liste_capteurs_fiables", "Deux capteurs fiables sur trois");
    test_assert(result[0].getDefaillant() == false, "get_liste_capteurs_fiables", "Premier capteur fiable correct");
    test_assert(result[1].getDefaillant() == false, "get_liste_capteurs_fiables", "Deuxième capteur fiable correct");
}

int main() {
    test_un_capteur_defaillant();
    test_aucun_capteur_fiable();
    return 0;
}
