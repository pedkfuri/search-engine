#include "../include/query.h"

Query::Query() {
	//vazio
}

map<Term, double> Query::getCoord() {
	return coord_.getPos();
}

void Query::setCoord(Coord coord) {
	this->coord_ = coord;
}

void Query::calcTermsCoord(Index& index, int numDocs) {
	for (auto& term : terms_) {
		double tf = term.second;
		double idf = log10(numDocs / index.numDocsAssoc(term.first));
	
		this->coord_.updateTermVal(term.first, tf * idf);
	}
}

void Query::setTerms(string exp) {
	char* exp_ = &exp[0u];
	char* token = new char(' ');

	strtok(exp_, token);

	while (exp_ != NULL) {
		string expAdd(exp);

		Files::normalizeTerm(expAdd);
		this->terms_[Term(expAdd)]++;
		exp_ = strtok(NULL, token);
	}
}

Query::~Query() {
	//vazio
}