#include <iostream>

#ifndef TERM_HEADER
#define TERM_HEADER

using namespace std;

class Term {
	public:
		Term();

		Term(string word);

		friend bool operator<(const Term& w1, const Term& w2);

		~Term();

	private:
		string word_;

	friend class termTest;
};

#endif //TERM_HEADER
