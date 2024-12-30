#include "hexagone.h"
#include <QPolygonF>
#include <QBrush>

hexagone::hexagone(point p, double rayon)
    : d_rayon{rayon}, d_centre{p}, d_estActif{false} {
    // Calculez les sommets de l'hexagone
    vector<point> points = calculPoints();

    // Convertir les sommets en QPolygonF
    QPolygonF polygon;
    for (const auto& sommet : points) {
        polygon << QPointF(sommet.x(), sommet.y());
    }

    // Définir le polygone graphique
    setPolygon(polygon);

    // Appliquer une couleur de remplissage initiale
    setBrush(QBrush(Qt::gray));
}

point hexagone::getCentre() const {
    return d_centre;
}

double hexagone::getRayon() const {
    return d_rayon;
}

vector<point> hexagone::calculPoints() const {
    vector<point> points;
    double angle_debut = M_PI / 6;  // Début à 30 degrés
    for (int i = 0; i < 6; ++i) {
        double angle = angle_debut + i * M_PI / 3;  // 60 degrés entre chaque sommet
        double pointX = d_centre.x() + getRayon() * cos(angle);
        double pointY = d_centre.y() + getRayon() * sin(angle);
        points.emplace_back(pointX, pointY);
    }
    return points;
}

bool hexagone::estActif() const {
    return d_estActif;
}

void hexagone::setActif(bool actif) {
    d_estActif = actif;
}

bool hexagone::contientVehicule(const Vehicule& vehicule) const {
    point vehiculePos = vehicule.getPosition();
    vector<point> pointsHexagone = calculPoints();

    int n = pointsHexagone.size();
    bool result = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((pointsHexagone[i].y() > vehiculePos.y()) != (pointsHexagone[j].y() > vehiculePos.y())) &&
            (vehiculePos.x() < (pointsHexagone[j].x() - pointsHexagone[i].x()) * (vehiculePos.y() - pointsHexagone[i].y()) / (pointsHexagone[j].y() - pointsHexagone[i].y()) + pointsHexagone[i].x())) {
            result = !result;
        }
    }

    return result;
}

void hexagone::colorierVert(const Vehicule& vehicule) {
    if (contientVehicule(vehicule)) {
        setBrush(QBrush(Qt::green));  // Changer la couleur de remplissage en vert
        update();                     // Actualiser le dessin
    }
}
