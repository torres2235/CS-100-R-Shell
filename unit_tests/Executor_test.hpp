#ifndef __EXECUTOR_TEST_HPP__
#define __EXECUTOR_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Base.hpp"
#include "../header/Executor.hpp"

#include <iostream>
#include <vector>
#include <string>

TEST(ExecutorTest, EchoTest) {
        Executor tester = Executor();

        EXPECT_EQ(tester.execute("echo hello"), 0);
}

TEST(ExecutorTest, FailTest) {
        Executor tester = Executor();

        EXPECT_EQ(tester.execute("this should fail"), 256);
}

TEST(ExecutorTest, TestCommandDirectory) {
	Executor tester = Executor();

	char sample[] = {'h', 'e', 'a', 'd', 'e', 'r'};
	char* hi = sample;
	EXPECT_EQ(tester.test(hi), 1);
}

#endif //__EXECUTOR_TEST_HPP__
