#ifndef PLANETCANNONS_LINEARALGEBRAVECTORTEST_H
#define PLANETCANNONS_LINEARALGEBRAVECTORTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "LinearAlgebraVector.h"

class LinearAlgebraVectorTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(LinearAlgebraVectorTest);
        CPPUNIT_TEST(getX_setTo5_5);
        CPPUNIT_TEST(getY_setTo7_7);
        CPPUNIT_TEST(getZ_setTo1_1);
        CPPUNIT_TEST(operatorEqualsWithEpsilon_sameContent_true);
        CPPUNIT_TEST(operatorEqualsWithEpsilon_differentContent_false);
        CPPUNIT_TEST(operatorAdd_validVector_correctResult);
        CPPUNIT_TEST(operatorSubtract_validVector_correctResult);
        CPPUNIT_TEST(operatorMultiplyWithScalar_validScalar_correctResult);
        CPPUNIT_TEST(operatorMultiplyWithScalarAsFirstOperator_validScalar_correctResult);
        CPPUNIT_TEST(operatorCastToTuple_validVector_correctResult);
        CPPUNIT_TEST(crossProduct_yAxisAndZAxis_xAxis);
        CPPUNIT_TEST(crossProduct_twoValidVectors_correctResult);
        CPPUNIT_TEST(dotProduct_twoValidVectors_correctResult);
        CPPUNIT_TEST_SUITE_END();

    public:
        void getX_setTo5_5();
        void getY_setTo7_7();
        void getZ_setTo1_1();
        void operatorEqualsWithEpsilon_sameContent_true();
        void operatorEqualsWithEpsilon_differentContent_false();
        void operatorAdd_validVector_correctResult();
        void operatorSubtract_validVector_correctResult();
        void operatorMultiplyWithScalar_validScalar_correctResult();
        void operatorMultiplyWithScalarAsFirstOperator_validScalar_correctResult();
        void operatorCastToTuple_validVector_correctResult();
        void crossProduct_yAxisAndZAxis_xAxis();
        void crossProduct_twoValidVectors_correctResult();
        void dotProduct_twoValidVectors_correctResult();

    private:
};

#endif