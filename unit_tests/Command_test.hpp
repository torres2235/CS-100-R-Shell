#ifndef __COMMAND_TEST_HPP__
#define __COMMAND_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Base.hpp"
#include "../header/Command.hpp"
#include "../header/Executor.hpp"

#include <iostream>
#include <vector>
#include <string>

TEST(CommandTest, EchoTest) {
	Base* tester = new Command("echo hello");
	EXPECT_EQ(tester->evaluate(), 0);
}

TEST(CommandTest, FailTest) {
        Base* tester = new Command("this should fail");
        EXPECT_EQ(tester->evaluate(), 256);
}
#endif //__COMMAND_TEST_HPP__
	
