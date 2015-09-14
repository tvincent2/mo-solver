#ifndef UPPER_BOUND_SET_HPP
#define UPPER_BOUND_SET_HPP

#include "MOLP.hpp"

class UpperBoundSet {
 private:
  std::list<MOLP> set;
 public:
  bool empty() const;
  void merge(MOLP);
  unsigned molpNumber() const;
  unsigned edgeNumber() const;
  bool hasDominanceRelationshipWith(const MOLP) const;
};

#endif  // UPPER_BOUND_SET_HPP
