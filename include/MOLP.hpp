#ifndef MOLP_HPP
#define MOLP_HPP

#include <list>
#include "BVect.hpp"

class MOLP {
 private:
  std::list<BVect> set;
 public:
  MOLP();
  MOLP(std::list<BVect>);
  bool empty();
  unsigned size();
  void push_back(const BVect&);
  BVect leftmost();
  BVect rightmost();
};

#endif
