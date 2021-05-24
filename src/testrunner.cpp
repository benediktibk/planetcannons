#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <iostream>

int main() {
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));
    bool success = runner.run();
    return success ? 0 : 1;
}