#include "UpperBoundSet.hpp"

bool UpperBoundSet::empty() {
  return set.empty();
}

void UpperBoundSet::merge(std::vector<BVect> newSet) {
  if (empty())
    set.push_back(newSet);
}
