#include <cppunit/extensions/HelperMacros.h>
#include "MOLP.hpp"

class MOLPTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(MOLPTest);
  CPPUNIT_TEST(testEmptyness);
  CPPUNIT_TEST(testSize);
  CPPUNIT_TEST(testConstructors);
  CPPUNIT_TEST(testAccessors);
  CPPUNIT_TEST(testAreaPredicates);
  CPPUNIT_TEST_SUITE_END();
 private:
  MOLP* emptyMOLP;
  MOLP* simpleMOLP;
  MOLP* constructMOLP;
  MOLP* leftMOLP;
  MOLP* rightMOLP;
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
    BVect bv3(3, 0, xVect);
    constructMOLP->extendWithPoint(bv3);

    leftMOLP = new MOLP();
    rightMOLP = new MOLP();
    leftMOLP->push_back(be);
    BVect bv4(4, -1, xVect);
    BEdge be2(bv3, bv4);
    rightMOLP->push_back(be2);
  }
  void tearDown() {
    delete emptyMOLP;
    delete simpleMOLP;
    delete constructMOLP;
    delete leftMOLP;
    delete rightMOLP;
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
    CPPUNIT_ASSERT(constructMOLP->size() == 2);
  }
  void testEdgeGetters() {
    std::list<BEdge> edges = constructMOLP->edges();
    CPPUNIT_ASSERT(edges.size() == 2);
    CPPUNIT_ASSERT(edges.front().leftPoint().z1() == 1 && edges.front().leftPoint().z2() == 2);
    CPPUNIT_ASSERT(edges.front().rightPoint().z1() == 2 && edges.front().rightPoint().z2() == 1);
    CPPUNIT_ASSERT(edges.back().leftPoint().z1() == 2 && edges.back().leftPoint().z2() == 1);
    CPPUNIT_ASSERT(edges.back().rightPoint().z1() == 3 && edges.back().rightPoint().z2() == 0);
  }
  void testAccessors() {
    BVect left = simpleMOLP->leftmostPoint();
    BVect right = simpleMOLP->rightmostPoint();
    CPPUNIT_ASSERT(left.z1() == 1 && left.z2() == 2);
    CPPUNIT_ASSERT(right.z1() == 2 && right.z2() == 1);
    BVect constructRight = constructMOLP->rightmostPoint();
    CPPUNIT_ASSERT(constructRight.z1() == 3 && constructRight.z2() == 0);
  }
  void testAreaPredicates() {
    CPPUNIT_ASSERT(leftMOLP->isInA1AreaOf(*rightMOLP));
    CPPUNIT_ASSERT(rightMOLP->isInA2AreaOf(*leftMOLP));
    CPPUNIT_ASSERT(!(leftMOLP->isInA2AreaOf(*rightMOLP)));
    CPPUNIT_ASSERT(!(rightMOLP->isInA1AreaOf(*leftMOLP)));
    CPPUNIT_ASSERT(!leftMOLP->isInA1AreaOf(*constructMOLP));
    CPPUNIT_ASSERT(!leftMOLP->isInA2AreaOf(*constructMOLP));
    CPPUNIT_ASSERT(!rightMOLP->isInA1AreaOf(*constructMOLP));
    CPPUNIT_ASSERT(!rightMOLP->isInA2AreaOf(*constructMOLP));
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(MOLPTest);
