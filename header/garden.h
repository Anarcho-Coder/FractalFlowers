#ifndef GARDEN
#define GARDEN

#include "plant.h"
#include <QResizeEvent>
#include <QWidget>

void drawStem(Stem stem, QPaintEvent painter);

class Garden : public QWidget {
  Q_OBJECT
private:
  Plant *plants;
  int plantCount = 0;
  int maxPlants = 10;
  int gardenSize = 200;
  int scale = 1;
  bool updated = false;

  void drawPlant(Plant plant, QPainter *painter);
  void drawStem(Plant plant, QPainter *painter);
  void drawFlowers(Plant plant, QPainter *painter);
  void drawLeaves(Plant plant, QPainter *painter);
  void addPlant(Plant plant);
  void randomizePlants(int gardenWidth);

public:
  explicit Garden(QWidget *parent = nullptr);

protected:
  void resizeEvent(QResizeEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
};

#endif
