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
  bool empty() const;
  unsigned size() const;
  void push_back(const BEdge&);
  void extendWithPoint(const BVect&);
  BVect leftmostPoint() const;
  BVect rightmostPoint() const;
  bool isInA1AreaOf(const MOLP&) const;
  bool isInA2AreaOf(const MOLP&) const;
};

#endif
