#include <leaf.h>

Leaf::Leaf(float x, float y, QColor* color){
  if(color == nullptr){
    this->color = DEFAULT_LEAF_COLOR;
  }
  else {
    this->color = color;
  }

  this->x = x;
  this->y = y;
}

QColor* Leaf::getColor(){
  return color;
}

float Leaf::getX(){
  return x;
}
float Leaf::getY(){
  return y;
}

float Leaf::getWidth(){
  return width;
}

float Leaf::getHeight(){
  return height;
}

void Leaf::setX(float x){
  this->x = x;
}
void Leaf::setY(float y){
  this->y = y;
}
