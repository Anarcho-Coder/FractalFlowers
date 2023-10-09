#include "stem.h"
#include <qnamespace.h>

Stem::Stem(float x1, float y1, float x2, float y2, QColor *color)
{
  if(color == nullptr){
    this->color = DEFAULT_STEM_COLOR;
  } else {
    this->color = color;
  }
  this->x1 = x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
}

float Stem::getX1(){
  return x1;
}

float Stem::getY1(){
  return y1;
}

float Stem::getX2(){
  return x2;
}

float Stem::getY2(){
  return y2;
}

QColor* Stem::getColor(){
  return color;
}
