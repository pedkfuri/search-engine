#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <cmath>

#include "term.h"
#include "coord.h"

#ifndef DOC_HEADER
#define DOC_HEADER

using namespace std;

class Doc {
	public:
		Doc();
		
		Doc(string name);
		
		string getDocName();

		map<Term, double> getCoord();

		void setSim(double sim_);

		friend bool operator<(const Doc& d1, const Doc& d2);

		map<Term, int>& getTerms();

		double getSim() const;

		void setCoord(Coord coord);

		int getOccsTerm(Term term);

		static vector<string> getDocsNames(list<Doc> docs);

		friend class Index;

		~Doc();

	private: 
		string name_;

		map<Term, int> terms_;

		Coord coord_;

		double sim_;
};

#endif //DOC_HEADER

