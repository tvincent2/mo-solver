#include "MOLP.hpp"

MOLP::MOLP() {
}

MOLP::MOLP(std::list<BEdge> set) : set(set) {
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
