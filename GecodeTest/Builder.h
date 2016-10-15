/*
 * Builder.h
 *
 *  Created on: 2016年6月21日
 *      Author: leezear
 */

#ifndef BUILDER_H_
#define BUILDER_H_
#include "type_define.h"
using namespace cudacsp::model;

namespace cudacsp
{
namespace parse
{
/**
 *\brief some Types of bankmark file type
 */
enum BMFileType
{
	BFT_TXT,			///<txt doc
	BFT_XCSP_2_0_INT,	///<xcsp v2.0 intension
	BFT_XCSP_2_1_INT,	///<xcsp v2.1 intension
	BFT_XCSP_3_0_INT,	///<xcsp v3.0 intension
	BFT_XCSP_2_0_EXT,	///<xcsp v2.0 extension
	BFT_XCSP_2_1_EXT,	///<xcsp v2.1 extension
	BFT_XCSP_3_0_EXT	///<xcsp v3.0 extension
};

enum XmlReaderType
{
	XRT_BM_PATH,		///<banchmark path file
	XRT_BM				///<banchmark
};

class Builder
{
public:
	u32 id;
	Builder();
	virtual ~Builder();
};
}
}

#endif /* BUILDER_H_ */
