#ifndef GRAPHEROUTIER_H_INCLUDED
#define GRAPHEROUTIER_H_INCLUDED


#include "noeud.h"
#include "arete.h"
#include <vector>
#include <unordered_map>
#include <string>

class GrapheRoutier {
private:
    std::vector<Noeud> noeuds;
    std::vector<Arete> aretes;
    std::unordered_map<osmium::object_id_type, Noeud*> noeuds_map; // Pour un acc�s rapide aux n�uds

public:
    // Constructeur
    GrapheRoutier() = default;

    // M�thodes pour ajouter des n�uds et des ar�tes
    void ajouterNoeud(const Noeud& n);
    void ajouterArete(const Arete& a);

    // M�thodes pour r�cup�rer les n�uds et les ar�tes
    const std::vector<Noeud>& getNoeuds() const;
    const std::vector<Arete>& getAretes() const;

    Noeud* getNoeud(osmium::object_id_type id) const;

    // M�thode pour afficher le graphe
    void afficherGraphe() const;

    // M�thode pour trouver le chemin entre deux n�uds (par exemple, recherche en largeur)
    //std::vector<Noeud*> trouverChemin(Noeud* depart, Noeud* arrivee);

   // Noeud* getNoeudParId(osmium::object_id_type id);
};



#endif // GRAPHEROUTIER_H_INCLUDED
