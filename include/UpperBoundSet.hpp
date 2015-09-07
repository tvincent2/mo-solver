#ifndef UPPER_BOUND_SET_HPP
#define UPPER_BOUND_SET_HPP

#include <vector>
#include "BVect.hpp"

class UpperBoundSet {
 private:
  std::vector<std::vector<BVect> > set;
 public:
  bool empty();
  void merge(std::vector<BVect>);
  unsigned molpNumber();
  unsigned pointNumber();
};

#endif  // UPPER_BOUND_SET_HPP
