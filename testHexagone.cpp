#include "hexagone.h"
#include "doctest.h"
#include <cmath>
#include <iostream>
TEST_CASE("Tests du constructeur et des getters de la classe hexagone") {
    point centre(0, 0);
    hexagone h(centre, 5);

    CHECK(h.getCentre() == centre);
    CHECK(h.getRayon() == 5);
}

TEST_CASE("Tests de la méthode calculPoints() de la classe hexagone") {
    point centre(2, 2);
    hexagone h(centre, 5.0);
    vector<point> points = h.calculPoints();

    REQUIRE_EQ(points.size(),6);
        double angleDebut = M_PI / 6;
       // std::cout << M_PI/6 << " | " << sin(M_PI/6)<< " | " << sin(30) ;
    for (int i = 0; i < 5; ++i) {
        double angle = angleDebut + M_PI / 3 * i;
        point p = point(2 + 5.0 * cos(angle), 2+  5.0 * sin(angle));
        points[i].affiche();
        p.affiche();
        //CHECK(points[i] == p);
        REQUIRE_EQ(points[i] == p,true);
    }
}
