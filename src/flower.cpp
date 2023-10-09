#include "flower.h"

Flower::Flower(float x, float y, QColor* color){
  if(color == nullptr){
    this->color = DEFAULT_FLOWER_COLOR;
  }
  else {
    this->color = color;
  }

  this->x = x;
  this->y = y;
}

QColor* Flower::getColor(){
  return color;
}

float Flower::getX(){
  return x;
}
float Flower::getY(){
  return y;
}

float Flower::getWidth(){
  return width;
}

float Flower::getHeight(){
  return height;
}

void Flower::setX(float x){
  this->x = x;
}
void Flower::setY(float y){
  this->y = y;
}
