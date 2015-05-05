#include "LengthUnit.h"
#include "Formatter.h"

const unsigned int BASE_CONV_FACTOR = 1;
const unsigned int INCH_CONV_FACTOR = 1 * BASE_CONV_FACTOR;
const unsigned int FEET_CONV_FACTOR = 12 * INCH_CONV_FACTOR;
const unsigned int YARD_CONV_FACTOR = 3 * FEET_CONV_FACTOR;
const unsigned int MILE_CONV_FACTOR = 1760 * YARD_CONV_FACTOR;

#define strMILE "MILE"
#define strYARD "YARD"
#define strFEET "FEET"
#define strINCH "INCH"

#define IMPL_GET_METHOD(name)\
const LengthUnit& LengthUnit::get##name() {\
	static LengthUnit instance(name##_CONV_FACTOR, str##name);\
	return instance;\
}

IMPL_GET_METHOD(MILE)
IMPL_GET_METHOD(YARD)
IMPL_GET_METHOD(FEET)
IMPL_GET_METHOD(INCH)


void LengthUnit::accept(UnitVisitor& formatter) {
	auto container = LengthUnit::getUnitContainer();
	for (auto item : container) {
		formatter(item);
	}
}

Amount LengthUnit::toAmountInBaseUnit(const Amount& amount) const {
	return amount * toBaseUnitFactor;
}

LengthUnit::LengthUnit(unsigned int factor, string name)
: toBaseUnitFactor(factor),name(name) {
}

