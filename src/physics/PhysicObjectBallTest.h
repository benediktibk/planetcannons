#ifndef PLANETCANNONS_PHYSICOBJECTBALLTEST_H
#define PLANETCANNONS_PHYSICOBJECTBALLTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "PhysicObjectBall.h"
#include "utils/LoggerMock.h"

class PhysicObjectBallTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PhysicObjectBallTest);
        CPPUNIT_TEST(applyForce_notMovingAndNoForce_notMoved);
        CPPUNIT_TEST(applyForce_movingAndNoForce_movedDueToInitialVelocity);
        CPPUNIT_TEST(applyForce_notMovingAndNoForce_velocityNotChanged);
        CPPUNIT_TEST(applyForce_movingAndNoForce_velocityNotChanged);
        CPPUNIT_TEST(applyForce_notMovingAndForceButNoTime_notMoved);
        CPPUNIT_TEST(applyForce_movingAndForceButNoTime_notMoved);
        CPPUNIT_TEST(applyForce_notMovingAndForceButNoTime_velocityNotChanged);
        CPPUNIT_TEST(applyForce_movingAndForceButNoTime_velocityNotChanged);
        CPPUNIT_TEST(applyForce_notMovingAndForce_moved);
        CPPUNIT_TEST(applyForce_movingAndForce_moved);
        CPPUNIT_TEST(applyForce_notMovingAndForce_velocityChanged);
        CPPUNIT_TEST(applyForce_movingAndForce_velocityChanged);
        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

    public:
        void applyForce_notMovingAndNoForce_notMoved();
        void applyForce_movingAndNoForce_movedDueToInitialVelocity();
        void applyForce_notMovingAndNoForce_velocityNotChanged();
        void applyForce_movingAndNoForce_velocityNotChanged();
        void applyForce_notMovingAndForceButNoTime_notMoved();
        void applyForce_movingAndForceButNoTime_notMoved();
        void applyForce_notMovingAndForceButNoTime_velocityNotChanged();
        void applyForce_movingAndForceButNoTime_velocityNotChanged();
        void applyForce_notMovingAndForce_moved();
        void applyForce_movingAndForce_moved();
        void applyForce_notMovingAndForce_velocityChanged();
        void applyForce_movingAndForce_velocityChanged();

    private:
        PhysicObjectBall *m_ballNotMoving;
        PhysicObjectBall *m_ballMoving;
        LoggerMock *m_logger;
};

#endif