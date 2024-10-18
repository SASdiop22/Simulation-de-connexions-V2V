#include "hexagone.h"

hexagone::hexagone(double x, double y, int rayon):d_x{x}, d_y{y}, d_rayon{rayon}
{}

hexagone::~hexagone()
{}

double hexagone::getX()
{
    return d_x;
}

double hexagone::getY()
{
    return d_y;
}

int hexagone::getRayon()
{
    return d_rayon;
}

bool hexagone::contient(point p)
{
    return d_contient;
}

void hexagone::deplacerPoint(double dx, double dy)
{
    d_x = dx;
    d_y = dy;
}

vector<point> hexagone::calculPoints()
{
    vector<point> points;
    double angle_debut = M_PI / 6; // Début à 30 degrés
    for (int i = 0; i < 6; ++i) {
        double angle = angle_debut + i * M_PI / 3; // 60 degrés entre chaque sommet
        double pointX = getX() + getRayon() * cos(angle);
        double pointY = getY() + getRayon() * sin(angle);
        points.emplace_back(pointX, pointY);
    }
    return points;
}

