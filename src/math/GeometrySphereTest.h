#ifndef PLANETCANNONS_GEOMETRYSPHERETEST_H
#define PLANETCANNONS_GEOMETRYSPHERETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "GeometrySphere.h"

class GeometrySphereTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(GeometrySphereTest);
        CPPUNIT_TEST(calculatePoint_anglePiHalfAndPiHalf_correctPoint);
        CPPUNIT_TEST(calculatePoint_anglePiAndPiHalf_correctPoint);
        CPPUNIT_TEST(calculatePointFromDistanceOnSurface_equatorAndQuarterCircleAndQuarterCircle_northPole);
        CPPUNIT_TEST(calculatePointFromDistanceOnSurface_equatorAndQuarterCircleAndQuarterCircleAndHalfRadius_northPole);
        CPPUNIT_TEST_SUITE_END();

    public:
        void calculatePoint_anglePiHalfAndPiHalf_correctPoint();
        void calculatePoint_anglePiAndPiHalf_correctPoint();
        void calculatePointFromDistanceOnSurface_equatorAndQuarterCircleAndQuarterCircle_northPole();
        void calculatePointFromDistanceOnSurface_equatorAndQuarterCircleAndQuarterCircleAndHalfRadius_northPole();

    private:
};

#endif