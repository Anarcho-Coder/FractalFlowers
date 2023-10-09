#ifndef PLANT
#define PLANT

#include "stem.h"
#include "flower.h"
#include "leaf.h"

#include <limits>

class Plant{
protected:
  // Null terminated arrays 
  Stem* stems;
  Leaf* leaves;
  Flower* flowers;
  int flowerCounter = 0;
  int stemCounter = 0;
  int leafCounter = 0;
  int growthStep = 0;
  int maxGrowth = INT_MAX;
  int plantXOffset = 0;
  
public:
  explicit Plant();
  explicit Plant(int plantXOffset);
  Stem* getStems();
  Flower* getFlowers();
  Leaf* getLeaves();
  int stemCount();
  int flowerCount();
  int leafCount();
  void setXOffset(int xOffset);
  int getXOffset();
};

#endif
