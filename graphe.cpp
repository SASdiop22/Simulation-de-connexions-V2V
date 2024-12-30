#include "graphe.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

graphe::graphe() {}

// Getters
QMap<long long, noeud*> graphe::getListeNoeuds() const {
    return listeNoeuds;
}

QVector<arete*> graphe::getListeAretes() const {
    return listeAretes;
}

//afficher le graphe

void graphe::afficherGraphe(QGraphicsScene* scene) const{
    if (listeNoeuds.isEmpty() || listeAretes.isEmpty()) {
        qWarning() << "Le graphe est vide ou incomplet.";
        return;
    }

    // Définir un facteur d'échelle arbitraire pour adapter les nœuds à la scène
    double scaleFactor = 10.0;  // Facteur pour ajuster la taille du graphe

    // Initialiser les bornes de la scène (pour calculer la taille de la scène)
    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::lowest();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::lowest();

    // Affichage des arêtes et calcul des bornes de la scène
    for (const auto& edge : listeAretes) {
        noeud* debut = edge->getDebut();
        noeud* fin = edge->getFin();

        if (!debut || !fin) continue;

        // Utilisation des coordonnées arbitraires pour l'affichage
        double x1 = debut->getLatitude() * scaleFactor;  // Utilisation de la latitude comme coordonnée arbitraire
        double y1 = debut->getLongitude() * scaleFactor;  // Utilisation de la longitude comme coordonnée arbitraire
        double x2 = fin->getLatitude() * scaleFactor;
        double y2 = fin->getLongitude() * scaleFactor;

        // Créer et ajouter l'arête (ligne) à la scène
        QGraphicsLineItem* line = new QGraphicsLineItem(x1, y1, x2, y2);
        line->setPen(QPen(Qt::blue, 1));  // Couleur et épaisseur de l'arête
        scene->addItem(line);

        // Mettre à jour les bornes de la scène
        minX = std::min(minX, std::min(x1, x2));
        maxX = std::max(maxX, std::max(x1, x2));
        minY = std::min(minY, std::min(y1, y2));
        maxY = std::max(maxY, std::max(y1, y2));
    }

    // Affichage des nœuds et mise à jour des bornes
    for (const auto& node : listeNoeuds) {
        // Utilisation des coordonnées arbitraires
        double x = node->getLatitude() * scaleFactor;  // Latitude comme coordonnée X
        double y = node->getLongitude() * scaleFactor;  // Longitude comme coordonnée Y

        // Créer un nœud sous forme de cercle
        QGraphicsEllipseItem* point = new QGraphicsEllipseItem(x - 2, y - 2, 4, 4);  // Cercle de rayon 2
        point->setBrush(Qt::red);  // Couleur des nœuds
        scene->addItem(point);

        // Mettre à jour les bornes de la scène
        minX = std::min(minX, x);
        maxX = std::max(maxX, x);
        minY = std::min(minY, y);
        maxY = std::max(maxY, y);
    }

    // Définir la taille de la scène en fonction des bornes calculées
    scene->setSceneRect(minX, minY, maxX - minX, maxY - minY);

    // Optionnel: pour ajuster le zoom automatique de la scène
    qDebug() << "Graphe affiché avec" << listeNoeuds.size() << "nœuds et" << listeAretes.size() << "arêtes.";
}



/*void graphe::afficherGraphe(QGraphicsScene* scene) const {
    if (!scene) return;

    // Efface tout ce qui est dans la scène
    scene->clear();

    // Définir les dimensions pour les nœuds (petits cercles)
    const double nodeRadius = 2.0;

    // Dessiner les arêtes
    for (const auto& edge : listeAretes) {
        noeud* debut = edge->getDebut();
        noeud* fin = edge->getFin();

        if (debut && fin) {
            double x1 = debut->X_lambert93() / 1000; // Diviser pour normaliser l'échelle
            double y1 = -debut->Y_lambert93() / 1000;
            double x2 = fin->X_lambert93() / 1000;
            double y2 = -fin->Y_lambert93() / 1000;

            scene->addLine(x1, y1, x2, y2, QPen(Qt::black));
        }
    }

    // Dessiner les nœuds
    for (const auto& node : listeNoeuds) {
        double x = node->X_lambert93() / 1000; // Normalisation
        double y = -node->Y_lambert93() / 1000; // Inverser pour adapter à l'écran

        scene->addEllipse(x - nodeRadius, y - nodeRadius,
                          nodeRadius * 2, nodeRadius * 2,
                          QPen(Qt::red), QBrush(Qt::red));
    }
}*/

// Ajout de nœuds et d’arêtes
void graphe::ajouteNoeud(noeud* node) {
    listeNoeuds[node->getId()] = node;
}

void graphe::ajouteArete(arete* edge) {
    listeAretes.append(edge);
}

