#include <cppunit/extensions/HelperMacros.h>
#include "MOLPUpdateComputation.hpp"

class MOLPUpdateComputationTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MOLPUpdateComputationTest);
  CPPUNIT_TEST(testNoDominance);
  CPPUNIT_TEST(testPrepareIterators);
  CPPUNIT_TEST_SUITE_END();
 private:
  MOLP* molpA;
  MOLP* molpB;
  MOLP* molpC;
  MOLPUpdateComputation* mucAB;
  MOLPUpdateComputation* mucAC;
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

    molpC = new MOLP();
    BVect bv1C(3, 8.5, xVect);
    BVect bv2C(4, 6.5, xVect);
    BVect bv3C(5, 5.5, xVect);
    BEdge be1C(bv1C, bv2C);
    BEdge be2C(bv2C, bv3C);
    molpC->push_back(be1C);
    molpC->push_back(be2C);

    mucAB = new MOLPUpdateComputation(*molpA, *molpB);
    mucAC = new MOLPUpdateComputation(*molpA, *molpC);
  }
  void tearDown() {
    delete molpA;
    delete molpB;
    delete mucAB;
    delete mucAC;
  }
  void testNoDominance() {
    CPPUNIT_ASSERT(mucAB->noDominance());
    CPPUNIT_ASSERT(!mucAC->noDominance());
  }
  void testPrepareIterators() {
    mucAB->prepareIterators();
    CPPUNIT_ASSERT(mucAB->getIterA() == mucAB->getEndA());
    CPPUNIT_ASSERT(mucAB->getIterB() == mucAB->getBeginB());
    mucAC->prepareIterators();
    CPPUNIT_ASSERT(mucAC->getIterA() == mucAC->getBeginA());
    CPPUNIT_ASSERT(mucAC->getIterB() == mucAC->getBeginB());
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(MOLPUpdateComputationTest);
