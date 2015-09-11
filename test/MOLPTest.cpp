#include <cppunit/extensions/HelperMacros.h>
#include "MOLP.hpp"

class MOLPTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MOLPTest);
  CPPUNIT_TEST(testEmptyness);
  CPPUNIT_TEST(testSize);
  CPPUNIT_TEST(testConstructors);
  CPPUNIT_TEST(testAccessors);
  CPPUNIT_TEST_SUITE_END();
 private:
  MOLP* emptyMOLP;
  MOLP* simpleMOLP;
  MOLP* constructMOLP;
 public:
  void setUp() {
    emptyMOLP = new MOLP();

    simpleMOLP = new MOLP();
    std::vector<double> xVect;
    BVect bv1(1, 2, xVect);
    BVect bv2(2, 1, xVect);
    BEdge be(bv1, bv2);
    simpleMOLP->push_back(be);
    std::list<BEdge> bevect;
    bevect.push_back(be);
    constructMOLP = new MOLP(bevect);
  }
  void tearDown() {
    delete emptyMOLP;
    delete simpleMOLP;
    delete constructMOLP;
  }
  void testEmptyness() {
    CPPUNIT_ASSERT(emptyMOLP->empty());
    CPPUNIT_ASSERT(!(simpleMOLP->empty()));
  }
  void testSize() {
    CPPUNIT_ASSERT(simpleMOLP->size() == 1);
  }
  void testConstructors() {
    CPPUNIT_ASSERT(!(constructMOLP->empty()));
    CPPUNIT_ASSERT(constructMOLP->size() == 1);
  }
  void testAccessors() {
    BVect left = simpleMOLP->leftmostPoint();
    BVect right = simpleMOLP->rightmostPoint();
    CPPUNIT_ASSERT(left.y1() == 1 && left.y2() == 2);
    CPPUNIT_ASSERT(right.y1() == 2 && right.y2() == 1);
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(MOLPTest);
