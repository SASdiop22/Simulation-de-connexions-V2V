#include "hexagone.h"

hexagone::hexagone(point p, double rayon):d_centre{p}, d_rayon{rayon}
{}

point hexagone::getCentre() const
{
    return d_centre;
}
double hexagone::getRayon()
{
    return d_rayon;
}

vector<point> hexagone::calculPoints()
{
    vector<point> points;
    double angle_debut = M_PI / 6; // Début à 30 degrés
    for (int i = 0; i < 6; ++i) {
        double angle = angle_debut + i * M_PI / 3; // 60 degrés entre chaque sommet
        double pointX = d_centre.x() + getRayon() * cos(angle);
        double pointY = d_centre.y() + getRayon() * sin(angle);
        point sommet(pointX, pointY);
        points.push_back(sommet);
    }
    return points;
}

bool hexagone::estActif() const {
    return d_estActif;
}

void hexagone::setActif(bool actif) {
    d_estActif = actif;
}

