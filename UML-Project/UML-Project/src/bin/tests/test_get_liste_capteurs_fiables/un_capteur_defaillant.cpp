#include "Model.h"
#include "test_helpers.h"

void test_un_capteur_defaillant() {
    Model model;

    // Setup
    Capteur capteur1, capteur2, capteur3;
    capteur1.defaillant = false;
    capteur2.defaillant = true;
    capteur3.defaillant = false;

    model.listeCapteurs.push_back(capteur1);
    model.listeCapteurs.push_back(capteur2);
    model.listeCapteurs.push_back(capteur3);

    // Execute
    std::vector<Capteur> result = model.get_liste_capteurs_fiables();

    // Test
    test_assert(result.size() == 2, "get_liste_capteurs_fiables", "Deux capteurs fiables attendus");
    test_assert(result[0].getDefaillant() == false, "get_liste_capteurs_fiables", "Premier capteur fiable correct");
    test_assert(result[1].getDefaillant() == false, "get_liste_capteurs_fiables", "Deuxième capteur fiable correct");
}

int main() {
    test_un_capteur_defaillant();
    return 0;
}
