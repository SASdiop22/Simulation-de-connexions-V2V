#ifndef HEXAGONE_H
#define HEXAGONE_H
#include"point.h"
#include"cmath"
#include"vector"

using namespace std;
class hexagone
{
    public:
        hexagone(double x, double y, int rayon);
        virtual ~hexagone();
        //abscisse du centre
        double getX();
        //ordonnée du centre
        double getY();
        //rayon de l'hexagone
        int getRayon();
        //methode pour verifier si un point n'est pas dans un hexagone
        bool contient(point p);
        //methode pour deplacer les poits
        void deplacerPoint(double dx, double dy);
        //methode pour calculer les 6 points de l'hexagone
        vector<point> calculPoints();

    private:
        double d_x, d_y;
        int d_rayon;
        point d_p;
        bool d_contient;

};

#endif // HEXAGONE_H
