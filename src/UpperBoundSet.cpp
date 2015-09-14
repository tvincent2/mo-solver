#include "UpperBoundSet.hpp"

bool UpperBoundSet::empty() const {
  return set.empty();
}

// FIXME Still a work in progress
void UpperBoundSet::merge(MOLP newMOLP) {
  if (empty()) {
    set.push_back(newMOLP);
  } else {
    bool addAtEnd = true;
    for (auto ubsMOLPit = set.begin(); ubsMOLPit != set.end(); ++ubsMOLPit) {
      if (newMOLP.isInA1AreaOf(*ubsMOLPit)) {
        set.insert(ubsMOLPit, newMOLP);
        break;
      } else if (!newMOLP.isInA2AreaOf(*ubsMOLPit)) {
        // dominance occurs, do nothing for the moment
        addAtEnd = false;
        break;
      }
    }
    if (addAtEnd) {
      set.push_back(newMOLP);
    }
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

bool UpperBoundSet::hasDominanceRelationshipWith(const MOLP compMOLP) const {
  for (auto &ubsMOLP: set) {
    if (compMOLP.isInA1AreaOf(ubsMOLP)) {
      return false;
    } else if (!compMOLP.isInA2AreaOf(ubsMOLP)) {
      return true;
    }
  }
  return false;
}
