#include "Model.h"
#include "test_helpers.h"

void test_aucun_capteur_defaillant() {
    Model model;

    // Setup
    Capteur capteur1, capteur2, capteur3;
    capteur1.setDefaillant(false);
    capteur1.setDefaillant(false);
    capteur1.setDefaillant(false);

    std::vector<Capteur> listeCapteurs = model.getListeCapteurs();
    listeCapteurs.push_back(capteur1);
    listeCapteurs.push_back(capteur2);
    listeCapteurs.push_back(capteur3);
    model.setListeCapteurs(listeCapteurs);

    // Execute
    std::vector<Capteur> result = model.get_liste_capteurs_fiables();

    // Test
    test_assert(result.size() == 3, "get_liste_capteurs_fiables", "Trois capteurs fiables attendus");
    test_assert(result[0].getDefaillant() == false, "get_liste_capteurs_fiables", "Premier capteur fiable correct");
    test_assert(result[1].getDefaillant() == false, "get_liste_capteurs_fiables", "Deuxième capteur fiable correct");
    test_assert(result[2].getDefaillant() == false, "get_liste_capteurs_fiables", "Troisième capteur fiable correct");
}

int main() {
    test_aucun_capteur_defaillant();
    return 0;
}
