#ifndef PLANETCANNONS_PHYSICOBJECTBALLSTATICTEST_H
#define PLANETCANNONS_PHYSICOBJECTBALLSTATICTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "PhysicObjectBallStatic.h"
#include "LoggerMock.h"

class PhysicObjectBallStaticTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PhysicObjectBallStaticTest);
        CPPUNIT_TEST(applyForce_noForce_notMoved);
        CPPUNIT_TEST(applyForce_noForce_velocityNotChanged);
        CPPUNIT_TEST(applyForce_forceButNoTime_notMoved);
        CPPUNIT_TEST(applyForce_forceButNoTime_velocityNotChanged);
        CPPUNIT_TEST(applyForce_force_notMoved);
        CPPUNIT_TEST(applyForce_force_velocityNotChanged);
        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

    public:
        void applyForce_noForce_notMoved();
        void applyForce_noForce_velocityNotChanged();
        void applyForce_forceButNoTime_notMoved();
        void applyForce_forceButNoTime_velocityNotChanged();
        void applyForce_force_notMoved();
        void applyForce_force_velocityNotChanged();

    private:
        PhysicObjectBallStatic *m_ball;
        LoggerMock *m_logger;
};

#endif