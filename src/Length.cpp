#include "Length.h"
#include "Formatter.h"
Length::Length(const Amount& amount, const LengthUnit& unit) :
		Quantity<LengthUnit>(amount, unit) {
}

void Length::format(ostream& os, Formatter* formatter) const {
	formatter->format(os, toAmountInBaseUnit());
}
