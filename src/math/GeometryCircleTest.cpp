#include "GeometryCircleTest.h"
#include <cmath>

CPPUNIT_TEST_SUITE_REGISTRATION(GeometryCircleTest);

void GeometryCircleTest::calculatePoint_anglePiHalf_correctPoint() {
    GeometryCircle circle(LinearAlgebraVector(5, 7, 1), 0.5);

    auto result = circle.calculatePoint(M_PI/2);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 7.5, 1), result, 1e-6));
}
void GeometryCircleTest::calculatePoint_anglePi_correctPoint() {
    GeometryCircle circle(LinearAlgebraVector(5, 7, 1), 0.5);

    auto result = circle.calculatePoint(M_PI);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(4.5, 7, 1), result, 1e-6));
}