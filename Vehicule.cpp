#include "Vehicule.h"

Vehicule::Vehicule(int ident, double p, double f) : id{ident}, puissance{p}, frequence{f}, position{}
{

}

int Vehicule::getId()
{ return id; }

point Vehicule::getPosition() const
{ return position; }

void Vehicule::setPosition(point val)
{ position = val; }

double Vehicule::getPuissance()
{ return puissance; }

void Vehicule::setPuissance(double val)
{ puissance = val; }
void Vehicule::deplace(point p)
{
    position.deplaceEn(p.x(),p.y());
}

void Vehicule::connecteAvec(Vehicule* VB)
{
    if(!estConnecteAvec(VB))
    {
        vehiclesConnectes.push_back(VB);
    }
}

bool Vehicule::estConnecteAvec(const Vehicule* VB) const
{
    int t = vehiclesConnectes.size();
    int i = 0;
    while(i < t)
    {
        if(vehiclesConnectes[i]->id == VB->id)
        {
            return true;
        }
        i++;
    }
    return false;
}

void Vehicule::deconnecteDe(Vehicule* VB)
{
    if(estConnecteAvec(VB))
    {

    }
}
