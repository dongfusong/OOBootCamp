/*
 * Mile.h
 *
 *  Created on: 2015��3��5��
 *      Author: Thoughtworks
 */

#ifndef Length_H_
#define Length_H_
#include "typedefine.h"
#include "LengthUnit.h"
#include "Quantity.h"
#include <ostream>
using namespace std;

#define Mile(value) Length(value, MILE)
#define Yard(value) Length(value, YARD)
#define Feet(value) Length(value, FEET)
#define Inch(value) Length(value, INCH)

class Formatter;
class Length : public Quantity<LengthUnit>{
public:
	Length(const Amount& amount, const LengthUnit& unit);
	void format(ostream& os, Formatter* formatter) const;
};
#endif
