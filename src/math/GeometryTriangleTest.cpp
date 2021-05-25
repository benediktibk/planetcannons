#include "GeometryTriangleTest.h"
#include <cmath>

CPPUNIT_TEST_SUITE_REGISTRATION(GeometryTriangleTest);

void GeometryTriangleTest::calculateMidPointSubTriangles_validTriangle_4Results() {
    GeometryTriangle triangle(LinearAlgebraVector(0, 0, 0), LinearAlgebraVector(1, 1, 0), LinearAlgebraVector(0, 0, 1));

    auto result = triangle.calculateMidPointSubTriangles();

    CPPUNIT_ASSERT_EQUAL((size_t)4, result.size());
}

void GeometryTriangleTest::calculateMidPointSubTriangles_validTriangle_correctPoints()  {
    GeometryTriangle triangle(LinearAlgebraVector(0, 0, 0), LinearAlgebraVector(1, 1, 0), LinearAlgebraVector(0, 0, 1));

    auto result = triangle.calculateMidPointSubTriangles();

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0), result[0].getPointOne(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0.5, 0.5, 0), result[0].getPointTwo(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0.5), result[0].getPointThree(), 1e-6));

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0.5, 0.5, 0), result[1].getPointOne(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(1, 1, 0), result[1].getPointTwo(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0.5, 0.5, 0.5), result[1].getPointThree(), 1e-6));

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0.5), result[2].getPointOne(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0.5, 0.5, 0.5), result[2].getPointTwo(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 1), result[2].getPointThree(), 1e-6));

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0.5, 0.5, 0), result[3].getPointOne(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0.5, 0.5, 0.5), result[3].getPointTwo(), 1e-6));
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0.5), result[3].getPointThree(), 1e-6));
}