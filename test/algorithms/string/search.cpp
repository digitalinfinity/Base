#include "stdafx.h"
#include <base.h>
#include <algorithms/string/search.h>

class StringEditDistance: public ::testing::Test {
};

TEST_F(StringEditDistance, BasicEditDistance) {
	CharType* string1 = L"sitting";
	CharType* string2 = L"kitten";
	size_t calculatedDistance = String::LevenshteinDistance(string1, string2);
	EXPECT_EQ(3, calculatedDistance);

	string1 = L"Sunday";
	string2 = L"Saturday";

	calculatedDistance = String::LevenshteinDistance(string1, string2);
	EXPECT_EQ(3, calculatedDistance);
}