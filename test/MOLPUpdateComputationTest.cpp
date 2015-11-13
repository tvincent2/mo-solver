#include <cppunit/extensions/HelperMacros.h>
#include "MOLPUpdateComputation.hpp"

class MOLPUpdateComputationTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MOLPUpdateComputationTest);
  CPPUNIT_TEST_SUITE_END();
 private:
  MOLP* molpA;
  MOLP* molpB;
  MOLPUpdateComputation* muc;
 public:
  void setUp() {
    std::vector<double> xVect;
    
    molpA = new MOLP();
    BVect bv1A(0, 10, xVect);
    BVect bv2A(1, 8, xVect);
    BVect bv3A(2, 7, xVect);
    BEdge be1A(bv1A, bv2A);
    BEdge be2A(bv2A, bv3A);
    molpA->push_back(be1A);
    molpA->push_back(be2A);
    
    molpB = new MOLP();
    BVect bv1B(3, 6, xVect);
    BVect bv2B(4, 4, xVect);
    BVect bv3B(5, 3, xVect);
    BEdge be1B(bv1B, bv2B);
    BEdge be2B(bv2B, bv3B);
    molpB->push_back(be1B);
    molpB->push_back(be2B);

    muc = new MOLPUpdateComputation(*molpA, *molpB);
  }
  void tearDown() {
    delete molpA;
    delete molpB;
    delete muc;
  }
  void testNoDominance() {
    CPPUNIT_ASSERT(muc->noDominance());
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(MOLPUpdateComputationTest);
