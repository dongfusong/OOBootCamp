/*
 * TestOO.cpp
 *
 *  Created on: 2015��3��5��
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "Length.h"
#include "Formatter.h"
#include "FormatterLength.h"
#include <sstream>
using namespace std;

class TestLength: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestLength, 1_mile_equal_to_1_mile){
	EXPECT_EQ(true, Mile(1) == Mile(1));
}

TEST_F(TestLength, 1_mile_not_equal_to_3_mile){
	EXPECT_EQ(true, Mile(1) != Mile(3));
}

TEST_F(TestLength, 1_yard_equal_to_1_yard){
	EXPECT_EQ(true, Yard(1) == Yard(1));
}

TEST_F(TestLength, 2_yard_not_equal_to_5_yard){
	EXPECT_EQ(true, Yard(2) != Yard(5));
}

TEST_F(TestLength, 1_mile_equal_to_1760_yard){
	EXPECT_EQ(true, Mile(1) == Yard(1760));
}

TEST_F(TestLength, 1_yard_equal_to_3_feet){
	EXPECT_EQ(true, Yard(1) == Feet(3));
}

TEST_F(TestLength, 1_Feet_equal_to_12_Inch){
	EXPECT_EQ(true, Feet(1) == Inch(12));
}

TEST_F(TestLength, test_11inch_add_13inch_equal_to_2Feet){
	EXPECT_EQ(true, Feet(2) == Inch(11) + Inch(13));
}

TEST_F(TestLength, test_3Feet_add_3Yard_equal_to_3Yard){
	EXPECT_EQ(true, Feet(2) == Inch(11) + Inch(13));
}

TEST_F(TestLength, test_14intch_output_1feet2inch){
	ostringstream os;
	os << FormatterLength(Inch(14), ALL_UNIT_FORMAT);
	EXPECT_EQ("1 FEET 2 INCH", os.str());
}

TEST_F(TestLength, test_24intch_output_2feet){
	ostringstream os;
	os << FormatterLength(Inch(24), ALL_UNIT_FORMAT);
	EXPECT_EQ("2 FEET", os.str());
}

TEST_F(TestLength, test_0intch_output_0inch){
	ostringstream os;
	os << FormatterLength(Inch(0), ALL_UNIT_FORMAT);
	EXPECT_EQ("0 INCH", os.str());
}

TEST_F(TestLength, test_2_feet_output_24inch)
{
	ostringstream os;
	os << FormatterLength(Feet(2), ONE_UNIT_FORMAT);
	EXPECT_EQ("24 INCH", os.str());
}


