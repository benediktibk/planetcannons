#include "LinearAlgebraVectorTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(LinearAlgebraVectorTest);

void LinearAlgebraVectorTest::getX_setTo5_5() {
    LinearAlgebraVector vector(5, 7, 1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(5, vector.getX(), 1e-6);
}

void LinearAlgebraVectorTest::getY_setTo7_7() {
    LinearAlgebraVector vector(5, 7, 1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(7, vector.getY(), 1e-6);
}

void LinearAlgebraVectorTest::getZ_setTo1_1() {
    LinearAlgebraVector vector(5, 7, 1);

    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, vector.getZ(), 1e-6);
}

void LinearAlgebraVectorTest::operatorEqualsWithEpsilon_sameContent_true() {
    LinearAlgebraVector a(5, 7, 1);
    LinearAlgebraVector b(5, 7, 1);

    bool result = LinearAlgebraVector::equalsWithEpsilon(a, b, 1e-6);

    CPPUNIT_ASSERT(result);
}

void LinearAlgebraVectorTest::operatorEqualsWithEpsilon_differentContent_false() {
    LinearAlgebraVector a(5, 7, 1);
    LinearAlgebraVector b(-1, 2, 4);

    bool result = LinearAlgebraVector::equalsWithEpsilon(a, b, 1e-6);

    CPPUNIT_ASSERT(!result);
}

void LinearAlgebraVectorTest::operatorAdd_validVector_correctResult() {
    LinearAlgebraVector a(5, 7, 1);
    LinearAlgebraVector b(-1, 2, 4);

    auto result = a + b;

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(4, 9, 5), result, 1e-6));
}

void LinearAlgebraVectorTest::operatorSubtract_validVector_correctResult() {
    LinearAlgebraVector a(5, 7, 1);
    LinearAlgebraVector b(-1, 2, 4);

    auto result = a - b;

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(6, 5, -3), result, 1e-6));
}

void LinearAlgebraVectorTest::operatorMultiplyWithScalar_validScalar_correctResult() {
    LinearAlgebraVector a(5, 7, 1);

    auto result = a*2;

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(10, 14, 2), result, 1e-6));
}

void LinearAlgebraVectorTest::operatorMultiplyWithScalarAsFirstOperator_validScalar_correctResult() {
    LinearAlgebraVector a(5, 7, 1);

    auto result = 2*a;

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(10, 14, 2), result, 1e-6));
}

void LinearAlgebraVectorTest::operatorCastToTuple_validVector_correctResult() {
    LinearAlgebraVector a(5, 7, 1);

    auto result = (std::tuple<double, double, double>)a;

    CPPUNIT_ASSERT_DOUBLES_EQUAL(5, std::get<0>(result), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(7, std::get<1>(result), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1, std::get<2>(result), 1e-6);
}

void LinearAlgebraVectorTest::crossProduct_yAxisAndZAxis_xAxis() {
    LinearAlgebraVector a(0, 1, 0);
    LinearAlgebraVector b(0, 0, 1);

    auto result = LinearAlgebraVector::crossProduct(a, b);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(1, 0, 0), result, 1e-6));
}

void LinearAlgebraVectorTest::crossProduct_twoValidVectors_correctResult() {
    LinearAlgebraVector a(5, -3, 2);
    LinearAlgebraVector b(-1, 9, 4);

    auto result = LinearAlgebraVector::crossProduct(a, b);

    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(-30, -22, 42), result, 1e-6));
}