#ifndef LEAF
#define LEAF

#include <QColor>

static QColor *DEFAULT_LEAF_COLOR = new QColor(0, 128, 85);

class Leaf {
private:
  float x;
  float y;
  float width = 10;
  float height = 4;
  QColor *color;

public:
  Leaf(float x, float y, QColor *color);
  QColor *getColor();
  float getX();
  float getY();
  float getWidth();
  float getHeight();
  void setX(float x);
  void setY(float y);
};
#endif
