#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED
#include "point.h"

#include <osmium/osm/types.hpp>
#include <string>
#include <osmium/osm.hpp> // Assurez-vous d'avoir la bonne biblioth�que OSM

class Noeud {
private:
    osmium::object_id_type id;
    double latitude;
    double longitude;

public:
    Noeud(osmium::object_id_type id, double lat, double lon);

    // Getters
    osmium::object_id_type getId() const;
    double getLatitude() const;
    double getLongitude() const;
    point getCoordonnees() const;

    double X_lambert93() const;
    double Y_lambert93() const;



};



#endif // NOEUD_H_INCLUDED
