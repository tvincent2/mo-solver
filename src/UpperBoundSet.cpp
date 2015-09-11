#include "UpperBoundSet.hpp"

bool UpperBoundSet::empty() {
  return set.empty();
}

void UpperBoundSet::merge(MOLP newMOLP) {
  if (empty()) {
    set.push_back(newMOLP);
  } else {
    
  }
}

unsigned UpperBoundSet::molpNumber() {
  return set.size();
}

unsigned UpperBoundSet::edgeNumber() {
  unsigned number = 0;
  for (auto &molp : set) {
    number += molp.size();
  }
  return number;
}
