#include "MOLPUpdateComputation.hpp"

MOLPUpdateComputation::MOLPUpdateComputation(MOLP a, MOLP b) : molpA(a), molpB(b) {
}

bool noDominance() {
  return (molpA.empty() ||
          molpB.empty() ||
          molpA.isInA1AreaOf(molpB) ||
          molpB.isInA1AreaOf(molpA));
}

void MOLPUpdateComputation::initIterators() {
  endA = molpA.edges().end();
  endB = molpB.edges().end();
  iterA = molpA.edges().begin();
  iterB = molpB.edges().begin();
  while (iterA->isInA1AreaOf(*iterB) && iterA != endA)
    ++iterA;
  while (iterB->isInA1AreaOf(*iterA) && iterB != endB)
    ++iterB;
}

DominanceStatus MOLPUpdateComputation::computeUpdate() {
  if (noDominance())
    return DominanceStatus::NO_DOM;
  initIterators();
}
