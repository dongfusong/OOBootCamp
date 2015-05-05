
#ifndef LENGTHUNIT_H_
#define LENGTHUNIT_H_
#include "typedefine.h"
#include <vector>
#include <string>
using namespace std;
#define BASE_UNIT INCH
#define MILE LengthUnit::getMILE()
#define INCH LengthUnit::getINCH()
#define FEET LengthUnit::getFEET()
#define YARD LengthUnit::getYARD()

class UnitVisitor;
class LengthUnit{
public:
#define DECL_GET_METHOD(name) static const LengthUnit& get##name();

	DECL_GET_METHOD(MILE)
	DECL_GET_METHOD(FEET)
	DECL_GET_METHOD(YARD)
	DECL_GET_METHOD(INCH)

	static vector<LengthUnit>& getUnitContainer() {
		static vector<LengthUnit> container { MILE, YARD, FEET, INCH};
		return container;
	}
	
	static void accept(UnitVisitor& formatter);

	Amount toAmountInBaseUnit(const Amount& amount) const;
	string getName()const{
		return name;
	}
private:
	LengthUnit(unsigned int factor, string name);
private:
	unsigned int toBaseUnitFactor;
	string name;
};
#endif /* LENGTHUNIT_H_ */
