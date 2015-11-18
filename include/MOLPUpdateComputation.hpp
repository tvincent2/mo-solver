#ifndef MOLP_UPDATE_COMPUTATION_HPP
#define MOLP_UPDATE_COMPUTATION_HPP

#include "MOLP.hpp"
#include "DominanceStatus.hpp"

class MOLPUpdateComputation {
 private:
  MOLP molpA;
  MOLP molpB;
  std::list<BEdge>::iterator iterA;
  std::list<BEdge>::iterator iterB;
  std::list<BEdge>::iterator endA;
  std::list<BEdge>::iterator endB;
 public:
  MOLPUpdateComputation(MOLP, MOLP);
  DominanceStatus computeUpdate();
  bool noDominance();
  void prepareIterators();
};

#endif
