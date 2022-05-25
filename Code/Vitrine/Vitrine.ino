// Comment the line below to disable test mode
#define TEST_MODE

#ifdef TEST_MODE

#include "MainTest.h"

void setup() {
    testSetup();
}

void loop() {
    testLoop();
}

#else

#include "Main.h"

void setup() {
    mainSetup();
}

void loop() {
    mainLoop();
}

#endif
