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
  bool ACurrentlyNonDom = true;
  bool BCurrentlyNonDom = true;
  bool ADom = false;
  bool BDom = false;
  auto ADomBegin = molpA.end();
  auto ADomEnd   = molpA.end();
  auto BDomBegin = molpB.end();
  auto BDomEnd   = molpB.end();
  std::vector<MOLP> ADomParts;
  std::vector<MOLP> BDomParts;
  while (iterA != endA && iterB != endB) {
    BEdge leftA, rightA, leftB, rightB;
    DominanceStatus currentStatus = iterA->compareWith(*iterB, leftA, rightA, leftB, rightB);
    switch (currentStatus) {
      case DominanceStatus::A_DOM_B :
        if (!ACurrentlyNonDom) {
          ACurrentlyNonDom = true;
          ADomEnd = iterA;
        }
        if (BCurrentlyNonDom) {
          BCurrentlyNonDom = false;
          BDom = true;
          BDomBegin = iterB;
        }
        ++iterB;
        break;
      case DominanceStatus::A_PART_DOM_B :
        if (!ACurrentlyNonDom) {
          ACurrentlyNonDom = true;
          ADomEnd = iterA;
        }
        if (BCurrentlyNonDom) {
          BCurrentlyNonDom = false;
          BDom = true;
          BDomBegin = iterB;
        }
        if (!rightB.isEmpty()) {
          ++iterA;
          if(iterA == endA) {
            BCurrentlyNonDom = true;
            BDomEnd = iterB;
            BDomParts.push_back(MOLP(std::list<BEdge>(BDomBegin, BDomEnd)));
          }
        }
        break;
      case DominanceStatus::B_DOM_A :
        if (!BCurrentlyNonDom) {
          BCurrentlyNonDom = true;
          BDomEnd = iterB;
        }
        if (ACurrentlyNonDom) {
          ACurrentlyNonDom = false;
          ADom = true;
          ADomBegin = iterA;
        }
        ++iterA;
        break;
      case DominanceStatus::B_PART_DOM_A :
        if (!BCurrentlyNonDom) {
          BCurrentlyNonDom = true;
          BDomEnd = iterB;
        }
        if (ACurrentlyNonDom) {
          ACurrentlyNonDom = false;
          ADom = true;
          ADomBegin = iterA;
        }
        if (!rightA.isEmpty()) {
          ++iterB;
          if(iterB == endB) {
            ACurrentlyNonDom = true;
            ADomEnd = iterA;
            ADomParts.push_back(MOLP(std::list<BEdge>(ADomBegin, ADomEnd)));
          }
        }
        break;
      case DominanceStatus::MUTUAL_DOM :
        ADom = true;
        BDom = true;
        if (ACurrentlyNonDom) {
          if (!rightA.isEmpty()) {
            ACurrentlyNonDom = false;
            ADomBegin = iterA;
          }
        } else {
          ADomEnd = iterA;
          ADomParts.push_back(MOLP(std::list<BEdge>(ADomBegin, ADomEnd)));
          ACurrentlyNonDom = true;
        }
        if (BCurrentlyNonDom) {
          if (!rightB.isEmpty()) {
            BCurrentlyNonDom = false;
            BDomBegin = iterB;
          }
        } else {
          BDomEnd = iterB;
          BDomParts.push_back(MOLP(std::list<BEdge>(BDomBegin, BDomEnd)));
          BCurrentlyNonDom = true;
        }
        break;
      case DominanceStatus::NO_DOM :
        prepareIterators();
        break;
    }
  }
  if (ADom && BDom) {
    return DominanceStatus::MUTUAL_DOM;
  }
  else  if (ADom) {
    if (ADomParts.size() == 1
        && ADomParts.front().begin() == molpA.begin()
        && ADomParts.front().end() == molpA.end())
      return DominanceStatus::B_DOM_A;
    else return DominanceStatus::B_PART_DOM_A;
  }
  else if (BDom) {
    if (BDomParts.size() == 1
        && BDomParts.front().begin() == molpB.begin()
        && BDomParts.front().end() == molpB.end())
      return DominanceStatus::A_DOM_B;
    else return DominanceStatus::A_PART_DOM_B;
  }
  else return DominanceStatus::NO_DOM;
}
