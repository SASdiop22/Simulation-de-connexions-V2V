#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED


#include "noeud.h"
#include <cmath>
#include <string>
using namespace std;

class Arete {
private:
    Noeud* debut;
    Noeud* fin;
    string id;   // ID de l'ar�te provenant de OSM
    string type; // Type de route (autoroute, nationale, etc.)

public:
    Arete(Noeud* debut, Noeud* fin);

    Noeud* getDebut() const;
    void setDebut(Noeud* newDebut);

    Noeud* getFin() const;
    void setFin(Noeud* newFin);

    double getDistance() const;

    //void calculerDistance();// M�thode pour calculer la distance entre les n�uds
    double getDistanceLambert93() const;

    string getId() const;
    void setId(const string& newId);

   string getType() const;
    void setType(const string& newType);


};



#endif // ARETE_H_INCLUDED
