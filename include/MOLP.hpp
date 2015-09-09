#ifndef MOLP_HPP
#define MOLP_HPP

#include <vector>
#include "BVect.hpp"

class MOLP {
 private:
  std::vector<BVect> set;
 public:
  MOLP();
  MOLP(std::vector<BVect>);
  bool empty();
  unsigned size();
  void push_back(const BVect&);
  BVect leftmost();
  BVect rightmost();
};

#endif
