// parser_test.cpp
// @author rvarago

#include <gtest/gtest.h>
#include <string>

#include "parser.h"
#include "parser_builder.h"

using namespace std;
using namespace rpn;

TEST(Parser, SimpleExpr)
{
	Parser parser = make_parser();
	double actual = compute(parser, "3 2 +");

	EXPECT_DOUBLE_EQ(5, actual);
}

TEST(Parser, ComplexExpr)
{
	Parser parser = make_parser();
	double actual = compute(parser, "3 4 2 * 1 5 - 2 3 ^ ^ / +");

	EXPECT_NEAR(3.0, actual, 0.1);
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
