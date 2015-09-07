#ifndef UPPER_BOUND_SET_HPP
#define UPPER_BOUND_SET_HPP

#include "MOLP.hpp"

class UpperBoundSet {
 private:
  std::vector<MOLP> set;
 public:
  bool empty();
  void merge(MOLP);
  unsigned molpNumber();
  unsigned pointNumber();
};

#endif  // UPPER_BOUND_SET_HPP
