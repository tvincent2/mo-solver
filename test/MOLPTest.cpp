#include <cppunit/extensions/HelperMacros.h>
#include "MOLP.hpp"

class MOLPTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MOLPTest);
  CPPUNIT_TEST(testEmptyness);
  CPPUNIT_TEST(testSize);
  CPPUNIT_TEST_SUITE_END();
 private:
  MOLP* emptyMOLP;
  MOLP* simpleMOLP;
 public:
  void setUp() {
    emptyMOLP = new MOLP();

    simpleMOLP = new MOLP();
    std::vector<double> xVect;
    BVect bv1(1, 2, xVect);
    BVect bv2(2, 1, xVect);
    simpleMOLP->push_back(bv1);
    simpleMOLP->push_back(bv2);
  }
  void tearDown() {
    delete emptyMOLP;
    delete simpleMOLP;
  }
  void testEmptyness() {
    CPPUNIT_ASSERT(emptyMOLP->empty());
    CPPUNIT_ASSERT(!(simpleMOLP->empty()));
  }
  void testSize() {
    CPPUNIT_ASSERT(simpleMOLP->size() == 2);
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(MOLPTest);
