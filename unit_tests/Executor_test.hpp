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

TEST(ExecutorTest, FailTestCommandDirectory) {
        Executor tester = Executor();

        char sample[] = {'h', 'e', 'a', 'd', 'e'};
        char* hi = sample;
        EXPECT_EQ(tester.test(hi), 0);
}

TEST(ExecutorTest, TestCommandMain) {
	Executor tester = Executor();

	char sample[] = {'s', 'r', 'c', '/', 'm', 'a', 'i', 'n', '.', 'c', 'p', 'p'};
	char* hi = sample;
	EXPECT_EQ(tester.test(hi), 2);
}

TEST(ExecutorTest, FailTestCommandMain) {
        Executor tester = Executor();

        char sample[] = {'s', 'r', 'c', '/', 'm', 'a', 'i', 'n', '.', 'c', 'p'};
        char* hi = sample;
        EXPECT_EQ(tester.test(hi), 0);
}

TEST(ExecutorTest, FailTestCommandMain2) {
        Executor tester = Executor();

        char sample[] = {'m', 'a', 'i', 'n', '.', 'c', 'p', 'p'};
        char* hi = sample;
        EXPECT_EQ(tester.test(hi), 0);
}



#endif //__EXECUTOR_TEST_HPP__
