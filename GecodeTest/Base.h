/*
 * Base.h
 *
 *  Created on: 2016年6月22日
 *      Author: leezear
 */

#ifndef BASE_H_
#define BASE_H_

#include "type_define.h"

namespace cudacsp
{
namespace model
{

class Base
{
public:
	u32 id = 0;		///<Object id

	Base();
	Base(const u32 id);
	virtual ~Base();
};

} /* namespace model */
} /* namespace cudacsp */

#endif /* BASE_H_ */
