#ifndef MOLP_HPP
#define MOLP_HPP

#include <vector>
#include "BVect.hpp"

class MOLP {
 private:
  std::vector<BVect> set;
 public:
  bool empty();
  unsigned size();
  void push_back(const BVect&);
};

#endif
