////============================================================================
//// Name        : CSP_SAC.cpp
//// Author      : lee
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "XMLModel.h"
#include "XMLBuilder.h"
#include "GecodeModel.h"
#include "BuildGecodeModel.h"
#include <gecode\int.hh>
//#include "ModelTransfer.h"
//#include "SAC1.h"

using namespace std;
using namespace Gecode;
using namespace cudacsp::model;
using namespace cudacsp::parse;

const string X_PATH = "BMPath.xml";

int main() {
	cout << X_PATH << endl;
	XMLBuilder path_builder(X_PATH, XRT_BM_PATH);
	string bm_path = path_builder.GetBMFile();
	cout << bm_path << endl;
	XMLBuilder builder(bm_path, XRT_BM);
	XMLModel* xml_model = new XMLModel();
	builder.GenerateModelFromXml(xml_model);
	GecodeModel* gm = new GecodeModel;
	SizeOptions opt("Gecode Model");
	BuildGecodeModel(xml_model, gm);
	//GecodeModel* gmt = new GecodeModel;
	//ViewArray<Int::IntView> va(gm->vars_);
	//const int var_size = gmt->vars_.size();
	//ViewArray<Int::IntView> va(*gmt, var_size);
	//for (int i = 0; i < var_size; ++i)
	//{
	//	va[i] = Int::IntView(gmt->vars_[i]);
	//}
	//gm->print();
	//va[0].eq(*gm, 2);
	////va[1].eq(*gm, 4);
	//gm->status();
	//if (gm->failed())
	//	cout << "failed" << endl;
	//else
	//	cout << "ac!" << endl;
	//cout << "-------------" << endl;
	//gm->print();
	//gmt->print();
	DestroyEXTModel(xml_model);

	branch(*gm, gm->vars_, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
	DFS<GecodeModel> ee(gm);

	//BrancherHandle as = assign(*gm, gm->vars_[0], INT_ASSIGN_MIN());
	//as.update(*gm, true, as);
	//IntAssign ass();
	////branch(*gm, gm->vars_[0],)
	//gm->status();
	//cout << gm->vars_.assigned() << endl;
	//gm->print();
	delete gm;
	//delete gmt;
	int i = 0;
	while (GecodeModel* ss = ee.next()) {
		ss->print();
		++i;
		delete ss;
	}
	cout << "|solutions| = " << i << endl;
	cout << "---end---" << endl;
	return 0;

	printf("end!\n");
	return 0;
}

//int main() {
//	GecodeModel* gm = new GecodeModel;
//	gm->vars_ = IntVarArray(*gm, 3);
//
//	for(int i = 0; i < gm->vars_.size(); ++i) {
//		gm->vars_[i] = IntVar(*gm, 0, 2);
//	}
//
//	IntVarArray v(gm->vars_);
//	IntVarArgs vs[2];
//	vs[0] << v[0] << v[1];
//	vs[1] << v[1] << v[2];
//
//	TupleSet ts[2];
//	ts[0].add(IntArgs(2, 0, 0));
//	ts[0].add(IntArgs(2, 1, 1));
//	ts[0].add(IntArgs(2, 2, 2));
//	ts[0].finalize();
//
//	ts[1].add(IntArgs(2, 0, 1));
//	ts[1].add(IntArgs(2, 0, 2));
//	ts[1].add(IntArgs(2, 1, 2));
//	ts[1].finalize();
//	extensional(*gm, vs[0], ts[0]);
//	extensional(*gm, vs[1], ts[1]);
//	branch(*gm, v, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
//	DFS<GecodeModel> ee(gm);
//	delete gm;
//	while(GecodeModel* ss = ee.next()) {
//		ss->print();
//		delete ss;
//	}
//	cout << "---end---" << endl;
//	return 0;
//}
//using namespace cudacsp::algorithm;
//
