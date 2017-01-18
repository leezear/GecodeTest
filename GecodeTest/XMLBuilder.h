/*
 * XMLBuilder.h
 *
 *  Created on: 2016年6月21日
 *      Author: leezear
 */

#ifndef XMLBUILDER_H_
#define XMLBUILDER_H_

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOMTreeWalker.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include "Builder.h"
#include "XMLModel.h"

using namespace xercesc_3_1;
using namespace cudacsp::model;

namespace cudacsp {
namespace parse {

/**
 * \brief XMLBuilder
 * Generate constraint network model for xml benchmark file
 * */
class XMLBuilder: public Builder {
public:

	/**
	 * \brief Constructors and initialization
	 * \param[in] i_file_name	The name of file.
	 * \param[in] i_type		The type of file, path file or banckmark file.
	 */
	XMLBuilder(std::string file_name, XmlReaderType type);
	virtual ~XMLBuilder();

	/**
	 * \brief Constructors and initialization
	 * \param[out] network	Pointer of model
	 * \return model generate result
	 *	-<em>false</em> fail
	 *	-<em>true</em> succeed
	 */
	bool GenerateModelFromXml(XMLModel *model);

	/**
	 * \brief GetBMFile
	 * \return Banchmark file path
	 */
	std::string GetBMFile() const;

private:
	NetworkFeatures feature_;		///<Feature of Network
	XMLModel *model_;				///<Constarint Network pointer
	std::string file_name_;			///<XML file name(path)
	XmlReaderType type_;			///<file type
	XercesDOMParser *parser_;
	DOMElement *root_;
	DOMDocument *document_;

	/**
	 * \brief createDomain
	 * \return Created domain
	 */
	//	void createDomain(XMLModel * network, const u32 dom_id, const u32 dom_size,
	//			std::string domain_values);
	std::vector<int> generateValues(const u32 dom_size, std::string values_str);

	void generateDomains(XMLModel *model);

	void generateVariables(XMLModel *model);

	void generateRelations(XMLModel *model);

	void generateTabulars(XMLModel *model);

	void generatePredicates(XMLModel *model);

	void generateConstraints(XMLModel *model);

	u32 getConstraintsCount();

	RelationType getRelationTpye();

	void getNetworkFeature();

	//void getNetworkFeature(XMLModel * network);

	int getMaxArity();

	bool initial();

};

}/* namespace parse */
}/* namespace cudacsp */

#endif /* XMLBUILDER_H_ */
