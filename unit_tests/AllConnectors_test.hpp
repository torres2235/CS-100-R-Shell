#ifndef __ALLCONNECTORS_TEST_HPP__
#define __ALLCONNECTORS_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Base.hpp"
#include "../header/Command.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Semi.hpp"
#include "../header/Executor.hpp"


TEST(AllConnectorsTest, EchoTest) { // this should fail || echo hello && echo dawg; echo goodbye
        Base* hello = new Command("echo hello");
        Base* goodbye = new Command("echo goodbye");
	Base* wassup = new Command("echo wassup");
	Base* dawg = new Command("echo dawg");
	Base* fail = new Command("this should fail");

        Base* orTest = new Or(fail, hello);
	Base* andTest = new And(orTest, dawg);
	Base* semiTest = new Semi(andTest, goodbye);

        EXPECT_EQ(semiTest->evaluate(), 0);
}

#endif //__ALLCONNECTORS_TEST_HPP__
