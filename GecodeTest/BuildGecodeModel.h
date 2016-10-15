/*
 * BuildGecodeModel.h
 *
 *  Created on: 2016年9月17日
 *      Author: leezear
 */

#ifndef BUILDGECODEMODEL_H_
#define BUILDGECODEMODEL_H_

#include "XMLModel.h"
#include "GecodeModel.h"
using namespace cudacsp::model;
using namespace Gecode;

inline bool TupleEqual(const int* lh, const int* rh, const int& len)
{
	for (int i = 0; i < len; ++i)
		if (lh[i] != rh[i])
			return false;

	return true;
}

void BuildGecodeModel(XMLModel *xmodel, GecodeModel* g_model)
{
	if (xmodel->ds_size == 1)
	{
		XMLDomain *d = &xmodel->domains[0];
		//		g_model->vars_ = IntVarArray(*g_model, xmodel->vs_size, d.values[0], d.values[d.size - 1]);
		g_model->vars_ = IntVarArray(*g_model, xmodel->vs_size, d->values[0], d->values[d->size - 1]);
	}
	else if (xmodel->ds_size != 1 && xmodel->vs_size != 1)
	{
		g_model->vars_ = IntVarArray(*g_model, xmodel->vs_size);
		for (int i = 0; i < xmodel->vs_size; ++i)
		{
			XMLVariable* v = &xmodel->variables[i];
			g_model->vars_[i] = IntVar(*g_model,
				IntSet(xmodel->domains[v->dm_id].values, xmodel->domains[v->dm_id].size));
		}
	}
	if (xmodel->features.rel_type == REL_TABULAR)
	{
		int* tss = new int(r->arity);
		int num_tuples;
		for (int i = 0; i < xmodel->cs_size; ++i)
		{
			XMLConstraint *c = &xmodel->constraints[i];
			TupleSet ts;
			XMLRelation* r = &xmodel->relations[c->re_id];
			XMLVariable* v;
			XMLDomain* d;
			if (r->type == SEM_SUPPORT)
			{
				for (int j = 0; j < r->size; ++j)
					ts.add(IntArgs(c->arity, r->tuples[j]));

				ts.finalize();
			}
			else
			{
				num_tuples = 1;

				for (int j = 0; j < r->arity; ++j)
				{
					v = &xmodel->variables[j];
					d = &xmodel->domains[v->dm_id];
					num_tuples* = d->size;
				}





			}

			IntVarArgs scope;

			for (int j = 0; j < c->arity; ++j)
			{
				scope << g_model->vars_[c->scope[j]];
			}
			//IntVarArray s;
			tss = nullptr;
			extensional(*g_model, scope, ts);
		}

		delete[] tss;
	}
	else {

	}


}



#endif /* BUILDGECODEMODEL_H_ */
