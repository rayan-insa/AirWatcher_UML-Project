#include "Model.h"
#include "test_helpers.h"

void test_aucun_capteur_fiable() {
    Model model;

    // Setup
    Capteur capteur1 = Capteur("c1", 1.03, 2.45, true, Utilisateur());
    Capteur capteur2 = Capteur("c2", 1.03, 2.45, true, Utilisateur());
    Capteur capteur3 = Capteur("c3", 1.03, 2.45, true, Utilisateur());

    std::vector<Capteur> listeCapteurs = model.getListeCapteurs();
    listeCapteurs.push_back(capteur1);
    listeCapteurs.push_back(capteur2);
    listeCapteurs.push_back(capteur3);
    model.setListeCapteurs(listeCapteurs);

    // Execute
    std::vector<Capteur> result = model.get_liste_capteurs_fiables();

    // Test
    test_assert(result.size() == 0, "get_liste_capteurs_fiables", "Aucun capteur fiable attendu");
}
