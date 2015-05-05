#include "Formatter.h"
#include "LengthUnit.h"


static string space = " ";
static string baseUnitName = "INCH";


void FormatImpl::operator ()(LengthUnit& unit)
{
	format(unit.toAmountInBaseUnit(1), unit.getName());
}

void FormatImpl::format(int value, const string str)
{
	if (total == 0) {
		if (fstFlg){
			os << "0" << space << BASE_UNIT.getName();
			fstFlg = false;
		}
		return;
	}
	if (total > value) {
		auto count = total / value;
		total -= count * value;
		if (fstFlg) {
			os << count << space << str;
			fstFlg = false;
		} else {
			os << space << count << space << str;
		}
	}
}

void AllUnitFormatter::format(ostream& os, int total) {
	FormatImpl fomatter(os, total);
	LengthUnit::accept(fomatter);
}

void OneUnitFormatter::format(ostream& os, int total) {
	os << total << " " << baseUnitName;
}


Formatter* getAllUnitsFormatter() {
	static Formatter* formatter = new AllUnitFormatter();
	return formatter;
}


Formatter* getOneUnitFormatter(){
	static Formatter* formatter = new OneUnitFormatter();
	return formatter;
}

