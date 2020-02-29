#ifndef __AND_TEST_HPP__
#define __AND_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Base.hpp"
#include "../header/Command.hpp"
#include "../header/And.hpp"
#include "../header/Executor.hpp"

TEST(AndTest, EchoTest) {
        Base* tester = new Command("echo hello");
	Base* tester2 = new Command("echo goodbye");

	Base* andTest = new And(tester, tester2);

        EXPECT_EQ(andTest->evaluate(), 0);
}

TEST(AndTest, LeftFail) {
        Base* tester = new Command("this should fail");
        Base* tester2 = new Command("echo goodbye");

        Base* andTest = new And(tester, tester2);

        EXPECT_EQ(andTest->evaluate(), 256);
}

TEST(AndTest, RightFail) {
        Base* tester = new Command("echo hello");
        Base* tester2 = new Command("This should fail");

        Base* andTest = new And(tester, tester2);

        EXPECT_EQ(andTest->evaluate(), 256);
}

TEST(AndTest, BothFail) {
        Base* tester = new Command("This should fail");
        Base* tester2 = new Command("This should also fail");

        Base* andTest = new And(tester, tester2);

        EXPECT_EQ(andTest->evaluate(), 256);
}

#endif //__AND_TEST_HPP__
