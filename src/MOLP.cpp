#include "MOLP.hpp"

MOLP::MOLP() {
}

MOLP::MOLP(std::list<BVect> set) : set(set) {
}

bool MOLP::empty() {
  return set.empty();
}

unsigned MOLP::size() {
  return set.size();
}

void MOLP::push_back(const BVect& point) {
  set.push_back(point);
}

BVect MOLP::leftmost() {
  return set.front();
}

BVect MOLP::rightmost() {
  return set.back();
}
