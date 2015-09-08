#include "MOLP.hpp"

MOLP::MOLP() {
}

MOLP::MOLP(std::vector<BVect> set) : set(set) {
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
