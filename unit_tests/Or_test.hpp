#ifndef __OR_TEST_HPP__
#define __OR_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Base.hpp"
#include "../header/Command.hpp"
#include "../header/Or.hpp"
#include "../header/Executor.hpp"

TEST(OrTest, LeftPass) {
        Base* tester = new Command("echo hello");
        Base* tester2 = new Command("echo goodbye");

        Base* orTest = new Or(tester, tester2);

        EXPECT_EQ(orTest->evaluate(), 0);
}

TEST(OrTest, LeftFail) {
        Base* tester = new Command("this should fail");
        Base* tester2 = new Command("echo goodbye");

        Base* orTest = new Or(tester, tester2);

        EXPECT_EQ(orTest->evaluate(), 0);
}

TEST(OrTest, RightFail) {
        Base* tester = new Command("echo hello");
        Base* tester2 = new Command("This should fail");

        Base* orTest = new Or(tester, tester2);

        EXPECT_EQ(orTest->evaluate(), 0);
}

TEST(OrTest, BothFail) {
        Base* tester = new Command("This should fail");
        Base* tester2 = new Command("This should also fail");

        Base* orTest = new Or(tester, tester2);

        EXPECT_EQ(orTest->evaluate(), 256);
}

#endif //__OR_TEST_HPP__
