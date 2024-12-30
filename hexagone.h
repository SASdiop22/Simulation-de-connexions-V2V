#ifndef HEXAGONE_H
#define HEXAGONE_H

#include "point.h"
#include <cmath>
#include <vector>
#include "Vehicule.h"
#include <QGraphicsPolygonItem>
#include <QBrush>
using namespace std;

class hexagone : public QGraphicsPolygonItem  // Héritage de QGraphicsPolygonItem
{
public:
    hexagone(point p, double rayon);  // Constructeur
    point getCentre() const;          // Obtenir le centre de l'hexagone
    double getRayon() const;          // Obtenir le rayon de l'hexagone
    vector<point> calculPoints() const;  // Calculer les sommets de l'hexagone
    bool estActif() const;            // Vérifier si l'hexagone est actif
    void setActif(bool actif);        // Activer/désactiver l'hexagone
    bool contientVehicule(const Vehicule& vehicule) const;  // Vérifier si un véhicule est dans l'hexagone
    void colorierVert(const Vehicule& vehicule);  // Colorier l'hexagone en vert si nécessaire

private:
    double d_rayon;  // Rayon de l'hexagone
    point d_centre;  // Centre de l'hexagone
    bool d_estActif; // État actif/inactif
};

#endif // HEXAGONE_H
