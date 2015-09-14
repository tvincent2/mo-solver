#include <cppunit/extensions/HelperMacros.h>
#include "UpperBoundSet.hpp"

class UpperBoundSetTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(UpperBoundSetTest);
  CPPUNIT_TEST(testEmptyness);
  CPPUNIT_TEST(testSize);
  CPPUNIT_TEST(testDominancePredicate);
  CPPUNIT_TEST_SUITE_END();
 private:
  UpperBoundSet* emptyUbs;
  UpperBoundSet* simpleUbs;
  UpperBoundSet* bigUbs;
 public:
  void setUp() {
    emptyUbs = new UpperBoundSet();

    simpleUbs = new UpperBoundSet();
    MOLP simpleMOLP;
    std::vector<double> xVect;
    BVect bv1(1, 2, xVect);
    BVect bv2(2, 1, xVect);
    BEdge be(bv1, bv2);
    simpleMOLP.push_back(be);
    simpleUbs->merge(simpleMOLP);

    bigUbs = new UpperBoundSet();
    MOLP m1;
    BVect bv1m1(2, 17, xVect);
    BVect bv2m1(3, 15, xVect);
    BVect bv3m1(5, 14, xVect);
    BEdge be1m1(bv1m1, bv2m1);
    BEdge be2m1(bv2m1, bv3m1);
    m1.push_back(be1m1);
    m1.push_back(be2m1);
    MOLP m2;
    BVect bv1m2(8, 11, xVect);
    BVect bv2m2(9, 9, xVect);
    BVect bv3m2(11, 8, xVect);
    BEdge be1m2(bv1m2, bv2m2);
    BEdge be2m2(bv2m2, bv3m2);
    m2.push_back(be1m2);
    m2.push_back(be2m2);
    MOLP m3;
    BVect bv1m3(14, 5, xVect);
    BVect bv2m3(15, 3, xVect);
    BVect bv3m3(17, 2, xVect);
    BEdge be1m3(bv1m3, bv2m3);
    BEdge be2m3(bv2m3, bv3m3);
    m3.push_back(be1m3);
    m3.push_back(be2m3);
    bigUbs->merge(m1);
    bigUbs->merge(m2);
    bigUbs->merge(m3);
  }
  void tearDown() {
    delete emptyUbs;
    delete simpleUbs;
    delete bigUbs;
  }
  void testEmptyness() {
    CPPUNIT_ASSERT(emptyUbs->empty());
    CPPUNIT_ASSERT(!(simpleUbs->empty()));
    CPPUNIT_ASSERT(!(bigUbs->empty()));
  }
  void testSize() {
    CPPUNIT_ASSERT(simpleUbs->molpNumber() == 1);
    CPPUNIT_ASSERT(simpleUbs->edgeNumber() == 1);
    CPPUNIT_ASSERT(bigUbs->molpNumber() == 3);
    CPPUNIT_ASSERT(bigUbs->edgeNumber() == 6);
  }
  void testDominancePredicate() {
    std::vector<double> xVect;
    MOLP testFalse1;
    BVect bv1tf1(0, 19, xVect);
    BVect bv2tf1(1, 18, xVect);
    BEdge betf1(bv1tf1, bv2tf1);
    testFalse1.push_back(betf1);
    MOLP testFalse2;
    BVect bv1tf2(6, 13, xVect);
    BVect bv2tf2(7, 12, xVect);
    BEdge betf2(bv1tf2, bv2tf2);
    testFalse2.push_back(betf2);
    MOLP testFalse3;
    BVect bv1tf3(12, 7, xVect);
    BVect bv2tf3(13, 6, xVect);
    BEdge betf3(bv1tf3, bv2tf3);
    testFalse3.push_back(betf3);
    MOLP testFalse4;
    BVect bv1tf4(18, 1, xVect);
    BVect bv2tf4(19, 0, xVect);
    BEdge betf4(bv1tf4, bv2tf4);
    testFalse4.push_back(betf4);
    CPPUNIT_ASSERT(!bigUbs->hasDominanceRelationshipWith(testFalse1));
    CPPUNIT_ASSERT(!bigUbs->hasDominanceRelationshipWith(testFalse2));
    CPPUNIT_ASSERT(!bigUbs->hasDominanceRelationshipWith(testFalse3));
    CPPUNIT_ASSERT(!bigUbs->hasDominanceRelationshipWith(testFalse4));
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(UpperBoundSetTest);
