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
  while (iterA != endA && iterB != endB && iterA->isInA1AreaOf(*iterB))
    ++iterA;
  while (iterA != endA && iterB != endB && iterB->isInA1AreaOf(*iterA))
    ++iterB;
}

std::list<BEdge>::iterator MOLPUpdateComputation::getIterA() {
  return iterA;
}

std::list<BEdge>::iterator MOLPUpdateComputation::getIterB() {
  return iterB;
}

std::list<BEdge>::iterator MOLPUpdateComputation::getBeginA() {
  return molpA.begin();
}

std::list<BEdge>::iterator MOLPUpdateComputation::getBeginB() {
  return molpB.begin();
}

std::list<BEdge>::iterator MOLPUpdateComputation::getEndA() {
  return endA;
}

std::list<BEdge>::iterator MOLPUpdateComputation::getEndB() {
  return endB;
}

DominanceStatus MOLPUpdateComputation::computeUpdate() {
  if (noDominance())
    return DominanceStatus::NO_DOM;
  prepareIterators();
}
