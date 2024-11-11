#include "Noeud.h"
#include <cmath>
#include "point.h"

const double PI = M_PI;

// Constantes pour la projection Lambert 93
const double X_OFFSET = 700000; // Déplacement en X
const double Y_OFFSET = 6600000; // Déplacement en Y
const double LAMBERT_A = 6378137; // Rayon de la Terre
const double LAMBERT_F = 1 / 298.257223563; // Aplatissement
const double LAMBERT_N = 0.730883; // Paramètre de projection
const double LAMBERT_E = 5.1227; // Paramètre d'excentricité

Noeud::Noeud(osmium::object_id_type id, double lat, double lon)
    : id(id), latitude(lat), longitude(lon) {

}

osmium::object_id_type Noeud::getId() const {
    return id;
}

double Noeud::getLatitude() const {
    return latitude;
}

double Noeud::getLongitude() const {
    return longitude;
}


point Noeud::getCoordonnees() const{
    return point(X_lambert93(),Y_lambert93());
 }

// Méthodes de conversion Lambert 93
double Noeud::X_lambert93() const {
    return X_OFFSET + (LAMBERT_A * std::cos(latitude * PI / 180) * std::sin(longitude * PI / 180) / (1 - LAMBERT_E * std::sin(latitude * PI / 180)));
}

double Noeud::Y_lambert93() const {
    return Y_OFFSET + (LAMBERT_A * std::sin(latitude * PI / 180) / (1 - LAMBERT_E * std::sin(latitude * PI / 180)));
}



