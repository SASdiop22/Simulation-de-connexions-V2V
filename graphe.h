#ifndef GRAPHE_H
#define GRAPHE_H

#include "noeud.h"
#include "arete.h"
#include <QMap>
#include <QVector>
#include <QString>
#include <QGraphicsScene>

class graphe {
private:
    QMap<long long, noeud*> listeNoeuds; // Clé : ID du nœud
    QVector<arete*> listeAretes;

public:
    graphe();

    // Getters
    QMap<long long, noeud*> getListeNoeuds() const;
    QVector<arete*> getListeAretes() const;

    // Ajout
    void ajouteNoeud(noeud* node);
    void ajouteArete(arete* edge);

    // Méthode pour charger un fichier OSM
    void chargerDepuisOSM(const QString& fichierOSM);

    void testerNoeudVoisins() const;
    void afficherGraphe(QGraphicsScene* scene) const;

};

#endif // GRAPHE_H
