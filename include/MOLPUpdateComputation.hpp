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
  const std::list<BEdge>::iterator endA;
  const std::list<BEdge>::iterator endB;
 public:
  MOLPUpdateComputation(MOLP, MOLP);
  DominanceStatus computeUpdate();
  bool noDominance();
  void prepareIterators();
  std::list<BEdge>::iterator getIterA();
  std::list<BEdge>::iterator getIterB();
  std::list<BEdge>::iterator getBeginA();
  std::list<BEdge>::iterator getBeginB();
  std::list<BEdge>::iterator getEndA();
  std::list<BEdge>::iterator getEndB();
};

#endif
