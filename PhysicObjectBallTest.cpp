#include "PhysicObjectBallTest.h"
#include "LoggerMock.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PhysicObjectBallTest);

void PhysicObjectBallTest::setUp() {
    m_logger = new LoggerMock();
    m_ballNotMoving = new PhysicObjectBall(
        *m_logger, 
        2, 
        0.1, 
        std::make_tuple<double, double, double>(5, 10, 3), 
        std::make_tuple<double, double, double>(0, 0, 0));
    m_ballMoving = new PhysicObjectBall(
        *m_logger, 
        2, 
        0.1, 
        std::make_tuple<double, double, double>(5, 10, 3), 
        std::make_tuple<double, double, double>(-1, 2, 0.1));
}

void PhysicObjectBallTest::tearDown() {
    delete m_ballMoving;
    m_ballMoving = 0;
    delete m_ballNotMoving;
    m_ballNotMoving = 0;
    delete m_logger;
    m_logger = 0;
}

void PhysicObjectBallTest::applyForce_notMovingAndNoForce_notMoved() {
    m_ballNotMoving->applyForce(std::make_tuple<double, double, double>(0, 0, 0), 0.5);

    auto position = m_ballNotMoving->getPosition();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5, std::get<0>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, std::get<1>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(3, std::get<2>(position), 1e-6);
}

void PhysicObjectBallTest::applyForce_movingAndNoForce_movedDueToInitialVelocity() {
    m_ballMoving->applyForce(std::make_tuple<double, double, double>(0, 0, 0), 0.5);

    auto position = m_ballMoving->getPosition();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(4.5, std::get<0>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(11, std::get<1>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(3.05, std::get<2>(position), 1e-6);
}

void PhysicObjectBallTest::applyForce_notMovingAndNoForce_velocityNotChanged() {
    m_ballNotMoving->applyForce(std::make_tuple<double, double, double>(0, 0, 0), 0.5);

    auto velocity = m_ballNotMoving->getVelocity();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, std::get<0>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, std::get<1>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, std::get<2>(velocity), 1e-6);
}

void PhysicObjectBallTest::applyForce_movingAndNoForce_velocityNotChanged() {
    m_ballMoving->applyForce(std::make_tuple<double, double, double>(0, 0, 0), 0.5);

    auto velocity = m_ballMoving->getVelocity();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-1, std::get<0>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(2, std::get<1>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.1, std::get<2>(velocity), 1e-6);
}

void PhysicObjectBallTest::applyForce_notMovingAndForceButNoTime_notMoved() {
    m_ballNotMoving->applyForce(std::make_tuple<double, double, double>(0, 20, 0), 0);

    auto position = m_ballNotMoving->getPosition();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5, std::get<0>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, std::get<1>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(3, std::get<2>(position), 1e-6);
}

void PhysicObjectBallTest::applyForce_movingAndForceButNoTime_notMoved() {
    m_ballMoving->applyForce(std::make_tuple<double, double, double>(0, 20, 0), 0);

    auto position = m_ballMoving->getPosition();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5, std::get<0>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(10, std::get<1>(position), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(3, std::get<2>(position), 1e-6);
}

void PhysicObjectBallTest::applyForce_notMovingAndForceButNoTime_velocityNotChanged() {
    m_ballNotMoving->applyForce(std::make_tuple<double, double, double>(0, 20, 0), 0);

    auto velocity = m_ballNotMoving->getVelocity();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, std::get<0>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, std::get<1>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0, std::get<2>(velocity), 1e-6);
}

void PhysicObjectBallTest::applyForce_movingAndForceButNoTime_velocityNotChanged() {
    m_ballMoving->applyForce(std::make_tuple<double, double, double>(0, 20, 0), 0);

    auto velocity = m_ballMoving->getVelocity();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-1, std::get<0>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(2, std::get<1>(velocity), 1e-6);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(0.1, std::get<2>(velocity), 1e-6);
}