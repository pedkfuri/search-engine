#include <iostream>
#include <map>

#include "term.h"

#ifndef COORD_HEADER
#define COORD_HEADER

using namespace std;

class Coord {
	public:
		Coord();

		map<Term, double> getPos();

		void addPos(Term term, double val);

		void updateTermVal(Term term, double val);

		~Coord();

	private: 
		map<Term, double> pos_;
};

#endif //COORD_HEADER