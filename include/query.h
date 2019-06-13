#include <map>
#include <cmath>

#include "term.h"
#include "coord.h"
#include "index.h"
#include "files.h"

#ifndef QUERY_HEADER
#define QUERY_HEADER

class Query {
	public:
		Query();

		map<Term, double> getCoord();

		void setCoord(Coord coord);

		void calcTermsCoord(Index& index, int numDocs);

		void setTerms(string exp);

		~Query();

	private:
		map<Term, int> terms_;

		Coord coord_;
};

#endif //QUERY_HEADER
