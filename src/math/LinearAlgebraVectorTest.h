#ifndef PLANETCANNONS_LINEARALGEBRAVECTORTEST_H
#define PLANETCANNONS_LINEARALGEBRAVECTORTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "LinearAlgebraVector.h"

class LinearAlgebraVectorTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(LinearAlgebraVectorTest);
        CPPUNIT_TEST(getX_setTo5_5);
        CPPUNIT_TEST(getY_setTo7_7);
        CPPUNIT_TEST(getZ_setTo1_1);
        CPPUNIT_TEST_SUITE_END();

    public:
        void getX_setTo5_5();
        void getY_setTo7_7();
        void getZ_setTo1_1();

    private:
};

#endif