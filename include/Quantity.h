/*
 * Quantity.h
 *
 *  Created on: 2015Äê4ÔÂ16ÈÕ
 *      Author: Thoughtworks
 */

#ifndef QUANTITY_H_
#define QUANTITY_H_

#include "typedefine.h"
template<typename UNIT>
class Quantity{
public:
	Quantity(const Amount& amount, const UNIT& unit):_amount(amount),_unit(unit){}

	bool operator ==(const Quantity<UNIT>& rhs) const{
		return rhs.toAmountInBaseUnit() == toAmountInBaseUnit();
	}

	bool operator != (const Quantity<UNIT>& rhs) const{
		return not (*this == rhs);
	}

	friend const Quantity<UNIT> operator +(const Quantity<UNIT>& lhs, const Quantity<UNIT>& rhs){
		return Quantity<UNIT>(rhs.toAmountInBaseUnit() + lhs.toAmountInBaseUnit(), BASE_UNIT);
	}

protected:
	Amount toAmountInBaseUnit() const{
		return _unit.toAmountInBaseUnit(_amount);
	}
	Amount _amount;
	const UNIT& _unit;
};

#endif /* QUANTITY_H_ */
