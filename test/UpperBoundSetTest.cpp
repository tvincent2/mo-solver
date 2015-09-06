#include <cppunit/extensions/HelperMacros.h>
#include "UpperBoundSet.hpp"

class UpperBoundSetTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(UpperBoundSetTest);
  CPPUNIT_TEST(testEmptyness);
  CPPUNIT_TEST_SUITE_END();
 private:
  UpperBoundSet* emptyUbs;
  UpperBoundSet* simpleUbs;
 public:
  void setUp() {
    emptyUbs = new UpperBoundSet();

    simpleUbs = new UpperBoundSet();
    std::vector<BVect> points;
    std::vector<double> xVect;
    BVect bv(0, 0, xVect);
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
};

CPPUNIT_TEST_SUITE_REGISTRATION(UpperBoundSetTest);
