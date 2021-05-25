#ifndef PLANETCANNONS_GEOMETRYTRIANGLETEST_H
#define PLANETCANNONS_GEOMETRYTRIANGLETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "GeometryTriangle.h"

class GeometryTriangleTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(GeometryTriangleTest);
        CPPUNIT_TEST(calculateMidPointSubTriangles_validTriangle_4Results);
        CPPUNIT_TEST(calculateMidPointSubTriangles_validTriangle_correctPoints);
        CPPUNIT_TEST_SUITE_END();

    public:
        void calculateMidPointSubTriangles_validTriangle_4Results();
        void calculateMidPointSubTriangles_validTriangle_correctPoints();

    private:
};

#endif