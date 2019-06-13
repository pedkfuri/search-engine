#include <iostream>
#include <map>
#include <string>
#include <set>

#include "term.h"
#include "doc.h"

#ifndef INDEX_HEADER
#define INDEX_HEADER

using namespace std;

class Index {
	public:
		Index();

		map<Term, set<Doc>>& getRegs();
		
		void calcCoordMap(Doc& doc, int numDocs);

		double numDocsAssoc(Term term);

		~Index();

	private:
		map<Term, set<Doc>> regs_;
};

#endif //INDEX_HEADER


