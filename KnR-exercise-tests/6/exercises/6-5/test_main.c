// Include the test framework.
#include "../../../test-framework/unity.h"
#include "main.h"

void setUp(void) {}

void tearDown(void) {}

static void test_hello_world(void) { TEST_ASSERT_EQUAL_INT(0, hello_world()); }

// Runs the test(s)
int main(void) {
  UnityBegin("test_main.c");

  RUN_TEST(test_hello_world);

  return UnityEnd();
}
