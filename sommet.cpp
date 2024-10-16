#include "Sommet.h"
#include <iostream>
Sommet::Sommet(int identifiant): id{identifiant}, x{0},y{0} {}
Sommet::Sommet(int identifiant, int xi, int yi) : id{identifiant}, x{xi}, y{yi}
{}
int Sommet::getId() const
{ return id;}

int Sommet::getX() const
{ return x; }
void Sommet::setX(int xi)
{
    x = xi;
}
int Sommet::getY() const
{ return y; }
void Sommet::setY(int yi)
{
    x = yi;
}
