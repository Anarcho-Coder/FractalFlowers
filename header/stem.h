#ifndef STEM
#define STEM

#include <QColor>

static QColor *DEFAULT_STEM_COLOR = new QColor(85, 128, 0);

class Stem {
private:
  float x1, x2, y1, y2;
  QColor *color;

public:
  Stem(float x1, float y1, float x2, float y2, QColor *color);

  QColor *getColor();
  float getX1();
  float getX2();
  float getY1();
  float getY2();
};

#endif
