#include "MOLP.hpp"

MOLP::MOLP() {
}

MOLP::MOLP(std::list<BEdge> set) : set(set) {
}

std::list<BEdge> MOLP::edges() const {
  return set;
}

std::list<BEdge>::iterator MOLP::begin() {
  return set.begin();
}

std::list<BEdge>::iterator MOLP::end() {
  return set.end();
}

bool MOLP::empty() const {
  return set.empty();
}

unsigned MOLP::size() const {
  return set.size();
}

void MOLP::push_back(const BEdge& edge) {
  set.push_back(edge);
}

void MOLP::extendWithPoint(const BVect& point) {
  BEdge e(this->rightmostPoint(), point);
  this->push_back(e);
}

BVect MOLP::leftmostPoint() const {
  return set.front().leftPoint();
}

BVect MOLP::rightmostPoint() const {
  return set.back().rightPoint();
}

bool MOLP::isInA1AreaOf (const MOLP& m) const {
  return (this->rightmostPoint().isInA1AreaOf(m.leftmostPoint()));
}

bool MOLP::isInA2AreaOf (const MOLP& m) const {
  return m.isInA1AreaOf(*this);
}

DominanceStatus MOLP::computeUpdate(const MOLP& compMOLP, std::list<MOLP>& toAdd) const {
  if (this->isInA1AreaOf(compMOLP) || this->isInA2AreaOf(compMOLP))
    return DominanceStatus::NO_DOM;
  bool AdomB = false, BdomA = false;
  auto compEdge = compMOLP.edges().begin();
  for (auto thisEdge: this->edges()) {
    if (compEdge == compMOLP.edges().end()) {
      break;
    }
    if (!thisEdge.isInA1AreaOf(*compEdge)) {
      while (compEdge->isInA1AreaOf(thisEdge) && compEdge != compMOLP.edges().end())
        ++compEdge;
    }
  }

  if (AdomB && BdomA)
    return DominanceStatus::MUTUAL_DOM;
  else if (!AdomB && BdomA)
    return DominanceStatus::B_DOM_A;
  else if (AdomB && !BdomA)
    return DominanceStatus::A_DOM_B;
  else
    return DominanceStatus::NO_DOM;
}
