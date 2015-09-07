#include "UpperBoundSet.hpp"

bool UpperBoundSet::empty() {
  return set.empty();
}

void UpperBoundSet::merge(std::vector<BVect> newSet) {
  if (empty())
    set.push_back(newSet);
}

unsigned UpperBoundSet::molpNumber() {
  return set.size();
}

unsigned UpperBoundSet::pointNumber() {
  unsigned number = 0;
  for (auto &molp : set) {
    number += molp.size();
  }
  return number;
}
