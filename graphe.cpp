#include "graphe.h"
#include <algorithm> // Inclure pour std::find
#include <iostream>

// M�thode pour ajouter un n�ud
void GrapheRoutier::ajouterNoeud(const noeud& n) {
    noeuds.push_back(n);
    // Ajouter � la map pour un acc�s rapide
    noeuds_map[n.getId()] = &noeuds.back();
}

// M�thode pour ajouter une ar�te
void GrapheRoutier::ajouterArete(const Arete& a) {
    aretes.push_back(a);
}

// M�thode pour r�cup�rer tous les n�uds
const std::vector<Noeud>& GrapheRoutier::getNoeuds() const {
    return noeuds;
}

// M�thode pour r�cup�rer toutes les ar�tes
const std::vector<Arete>& GrapheRoutier::getAretes() const {
    return aretes;
}

// M�thode pour r�cup�rer un n�ud par son ID
Noeud* GrapheRoutier::getNoeud(osmium::object_id_type id) const {
    auto it = noeuds_map.find(id);
    if (it != noeuds_map.end()) {
        return it->second;
    }
    return nullptr; // N�ud non trouv�
}

// M�thode pour afficher le graphe
void GrapheRoutier::afficherGraphe() const {
    std::cout << "N�uds du graphe :\n";
    for (const auto& n : noeuds) {
        std::cout << "ID: " << n.getId() << ", Lat: " << n.getLatitude() << ", Lon: " << n.getLongitude() << "\n";
    }

    std::cout << "Ar�tes du graphe :\n";
    for (const auto& a : aretes) {
        std::cout << "Arete de " << a.getDebut()->getId() << " � " << a.getFin()->getId() << ", Distance: " << a.getDistance() << "\n";
    }
}





/*Noeud* GrapheRoutier::getNoeudParId(osmium::object_id_type id) {
    // Utilisez std::find pour chercher le n�ud par son ID
    auto it = std::find_if(noeuds.begin(), noeuds.end(),
        [id](const Noeud& n) { return n.getId() == id; });

    if (it != noeuds.end()) {
        return &(*it); // Retournez le n�ud trouv�
    }
    return nullptr; // N�ud non trouv�
}
*/
