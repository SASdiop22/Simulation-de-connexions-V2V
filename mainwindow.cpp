#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    vueGraphique(new QGraphicsView(this)),
    scene(new QGraphicsScene(this))
{
    // Configurer la vue graphique
    vueGraphique->setScene(scene);
    vueGraphique->setRenderHint(QPainter::Antialiasing);

    // Ajouter la vue graphique à la fenêtre principale
    setCentralWidget(vueGraphique);

    // Charger le graphe depuis un fichier OSM et l'afficher
    chargerGrapheEtAfficher();
}

MainWindow::~MainWindow() {}

void MainWindow::chargerGrapheEtAfficher() {
    // Charger le graphe (remplacez par le chemin de votre fichier OSM)
    QString cheminFichierOSM = "C:/Users/fatou/Documents/sans_titre/data/map.osm";
    monGraphe.chargerDepuisOSM(cheminFichierOSM);

    // Afficher le graphe dans la scène
    monGraphe.afficherGraphe(scene);
    // Test d'un nœud voisin aléatoirement
    monGraphe.testerNoeudVoisins();
}
