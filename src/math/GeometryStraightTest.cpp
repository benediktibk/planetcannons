#include "GeometryStraightTest.h"
#include <cmath>

CPPUNIT_TEST_SUITE_REGISTRATION(GeometryStraightTest);

void GeometryStraightTest::getMidPoint_validStraight_correctPoint() {
    GeometryStraight straight(LinearAlgebraVector(5, 7, 1), LinearAlgebraVector(6, 8, 2));

    auto result = straight.getMidPoint();

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5.5, 7.5, 1.5), result, 1e-6));
}