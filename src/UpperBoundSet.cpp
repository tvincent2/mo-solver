#include "UpperBoundSet.hpp"

bool UpperBoundSet::empty() const {
  return set.empty();
}

void UpperBoundSet::merge(MOLP newMOLP) {
  if (empty()) {
    set.push_back(newMOLP);
  } else {
    
  }
}

unsigned UpperBoundSet::molpNumber() const {
  return set.size();
}

unsigned UpperBoundSet::edgeNumber() const {
  unsigned number = 0;
  for (auto &molp : set) {
    number += molp.size();
  }
  return number;
}
