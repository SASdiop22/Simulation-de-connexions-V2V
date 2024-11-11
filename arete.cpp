#include "Arete.h"

Arete::Arete(Noeud* debut, Noeud* fin)
    : debut(debut), fin(fin) {

}


double Arete::getDistanceLambert93() const{
    double dx = debut->X_lambert93() - fin->X_lambert93();
    double dy = debut->Y_lambert93() - fin->Y_lambert93();
    return sqrt(dx * dx + dy * dy);

}
Noeud* Arete::getDebut() const {
    return debut;
}

void Arete::setDebut(Noeud* newDebut) {
    debut = newDebut;

}

Noeud* Arete::getFin() const {
    return fin;
}

void Arete::setFin(Noeud* newFin) {
    fin = newFin;

}

double Arete::getDistance() const {
    double dx = debut->getLongitude() - fin->getLongitude();
    double dy = debut->getLatitude() - fin->getLatitude();
    return sqrt(dx * dx + dy * dy);

}

std::string Arete::getId() const {
    return id;
}

void Arete::setId(const std::string& newId) {
    id = newId;
}

std::string Arete::getType() const {
    return type;
}

void Arete::setType(const std::string& newType) {
    type = newType;
}
