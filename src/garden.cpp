#include "fmt/core.h"
#include <garden.h>
#include <qevent.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qwidget.h>

Garden::Garden(QWidget *parent) : QWidget(parent) {
  plants = new Plant[maxPlants];
  plantCount = maxPlants;

  randomizePlants(gardenSize);
}

void Garden::randomizePlants(int gardenWidth) {
  std::srand(std::time(nullptr));
  for (int i = 0; i < plantCount; i++) {
    plants[i].setXOffset(1 + std::rand() / ((RAND_MAX + 1u) / gardenWidth));
  }
  updated = false;
}

void Garden::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);
  fmt::println("garden size:{},{}", event->size().width(),
               event->size().height());
  scale = gardenSize / event->size().width();
}

void drawLine(int x, int y, int x2, int y2, QPainter *painter) {
  painter->drawLine(x, y, x2, y2);
}

void Garden::paintEvent(QPaintEvent *event) {
  QWidget::paintEvent(event);
  QPainter painter(this);
  float frameWidth = this->frameSize().width();
  float frameHeight = this->frameSize().height();
  painter.translate(frameWidth, frameHeight);
  painter.rotate(180);
  painter.scale(frameWidth / (float) gardenSize, frameHeight/ (float)gardenSize);

  for (int i = 0; i < plantCount; i++) {
    drawPlant(plants[i], &painter);
  }
  updated = true;
  
}

void Garden::drawPlant(Plant plant, QPainter *painter) {
  drawStem(plant, painter);
  drawLeaves(plant, painter);
  drawFlowers(plant, painter);
}

void Garden::drawFlowers(Plant plant, QPainter *painter) {
  int windowheight = this->height();
  int flowerCount = plant.flowerCount();
  Flower *flowers = plant.getFlowers();
  QBrush brush = painter->brush();
  QPen pen = painter->pen();

  for (int i = 0; i < flowerCount; i++) {
    Flower target = flowers[i];
    
    painter->setPen(Qt::black);
    painter->setBrush(QBrush(*target.getColor()));
    painter->drawEllipse(target.getX() + plant.getXOffset() -
                             target.getWidth() / 2,
                         target.getY() - target.getHeight() / 2,
                         target.getWidth(), target.getHeight());
  }
}
void Garden::drawLeaves(Plant plant, QPainter *painter) {
  int windowheight = this->height();
  int leafCount = plant.leafCount();
  Leaf *leaves = plant.getLeaves();
  QBrush brush = painter->brush();
  QPen pen = painter->pen();

  for (int i = 0; i < leafCount; i++) {
    Leaf target = leaves[i];
    
    painter->setPen(Qt::black);
    painter->setBrush(QBrush(*target.getColor()));

    painter->drawEllipse(target.getX() + plant.getXOffset() -
                             target.getWidth() / 2,
                         target.getY() - target.getHeight() / 2,
                         target.getWidth(), target.getHeight());
  }
}
void Garden::drawStem(Plant plant, QPainter *painter) {

  float windowheight = this->frameSize().rheight();
  int stemCount = plant.stemCount();
  Stem *stems = plant.getStems();
  QBrush brush = painter->brush();
  
  float x1, x2, y1, y2;

  for (int i = 0; i < stemCount; i++) {
    Stem target = stems[i];
    x1 = target.getX1() + plant.getXOffset();
    x2 = target.getX2() + plant.getXOffset();
    //y1 = windowheight - target.getY1();
    //y2 = windowheight - target.getY2();
    y1 = target.getY1();
    y2 = target.getY2();

    fmt::println("{},{}:{},{}", x1, y1, x2, y2);
    fmt::println("target color:{},{},{}", target.getColor()->red(), target.getColor()->green(), target.getColor()->blue());
    
    painter->setPen(QPen(*target.getColor()));
    painter->drawLine(x1, y1, x2, y2);
  }

}
