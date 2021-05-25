#ifndef PLANETCANNONS_GEOMETRYSTRAIGHTTEST_H
#define PLANETCANNONS_GEOMETRYSTRAIGHTTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "GeometryStraight.h"

class GeometryStraightTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(GeometryStraightTest);
        CPPUNIT_TEST(getMidPoint_validStraight_correctPoint);
        CPPUNIT_TEST_SUITE_END();

    public:
        void getMidPoint_validStraight_correctPoint();

    private:
};

#endif