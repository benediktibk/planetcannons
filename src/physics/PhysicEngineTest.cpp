#include "PhysicEngineTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PhysicEngineTest);

void PhysicEngineTest::setUp() {
    m_logger = new LoggerMock();
    m_engine = new PhysicEngine(*m_logger, 1e-3);
    m_person = new PhysicObjectBall(*m_logger, 60, 1, LinearAlgebraVector(6370100, 0, 0), LinearAlgebraVector(0, 0, 0));
    m_earth = new PhysicObjectBallStatic(*m_logger, 5.972e24, 6370000, LinearAlgebraVector(0, 0, 0));
    m_engine->add(*m_person);
    m_engine->add(*m_earth);
}

void PhysicEngineTest::tearDown() {
    delete m_engine;
    m_engine = 0;
    delete m_person;
    m_person = 0;
    delete m_earth;
    m_earth = 0;
    delete m_logger;
    m_logger = 0;
}

void PhysicEngineTest::execute_personFallingToEarth_positionOfPersonIsCorrect() {
    m_engine->execute(2);

    auto position = m_person->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(6370100 - 20, 0, 0), position, 1));
}