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