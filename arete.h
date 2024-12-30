#ifndef ARETE_H
#define ARETE_H

#include "noeud.h"
#include <QString>
#include <cmath>

class arete {
private:
    noeud* debut;
    noeud* fin;
    QString id;   // ID de l'arête provenant de OSM
    QString type; // Type de route (autoroute, nationale, etc.)

public:
    arete(noeud* debut = nullptr, noeud* fin = nullptr);

    // Getters et Setters
    noeud* getDebut() const;
    void setDebut(noeud* newDebut);

    noeud* getFin() const;
    void setFin(noeud* newFin);

    QString getId() const;
    void setId(const QString& newId);

    QString getType() const;
    void setType(const QString& newType);

    // Calcul de distance en km (Haversine)
    double getDistance() const;

    // Calcul de distance en projection Lambert 93
    double getDistanceLambert93() const;
};

#endif // ARETE_H
