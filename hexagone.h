#ifndef HEXAGONE_H
#define HEXAGONE_H
#include"point.h"
#include"cmath"
#include"vector"

using namespace std;
class hexagone
{
    public:
        hexagone(point p, double rayon);
//        //abscisse du centre
//        double getX();
//        //ordonnée du centre
//        double getY();
        point getCentre() const;
        //rayon de l'hexagone
        double getRayon();
        //methode pour calculer les 6 points de l'hexagone
        vector<point> calculPoints();
        bool estActif() const;
        void setActif(bool actif);

    private:
        double d_rayon;
        point d_centre;
        bool d_estActif;

};

#endif // HEXAGONE_H
