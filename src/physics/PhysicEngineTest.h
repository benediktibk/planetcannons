#ifndef PLANETCANNONS_PHYSICENGINETEST_H
#define PLANETCANNONS_PHYSICENGINETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "PhysicEngine.h"
#include "utils/LoggerMock.h"
#include "PhysicObjectBallStatic.h"
#include "PhysicObjectBall.h"

class PhysicEngineTest : public CppUnit::TestFixture {
        CPPUNIT_TEST_SUITE(PhysicEngineTest);
        CPPUNIT_TEST(execute_personFallingToEarth_positionOfPersonIsCorrect);
        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp();
        void tearDown();

        void execute_personFallingToEarth_positionOfPersonIsCorrect();

    private:
        PhysicEngine *m_engine;
        LoggerMock *m_logger;
        PhysicObjectBall *m_person;
        PhysicObjectBallStatic *m_earth;
};

#endif