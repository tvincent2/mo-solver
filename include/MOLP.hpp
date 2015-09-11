#ifndef MOLP_HPP
#define MOLP_HPP

#include <list>
#include "BVect.hpp"
#include "BEdge.hpp"

class MOLP {
 private:
  std::list<BEdge> set;
 public:
  MOLP();
  MOLP(std::list<BEdge>);
  bool empty();
  unsigned size();
  void push_back(const BEdge&);
  void extendWithPoint(const BVect&);
  BVect leftmostPoint();
  BVect rightmostPoint();
};

#endif
