#include "gtest/gtest.h"

#include "../unit_tests/Parser_tester.hpp"
#include "Executor_test.hpp"

#include "Command_test.hpp"
#include "And_test.hpp"
#include "Or_test.hpp"
#include "Semi_test.hpp"
#include "AllConnectors_test.hpp"
#include "shuntingYard_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
