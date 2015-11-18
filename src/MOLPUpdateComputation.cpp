#include "MOLPUpdateComputation.hpp"

MOLPUpdateComputation::MOLPUpdateComputation(MOLP a, MOLP b) : molpA(a), molpB(b), endA(molpA.end()), endB(molpB.end()), iterA(molpA.begin()), iterB(molpB.begin()) {
}

bool MOLPUpdateComputation::noDominance() {
  return (molpA.empty() ||
          molpB.empty() ||
          molpA.isInA1AreaOf(molpB) ||
          molpB.isInA1AreaOf(molpA));
}

void MOLPUpdateComputation::prepareIterators() {
  while (iterA->isInA1AreaOf(*iterB) && iterA != endA)
    ++iterA;
  while (iterB->isInA1AreaOf(*iterA) && iterB != endB)
    ++iterB;
}

DominanceStatus MOLPUpdateComputation::computeUpdate() {
  if (noDominance())
    return DominanceStatus::NO_DOM;
  prepareIterators();
}
