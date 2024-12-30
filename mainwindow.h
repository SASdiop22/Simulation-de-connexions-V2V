#include <QMainWindow>
#include <QGraphicsView>
#include "graphe.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsView* vueGraphique;
    QGraphicsScene* scene;
    graphe monGraphe;

    void chargerGrapheEtAfficher();

};
