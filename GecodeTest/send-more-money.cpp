/*
 *  Authors:
 *    Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *    Christian Schulte, 2008-2015
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software, to deal in the software without restriction,
 *  including without limitation the rights to use, copy, modify, merge,
 *  publish, distribute, sublicense, and/or sell copies of the software,
 *  and to permit persons to whom the software is furnished to do so, subject
 *  to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <gecode/int.hh>
#include <gecode/minimodel.hh>
#include <gecode/search.hh>

using namespace Gecode;

class SendMoreMoney: public Space {
protected:
public:
	IntVarArray l;
//	SendMoreMoney(void)
//			: l(*this, 8, 0, 9) {
//		IntVar s(l[0]), e(l[1]), n(l[2]), d(l[3]), m(l[4]), o(l[5]), r(l[6]), y(l[7]);
//		rel(*this, s != 0);
//		rel(*this, m != 0);
//		distinct(*this, l);
//		rel(*this,
//				1000 * s + 100 * e + 10 * n + d + 1000 * m + 100 * o + 10 * r + e
//						== 10000 * m + 1000 * o + 100 * n + 10 * e + y);
//		branch(*this, l, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
//	}
	SendMoreMoney(void) {
	}

	SendMoreMoney(bool share, SendMoreMoney& s)
			: Space(share, s) {
		l.update(*this, share, s.l);
	}

	virtual Space* copy(bool share) {
		return new SendMoreMoney(share, *this);
	}

	void print(void) const {
		std::cout << l << std::endl;
	}
};

//int main(int argc, char* argv[]) {
//	SendMoreMoney* smm = new SendMoreMoney;
//	smm->l = IntVarArray(*smm, 8, 0, 9);
//	IntVar s(smm->l[0]), e(smm->l[1]), n(smm->l[2]), d(smm->l[3]), m(smm->l[4]), o(smm->l[5]), r(smm->l[6]), y(
//			smm->l[7]);
//	rel(*smm, s != 0);
//	rel(*smm, m != 0);
//	distinct(*smm, smm->l);
//	rel(*smm,
//			1000 * s + 100 * e + 10 * n + d + 1000 * m + 100 * o + 10 * r + e
//					== 10000 * m + 1000 * o + 100 * n + 10 * e + y);
//	branch(*smm, smm->l, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
//
//	DFS<SendMoreMoney> ee(smm);
//	delete smm;
//	while(SendMoreMoney* ss = ee.next()) {
//		ss->print();
//		delete ss;
//	}
//	return 0;
//}
