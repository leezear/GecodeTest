// Copyright 2011-2014 Google
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Cryptoarithmetic puzzle
//
// First attempt to solve equation CP + IS + FUN = TRUE
// where each letter represents a unique digit.
//
// This problem has 72 different solutions in base 10.
//
// Use of NewSearch.

#include <vector>

#include <base/logging.h>
#include <constraint_solver/constraint_solver.h>
#include "table.cc"

namespace operations_research {

// helper functions
IntVar* const MakeBaseLine2(Solver*  s,
	IntVar* const v1,
	IntVar* const v2,
	const int64 base) {
	return s->MakeSum(s->MakeProd(v1, base), v2)->Var();
}

IntVar* const MakeBaseLine3(Solver* s,
	IntVar* const v1,
	IntVar* const v2,
	IntVar* const v3,
	const int64 base) {
	std::vector<IntVar*> vars;
	std::vector<int64> coefficients;
	vars.push_back(v1);
	coefficients.push_back(base * base);
	vars.push_back(v2);
	coefficients.push_back(base);
	vars.push_back(v3);
	coefficients.push_back(1);

	return s->MakeScalProd(vars, coefficients)->Var();
}

IntVar* const MakeBaseLine4(Solver* s,
	IntVar* const v1,
	IntVar* const v2,
	IntVar* const v3,
	IntVar* const v4,
	const int64 base) {
	std::vector<IntVar*> vars;
	std::vector<int64> coefficients;
	vars.push_back(v1);
	coefficients.push_back(base * base * base);
	vars.push_back(v2);
	coefficients.push_back(base * base);
	vars.push_back(v3);
	coefficients.push_back(base);
	vars.push_back(v4);
	coefficients.push_back(1);

	return s->MakeScalProd(vars, coefficients)->Var();
}

void CPIsFun() {
	// Constraint programming engine
	Solver solver("CP is fun!");
	std::vector<int> vec = { 0,1,2 };
	std::vector<IntVar*> vars;
	vars.push_back(solver.MakeIntVar(vec));
	vars.push_back(solver.MakeIntVar(vec));
	vars.push_back(solver.MakeIntVar(vec));

	std::vector<IntVar*> scope0;
	std::vector<IntVar*> scope1;
	std::vector<std::vector<int>> tuple0 = { {0,0},{1,1},{2,2} };
	std::vector<std::vector<int>> tuple1 = { {0,1},{0,2},{1,2} };
	IntTupleSet is0(2);
	IntTupleSet is1(2);
	is0.InsertAll(tuple0);
	is1.InsertAll(tuple1);
	scope0.push_back(vars[0]);
	scope0.push_back(vars[1]);
	scope1.push_back(vars[1]);
	scope1.push_back(vars[2]);

	PositiveTableConstraint pt0(&solver, scope0, is0);
	PositiveTableConstraint pt1(&solver, scope1, is1);
	//solver.AddConstraint(solver.MakeEquality(vars[0], vars[1]));
	//solver.AddConstraint(solver.MakeLess(vars[1], vars[2]));

	DecisionBuilder* const db = solver.MakePhase(vars,
		Solver::CHOOSE_FIRST_UNBOUND,
		Solver::ASSIGN_MIN_VALUE);
	solver.NewSearch(db);

	if (solver.NextSolution()) {
		LOG(INFO) << "Solution found:";
		LOG(INFO) << "C=" << vars[0]->Value() << " " << "P=" << vars[1]->Value() << " "
			<< "I=" << vars[2]->Value();
	}
	else {
		LOG(INFO) << "Cannot solve problem.";
	}  // if (solver.NextSolution())

	solver.EndSearch();
}

}   // namespace operations_research

	// ----- MAIN -----
int main(int argc, char **argv) {
	operations_research::CPIsFun();
	return 0;
}
