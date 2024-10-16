#ifndef ARETE_H
#define ARETE_H

#include "Sommet.h"

class Arete {
private:
    int poids;
    Sommet* debut;
    Sommet* arrivee;
    friend class Graphe;
public:
    Arete(Sommet* s1, Sommet* s2, int donnee);
    Sommet* getDebut() const;
    Sommet* getArrivee() const;
    int getPoids() const ;
    Arete& operator=(const Arete& other);
};

#endif // ARETE_H
