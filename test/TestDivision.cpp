/*
 * TestDivision.cpp
 *
 *  Created on: 2015Äê4ÔÂ2ÈÕ
 *      Author: Thoughtworks
 */


#include <gtest/gtest.h>
class TestDivision: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
};

TEST_F(TestDivision, )
{

}


#include <string>
using namespace std;

void appendToString(string& str, char value){
	str.append(string(1, value));
}

void appendToString(string& str, int value){
	appendToString(str, char(value + '0'));
}

int strToInt(string value){
	int factor = 1;
	auto result = 0;
	for (int i = value.size() - 1; i >= 0; i--){
		result += factor * (value[i] - '0');
		factor *= 10;
	}
	return result;
}

string intToString(int value){
	auto rest = value;
	string str;
	while (rest > 0){
		 appendToString(str, rest % 10);
		 rest = rest / 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

string toResult(const string& str){
	if (str.size() == 0){
		return str;
	}
	auto i = 0;
	while(i < str.size()){
		if (str[i] != '0'){
			break;
		}
		i++;
	}
	string result = str;
	result.erase(result.begin(), result.begin() + i);
	if (result.size() == 0){
		result = string(1, '0');
	}
	return result;
}

tuple<int, string> getMulti(string totalStr, string divStr){
	auto div = strToInt(divStr);
	auto total = strToInt(totalStr);
	int i = 0;
	for (; i < 10; i++){
		if  (i * div + div > total){
			break;
		}
	}
	return tuple<int, string>(i, intToString(total- i*div));
}

tuple<string, string> division(const string& strA, const string&  strB){
	string result;
	string rest = "";
	for (auto i = 0; i < strA.size(); i++){
		appendToString(rest, strA[i]);
		auto tempResult = getMulti(rest, strB);
		int value = get<0>(tempResult);
		appendToString(result, value);
		rest = get<1>(tempResult);
	}
	return tuple<string, string>(toResult(result), rest);
}

TEST_F(TestDivision, to_result){
	EXPECT_EQ("23", toResult("00023"));
	EXPECT_EQ("0", toResult("00000"));
}

TEST_F(TestDivision, testtoInt){
	EXPECT_EQ(1234, strToInt("1234"));
}

TEST_F(TestDivision, getMulti){
	auto value = getMulti("234", "34");
	EXPECT_EQ(6, get<0>(value));
	EXPECT_EQ("30", get<1>(value));
}

TEST_F(TestDivision, testDivision_simple){
	auto result = division("234", "34");
	EXPECT_EQ("6", get<0>(result));
	EXPECT_EQ("30", get<1>(result));
}
TEST_F(TestDivision, testDivision_final){
	auto result = division("74559", "345");
	EXPECT_EQ("216", get<0>(result));
	EXPECT_EQ("39", get<1>(result));
}



template<typename T>
class Vector{
public:
	typedef T value_type;
	typedef T* iterator;

	Vector(int size){

	}
	Vector(int size, const T& value = T()){

	}
private:
	allocator<T> acc;
};





