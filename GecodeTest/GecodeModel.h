/*
 * GecodeModel.h
 *
 *  Created on: 2016年9月15日
 *      Author: leezear
 */

#ifndef GECODEMODEL_H_
#define GECODEMODEL_H_

#include <gecode/driver.hh>
#include <gecode/int.hh>
#include <gecode/minimodel.hh>

using namespace Gecode;

class GecodeModel : public Script {
private:
public:
	IntVarArray vars_;
	GecodeModel(const SizeOptions& opt) :
		Script(opt) {}
	GecodeModel(bool share, GecodeModel& s)
		: Script(share, s) {
		vars_.update(*this, share, s.vars_);
	}

	virtual Space* copy(bool share) {
		return new GecodeModel(share, *this);
	}

	virtual void print(std::ostream& os) const {
		os << vars_ << std::endl;
	}
	GecodeModel operator = (GecodeModel& s)
	{
		vars_ = IntVarArray(s.vars_);
	}
	virtual ~GecodeModel() {}
};

#endif /* GECODEMODEL_H_ */
