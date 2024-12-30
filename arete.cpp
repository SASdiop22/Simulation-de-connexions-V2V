#include "arete.h"
#include <cmath>

arete::arete(noeud* debut, noeud* fin)
    : debut(debut), fin(fin), id(""), type("") {}

// Getters et Setters
noeud* arete::getDebut() const {
    return debut;
}

void arete::setDebut(noeud* newDebut) {
    debut = newDebut;
}

noeud* arete::getFin() const {
    return fin;
}

void arete::setFin(noeud* newFin) {
    fin = newFin;
}

QString arete::getId() const {
    return id;
}

void arete::setId(const QString& newId) {
    id = newId;
}

QString arete::getType() const {
    return type;
}

void arete::setType(const QString& newType) {
    type = newType;
}

// Calcul de la distance entre les nœuds (Haversine, en km)
double arete::getDistance() const {
    if (!debut || !fin) return 0.0;

    const double R = 6371.0; // Rayon de la Terre en km
    double lat1 = debut->getLatitude() * M_PI / 180.0;
    double lon1 = debut->getLongitude() * M_PI / 180.0;
    double lat2 = fin->getLatitude() * M_PI / 180.0;
    double lon2 = fin->getLongitude() * M_PI / 180.0;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}

// Calcul de la distance en projection Lambert 93
double arete::getDistanceLambert93() const {
    if (!debut || !fin) return 0.0;

    double x1 = debut->X_lambert93();
    double y1 = debut->Y_lambert93();
    double x2 = fin->X_lambert93();
    double y2 = fin->Y_lambert93();

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
