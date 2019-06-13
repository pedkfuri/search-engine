#include "../include/index.h"

Index::Index() {
	//vazio
}

map<Term, set<Doc>>& Index::getRegs() {
	return this->regs_;
}

void Index::calcCoordMap(Doc& doc, int numDocs) {
	for (auto& term : doc.terms_) {
		int tf = doc.getOccsTerm(term.first);
		double idf = log10((double)numDocs / numDocsAssoc(term.first));
		doc.coord_.updateTermVal(term.first, tf * idf);
	}
}

double Index::numDocsAssoc(Term term) {
	set<Doc> docs = this->regs_[term];
	return (double)docs.size();
}

Index::~Index() {
	//vazio
}