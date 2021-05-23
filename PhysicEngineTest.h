#ifndef PLANETCANNONS_PHYSICENGINETEST_H
#define PLANETCANNONS_PHYSICENGINETEST_H

#include <cppunit/extensions/HelperMacros.h>

class PhysicEngineTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PhysicEngineTest);
        CPPUNIT_TEST(blub);
        CPPUNIT_TEST_SUITE_END();

    public:
        void blub();
};

#endif