#include "Arete.h"

Arete::Arete(Sommet* s1, Sommet* s2, int donnee) : debut(s1), arrivee(s2), poids{donnee}
{}

Sommet* Arete::getDebut() const
 { return debut; }

Sommet* Arete::getArrivee() const
 { return arrivee; }
int Arete:: getPoids() const
{
    return poids;
}

Arete& Arete::operator=(const Arete& other) {
    if (this != &other) {
        poids = other.poids;
        debut = other.debut;
        arrivee = other.arrivee;
    }
    return *this;
}
