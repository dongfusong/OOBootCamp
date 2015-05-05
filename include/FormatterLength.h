/*
 * FormatterLength.h
 *
 *  Created on: 2015年4月30日
 *      Author: Thoughtworks
 */

#ifndef FORMATTERLENGTH_H_
#define FORMATTERLENGTH_H_
#include <sstream>
using namespace std;

class FormatterLength{
public:
	friend ostream& operator<<(ostream& os, const FormatterLength& rhs){
		rhs.format(os);
		return os;
	}

	FormatterLength(const Length& length, Formatter* formatter)
	:length(length), formatter(formatter)
	{

	}
	void format(ostream& os)const{
		length.format(os, formatter);
	}
private:
	const Length& length;
	Formatter* formatter;
};
#endif /* FORMATTERLENGTH_H_ */
