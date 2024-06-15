#include <iostream>
#include <fstream>
#include <vector>

// Structure pour représenter un siège
struct Siege {
    int numero;
    bool occupe;
};

// Fonction pour attribuer les sièges
void attribuerSieges(const std::string& fichierSieges, const std::string& fichierAttributions) {
    // Lire les informations des sièges à partir du fichier
    std::ifstream fichier(fichierSieges);
    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier des sièges." << std::endl;
        return;
    }

    std::vector<Siege> sieges;
    int numeroSiege;
    while (fichier >> numeroSiege) {
        sieges.push_back({numeroSiege, false});
    }

    fichier.close();

    // Lire les attributions des sièges à partir du fichier
    fichier.open(fichierAttributions);
    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier des attributions." << std::endl;
        return;
    }

    int numeroSiegeAttribue;
    while (fichier >> numeroSiegeAttribue) {
        // Vérifier si le siège est valide
        if (numeroSiegeAttribue < 1 || numeroSiegeAttribue > sieges.size()) {
            std::cerr << "Numéro de siège invalide : " << numeroSiegeAttribue << std::endl;
            continue;
        }

        // Vérifier si le siège est déjà occupé
        if (sieges[numeroSiegeAttribue - 1].occupe) {
            std::cerr << "Le siège " << numeroSiegeAttribue << " est déjà occupé." << std::endl;
            continue;
        }

        // Attribuer le siège
        sieges[numeroSiegeAttribue - 1].occupe = true;
        std::cout << "Le siège " << numeroSiegeAttribue << " a été attribué." << std::endl;
    }

    fichier.close();
}

int main() {
    std::string fichierSieges = "chemin/vers/fichier_sieges.txt";
    std::string fichierAttributions = "chemin/vers/fichier_attributions.txt";

    attribuerSieges(fichierSieges, fichierAttributions);

    return 0;
}