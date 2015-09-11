#include "MOLP.hpp"

MOLP::MOLP() {
}

MOLP::MOLP(std::list<BEdge> set) : set(set) {
}

bool MOLP::empty() {
  return set.empty();
}

unsigned MOLP::size() {
  return set.size();
}

void MOLP::push_back(const BEdge& edge) {
  set.push_back(edge);
}

void MOLP::extendWithPoint(const BVect& point) {
  BEdge e(this->rightmostPoint(), point);
  this->push_back(e);
}

BVect MOLP::leftmostPoint() {
  return set.front().leftPoint();
}

BVect MOLP::rightmostPoint() {
  return set.back().rightPoint();
}
