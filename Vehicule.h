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
        point getPosition();
        void setPosition(point val);
        double getPuissance();
        void setPuissance(double val);
        double getFrequence();
        void setFrequence(double f);
        void deplace(point p); // Déplacement du véhicule
        void connecteAvec(Vehicule* VB); // Connecter à un autre véhicule
        void deconnecteDe(Vehicule* VB); // Déconnecter
        bool estConnecteAvec(const Vehicule* VB) const; //Verifier la connection entre deux véhicules

    private:
        int id;
        point position;
        double puissance;
        double frequence;
        //liste des véhicules à qui il s'est connecté
        std::vector<Vehicule*> vehiclesConnectes;
};

#endif // VEHICULE_H
