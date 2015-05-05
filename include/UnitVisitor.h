/*
 * Visitor.h
 *
 *  Created on: 2015年5月5日
 *      Author: Thoughtworks
 */

#ifndef VISITOR_H_
#define VISITOR_H_
#include <string>
class LengthUnit;
class UnitVisitor{
public:
	virtual void operator ()(LengthUnit& unit) = 0;
	virtual ~UnitVisitor(){}
};

#endif /* VISITOR_H_ */

