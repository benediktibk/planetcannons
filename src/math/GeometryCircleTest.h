#ifndef PLANETCANNONS_GEOMETRYCIRCLETEST_H
#define PLANETCANNONS_GEOMETRYCIRCLETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "GeometryCircle.h"

class GeometryCircleTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(GeometryCircleTest);
        CPPUNIT_TEST(calculatePoint_anglePiHalf_correctPoint);
        CPPUNIT_TEST(calculatePoint_anglePi_correctPoint);
        CPPUNIT_TEST_SUITE_END();

    public:
        void calculatePoint_anglePiHalf_correctPoint();
        void calculatePoint_anglePi_correctPoint();

    private:
};

#endif