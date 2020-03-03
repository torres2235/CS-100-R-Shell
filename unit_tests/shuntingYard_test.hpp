#ifndef __SHUNTINGYARD_TEST__
#define __SHUNTINGYARD_TEST__

#include "gtest/gtest.h"

#include "../header/shuntingYard.hpp"

#include <vector> 
#include <queue>

TEST(ShuntingYardTest, FirstTest) {
	ShuntingYard tester = ShuntingYard();
	vector <string> test = {"echo hello", "&&",  "echo goodbye"};
	queue <string> newQueue = tester.infixToPostFix(test);
	EXPECT_EQ(newQueue.front(), "echo hello");

}

#endif //__SHUNTINGYARD_TEST__
