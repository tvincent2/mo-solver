#include <cppunit/extensions/HelperMacros.h>
#include "UpperBoundSet.hpp"

class UpperBoundSetTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(UpperBoundSetTest);
  CPPUNIT_TEST(testEmptyness);
  CPPUNIT_TEST(testSize);
  CPPUNIT_TEST_SUITE_END();
 private:
  UpperBoundSet* emptyUbs;
  UpperBoundSet* simpleUbs;
 public:
  void setUp() {
    emptyUbs = new UpperBoundSet();

    simpleUbs = new UpperBoundSet();
    MOLP points;
    std::vector<double> xVect;
    BVect bv1(1, 2, xVect);
    BVect bv2(2, 1, xVect);
    points.push_back(bv1);
    points.push_back(bv2);
    simpleUbs->merge(points);
  }
  void tearDown() {
    delete emptyUbs;
    delete simpleUbs;
  }
  void testEmptyness() {
    CPPUNIT_ASSERT(emptyUbs->empty());
    CPPUNIT_ASSERT(!(simpleUbs->empty()));
  }
  void testSize() {
    CPPUNIT_ASSERT(simpleUbs->molpNumber() == 1);
    CPPUNIT_ASSERT(simpleUbs->pointNumber() == 2);
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(UpperBoundSetTest);
