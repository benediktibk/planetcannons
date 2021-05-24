#include "GeometrySphereTest.h"
#include <cmath>

CPPUNIT_TEST_SUITE_REGISTRATION(GeometrySphereTest);

void GeometrySphereTest::calculatePoint_anglePiHalfAndPiHalf_correctPoint() {
    GeometrySphere sphere(LinearAlgebraVector(5, 7, 1), 0.5);

    auto result = sphere.calculatePoint(M_PI/2, M_PI/2);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 7.5, 1), result, 1e-6));
}
void GeometrySphereTest::calculatePoint_anglePiAndPiHalf_correctPoint() {
    GeometrySphere sphere(LinearAlgebraVector(5, 7, 1), 0.5);

    auto result = sphere.calculatePoint(M_PI, M_PI/2);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 7, 0.5), result, 1e-6));
}

void GeometrySphereTest::calculatePointFromDistanceOnSurface_equatorAndQuarterCircleAndQuarterCircle_northPole() {
    GeometrySphere sphere(LinearAlgebraVector(5, 7, 1), 1);

    auto result = sphere.calculatePointFromDistanceOnSurface(LinearAlgebraVector(6, 7, 1), M_PI/2, M_PI/2);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 7, 2), result, 1e-6));
}

void GeometrySphereTest::calculatePointFromDistanceOnSurface_equatorAndQuarterCircleAndQuarterCircleAndHalfRadius_northPole() {
    GeometrySphere sphere(LinearAlgebraVector(5, 7, 1), 0.5);

    auto result = sphere.calculatePointFromDistanceOnSurface(LinearAlgebraVector(5.5, 7, 1), M_PI/4, M_PI/4);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 7, 1.5), result, 1e-6));
}

void GeometrySphereTest::calculatePointFromDistanceOnSurface_equatorAndQuarterCircleAndQuarterCircleReverse_southPole() {
    GeometrySphere sphere(LinearAlgebraVector(5, 7, 1), 1);

    auto result = sphere.calculatePointFromDistanceOnSurface(LinearAlgebraVector(6, 7, 1), (-1)*M_PI/2, (-1)*M_PI/2);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 7, 0), result, 1e-6));
}