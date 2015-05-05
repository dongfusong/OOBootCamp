/*
 * Formatter.h
 *
 *  Created on: 2015��4��16��
 *      Author: Thoughtworks
 */

#ifndef FORMATTER_H_
#define FORMATTER_H_

#include <ostream>
#include "UnitVisitor.h"
using namespace std;

class Formatter{
public:
	virtual void format(ostream& os, int value) = 0;
	virtual ~Formatter(){}
};


class  FormatImpl : public UnitVisitor{
public:
	FormatImpl(ostream& os, int totalValue):
		os(os),total(totalValue){
	}
	void operator ()(LengthUnit&) override;
private:
	void format(int value, const string str);
private:
	ostream& os;
	int total = 0;
	bool fstFlg = true;
};


class AllUnitFormatter : public Formatter{
public:
	void format(ostream& os, int total) override;
};

class OneUnitFormatter : public Formatter{
public:
	void format(ostream& os, int total) override;
};

#define ALL_UNIT_FORMAT getAllUnitsFormatter()
Formatter* getAllUnitsFormatter();


#define ONE_UNIT_FORMAT getOneUnitFormatter()
Formatter* getOneUnitFormatter();

#endif /* FORMATTER_H_ */
