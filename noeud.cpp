#include "noeud.h"
#include <cmath>

noeud::noeud(long long id, double lat, double lon)
    : id(id), latitude(lat), longitude(lon) {}

// Getters
long long noeud::getId() const {
    return id;
}

double noeud::getLatitude() const {
    return latitude;
}

double noeud::getLongitude() const {
    return longitude;
}

point noeud::getCoordonnees() const {
    return point(latitude, longitude);
}

// Projection Lambert 93
double noeud::X_lambert93() const {
    // Exemple simplifié de conversion (vérifiez avec vos données réelles)
    const double lambda0 = 3.0 * M_PI / 180.0; // Longitude centrale de la projection Lambert 93
    const double phi0 = 46.5 * M_PI / 180.0;   // Latitude d'origine
    const double R = 6378137.0;               // Rayon de la Terre en mètres

    double phi = latitude * M_PI / 180.0;
    double lambda = longitude * M_PI / 180.0;

    double x = R * (lambda - lambda0) * cos(phi0);
    return x;
}

double noeud::Y_lambert93() const {
    const double R = 6378137.0; // Rayon de la Terre en mètres
    double phi = latitude * M_PI / 180.0;
    return R * phi;
}

QVector<noeud*> noeud::getNoeudsVoisins() const {
    return noeudsVoisins;
}

// Ajouter un voisin
void noeud::ajouterVoisin(noeud* voisin) {
    if (!noeudsVoisins.contains(voisin)) {
        noeudsVoisins.append(voisin);
    }
}
