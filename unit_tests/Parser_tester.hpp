#ifndef __PARSER_TESTER_HPP__
#define __PARSER_TESTER_HPP__

#include "gtest/gtest.h"

#include "../header/Parser.hpp"

#include <iostream>
#include <vector>
#include <string>

TEST(ParserTester, ParseShortString) {
	Parser* str = new Parser("echo hello");
	str->parserLogic();
	vector<string> parsed = str->getVector();
	EXPECT_EQ(parsed.at(0), "echo hello");
}

TEST(ParserTester, ParseConnectors) {
	Parser* str = new Parser("echo hello && echo goodbye");
	str->parserLogic();
	vector<string> parsed = str->getVector();
	EXPECT_EQ(parsed.at(1), "&&" );
}

TEST(ParserTester, ParseConnectors2) {
	Parser* str = new Parser("echo hello || echo goodbye");
	str->parserLogic();
        vector<string> parsed = str->getVector();
        EXPECT_EQ(parsed.at(1), "||");
}

TEST(ParserTester, ParseConnectors3) {
	Parser* str = new Parser("echo hello; echo goodbye");
	str->parserLogic();
        vector<string> parsed = str->getVector();
        EXPECT_EQ(parsed.at(1), ";");
}

TEST(ParserTester, ParseLongString) {
	Parser* str = new Parser("mkdir && echo hello || echo goodbye;");
	str->parserLogic();
        vector<string> parsed = str->getVector();
        EXPECT_EQ(parsed.at(2), "echo hello ");
}

TEST(ParserTester, ParseLongString2) {
	Parser* str = new Parser("mkdir && echo hello || echo goodbye;");
	str->parserLogic();
        vector<string> parsed = str->getVector();
        EXPECT_EQ(parsed.at(3), "||");
}

TEST(ParserTester, ParseLongString3) {
	Parser* str = new Parser("mkdir && echo hello || echo goodbye;");
	str->parserLogic();
        vector<string> parsed = str->getVector();
        EXPECT_EQ(parsed.at(4), "echo goodbye");
}

TEST(ParserTester, ParseLongString4) {
	Parser* str = new Parser("mkdir && echo hello || echo goodbye;");
	str->parserLogic();
	vector<string> parsed = str->getVector();
	EXPECT_EQ(parsed.at(5), ";");
}

TEST(ParserTester, ParseCommentString) {
	Parser* str = new Parser("echo he#llo");
	str->parserLogic();
	vector<string> parsed = str->getVector();
	EXPECT_EQ(parsed.at(0), "echo he");
}

#endif //__PARSER_TESTER_HPP__
