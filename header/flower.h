#ifndef FLOWER
#define FLOWER

#include <QColor>
static QColor *DEFAULT_FLOWER_COLOR = new QColor(255, 51, 51);

class Flower {
private:
  float x;
  float y;
  float width = 10;
  float height = 10;
  QColor *color;

public:
  Flower(float x, float y, QColor *color);
  QColor *getColor();
  float getX();
  float getY();
  float getWidth();
  float getHeight();
  void setX(float x);
  void setY(float y);
};
#endif