// Charger un fichier OSM
/*void graphe::chargerDepuisOSM(const QString& fichierOSM) {
    QFile file(fichierOSM);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Impossible d'ouvrir le fichier.");
        return;
    }

    QXmlStreamReader xml(&file);

    noeud* currentNode = nullptr;
    QVector<long long> wayNodeIds;
    QString currentWayId;

    while (!xml.atEnd() && !xml.hasError()) {
        xml.readNext();

        if (xml.isStartElement()) {
            if (xml.name() == "node") {
                long long id = xml.attributes().value("id").toLongLong();
                double lat = xml.attributes().value("lat").toDouble();
                double lon = xml.attributes().value("lon").toDouble();
                currentNode = new noeud(id, lat, lon);
                ajouteNoeud(currentNode);
            } else if (xml.name() == "way") {
                wayNodeIds.clear();
                currentWayId = xml.attributes().value("id").toString();
            } else if (xml.name() == "nd") {
                long long ref = xml.attributes().value("ref").toLongLong();
                wayNodeIds.append(ref);
            } else if (xml.name() == "tag") {
                QString k = xml.attributes().value("k").toString();
                QString v = xml.attributes().value("v").toString();
                if (k == "highway") {
                    for (int i = 0; i < wayNodeIds.size() - 1; ++i) {
                        noeud* debut = listeNoeuds.value(wayNodeIds[i]);
                        noeud* fin = listeNoeuds.value(wayNodeIds[i + 1]);
                        if (debut && fin) {
                            arete* edge = new arete(debut, fin);
                            edge->setId(currentWayId);
                            edge->setType(v);
                            ajouteArete(edge);
                        }
                    }
                }
            }
        }
    }

    if (xml.hasError()) {
        qWarning() << "Erreur XML :" << xml.errorString();
    }

    file.close();

    qDebug() << "Nombre de nœuds chargés :" << listeNoeuds.size();
    qDebug() << "Nombre d'arêtes chargées :" << listeAretes.size();

}*/
void graphe::chargerDepuisOSM(const QString& fichierOSM) {
    QFile file(fichierOSM);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Impossible d'ouvrir le fichier.");
        return;
    }

    QXmlStreamReader xml(&file);

    QMap<long long, noeud*> noeudsTemp; // Pour associer les IDs aux nœuds

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (token == QXmlStreamReader::StartElement) {
            if (xml.name() == "node") {
                // Lecture d'un nœud
                long long id = xml.attributes().value("id").toLongLong();
                double lat = xml.attributes().value("lat").toDouble();
                double lon = xml.attributes().value("lon").toDouble();

                noeud* newNode = new noeud(id, lat, lon);
                listeNoeuds[id] = newNode;
                noeudsTemp[id] = newNode;

            } else if (xml.name() == "way") {
                QVector<long long> noeudsDeLArrete;
                QString type;

                // Lecture des nœuds et du type dans une arête
                while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "way")) {
                    xml.readNext();

                    if (xml.tokenType() == QXmlStreamReader::StartElement) {
                        if (xml.name() == "nd") {
                            long long ref = xml.attributes().value("ref").toLongLong();
                            noeudsDeLArrete.append(ref);
                        } else if (xml.name() == "tag") {
                            if (xml.attributes().value("k") == "highway") {
                                type = xml.attributes().value("v").toString();
                            }
                        }
                    }
                }

                // Création des arêtes et mise à jour des voisins
                for (int i = 0; i < noeudsDeLArrete.size() - 1; ++i) {
                    long long idDebut = noeudsDeLArrete[i];
                    long long idFin = noeudsDeLArrete[i + 1];

                    noeud* debut = noeudsTemp.value(idDebut, nullptr);
                    noeud* fin = noeudsTemp.value(idFin, nullptr);

                    if (debut && fin) {
                        // Ajouter les voisins
                        debut->ajouterVoisin(fin);
                        fin->ajouterVoisin(debut);

                        // Ajouter une arête
                        arete* newEdge = new arete(debut, fin);
                        newEdge->setType(type);
                        listeAretes.append(newEdge);
                    }
                }
            }
        }
    }

    if (xml.hasError()) {
        qWarning() << "Erreur lors de la lecture du fichier OSM :" << xml.errorString();
    }

    file.close();

    qDebug() << "Nombre de nœuds chargés :" << listeNoeuds.size();
    qDebug() << "Nombre d'arêtes chargées :" << listeAretes.size();
}

#include <QRandomGenerator>

void graphe::testerNoeudVoisins() const {
    if (listeNoeuds.isEmpty()) {
        qWarning() << "La liste des nœuds est vide.";
        return;
    }

    // Obtenir un nœud aléatoire
    QList<long long> ids = listeNoeuds.keys();
    int indexAleatoire = QRandomGenerator::global()->bounded(ids.size());
    long long idAleatoire = ids[indexAleatoire];
    noeud* noeudAleatoire = listeNoeuds.value(idAleatoire);

    if (noeudAleatoire) {
        qDebug() << "Nœud aléatoire ID :" << noeudAleatoire->getId()
            << "a" << noeudAleatoire->getNoeudsVoisins().size() << "voisins.";
    } else {
        qWarning() << "Impossible de trouver un nœud aléatoire valide.";
    }
}

