#include "MOLP.hpp"

bool MOLP::empty() {
  return set.empty();
}

unsigned MOLP::size() {
  return set.size();
}

void MOLP::push_back(const BVect& point) {
  set.push_back(point);
}
