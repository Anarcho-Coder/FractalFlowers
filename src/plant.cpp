#include "plant.h"
// todo hardcode a test plant to draw
Plant::Plant() {
  stems = new Stem(0, 0, 0, 15, nullptr);
  stemCounter++;
  leaves = new Leaf(-2, 10, nullptr);
  leafCounter++;
  flowers = new Flower(0, 15, nullptr);
  flowerCounter++;
}

Plant::Plant(int plantXOffset) {
  Plant();
  this->plantXOffset = plantXOffset;
}

void Plant::setXOffset(int xOffset) { this->plantXOffset = xOffset; }

int Plant::getXOffset() { return this->plantXOffset; }

Stem *Plant::getStems() { return stems; }
Flower *Plant::getFlowers() { return flowers; }
Leaf *Plant::getLeaves() { return leaves; }

int Plant::flowerCount() { return flowerCounter; }
int Plant::leafCount() { return leafCounter; }
int Plant::stemCount() { return stemCounter; }
