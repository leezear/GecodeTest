/*
 * GecodeModel.h
 *
 *  Created on: 2016年9月15日
 *      Author: leezear
 */

#ifndef GECODEMODEL_H_
#define GECODEMODEL_H_

#include <gecode/int.hh>
#include <gecode/minimodel.hh>
#include <gecode/search.hh>

using namespace Gecode;

class GecodeModel : public Gecode::Space {
private:
public:
	IntVarArray vars_;
	GecodeModel() {}
	GecodeModel(GecodeModel& s) {
		vars_ = IntVarArray(s.vars_);
	}
	GecodeModel(bool share, GecodeModel& s)
		: Space(share, s) {
		vars_.update(*this, share, s.vars_);
	}

	virtual Space* copy(bool share) {
		return new GecodeModel(share, *this);
	}

	void print(void) const {
		std::cout << vars_ << std::endl;
	}
	GecodeModel operator = (GecodeModel& s)
	{
		vars_ = IntVarArray(s.vars_);
	}
	virtual ~GecodeModel() {}
};

#endif /* GECODEMODEL_H_ */
