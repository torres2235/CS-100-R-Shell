#ifndef __SEMI_TEST_HPP__
#define __SEMI_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Base.hpp"
#include "../header/Command.hpp"
#include "../header/Semi.hpp"
#include "../header/Executor.hpp"

TEST(SemiTest, EchoTest) {
        Base* tester = new Command("echo hello");
        Base* tester2 = new Command("echo goodbye");

        Base* semiTest = new Semi(tester, tester2);

        EXPECT_EQ(semiTest->evaluate(), 0);
}

#endif //__SEMI_TEST_HPP__
