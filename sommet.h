#ifndef SOMMET_H
#define SOMMET_H

#include "Point.h"

class Sommet {

private:
    int id;
    int x, y;

public:
    Sommet(int identifiant, int x, int y);
    Sommet(int identifiant);
    int getId() const;
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int x);
    // Getters et setters pour d'autres données du sommet
};

#endif // SOMMET_Hs
