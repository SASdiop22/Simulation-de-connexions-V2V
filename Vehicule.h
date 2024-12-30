#ifndef VEHICULE_H
#define VEHICULE_H
#include "point.h"
#include <vector>
class Vehicule
{
public:
    Vehicule();
    Vehicule(int ident, double p, double f);

    int getId();
    point getPosition() const;
    void setPosition(point val);
    double getPuissance();
    void setPuissance(double val);
    double getFrequence();
    void setFrequence(double f);
    void deplace(point p); // D?placement du v?hicule
    void connecteAvec(Vehicule* VB); // Connecter ? un autre v?hicule
    void deconnecteDe(Vehicule* VB); // D?connecter
    bool estConnecteAvec(const Vehicule* VB) const; //Verifier la connection entre deux v?hicules

private:
    int id;
    point position;
    double puissance;
    double frequence;
    //liste des v?hicules ? qui il s'est connect?
    std::vector<Vehicule*> vehiclesConnectes;
};

#endif // VEHICULE_H
