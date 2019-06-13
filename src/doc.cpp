#include "../include/doc.h"

Doc::Doc() {
	//vazio
}

Doc::Doc(string name) {
	this->name_ = name;
}

string Doc::getDocName() {
	return this->name_;
}

map<Term, double> Doc::getCoord() {
	return coord_.getPos();
}

void Doc::setSim(double sim_) {
	this->sim_ = sim_;
}

bool operator<(const Doc& d1, const Doc& d2) {
	return d1.name_ < d2.name_;
}

map<Term, int>& Doc::getTerms() {
	return this->terms_;
}

double Doc::getSim() const {
	return this->sim_;
}

void Doc::setCoord(Coord coord) {
	this->coord_ = coord;
}

int Doc::getOccsTerm(Term term) {
	return this->terms_[term];
}

vector<string> Doc::getDocsNames(list<Doc> docs) {
	vector<string> names;

	for (Doc& doc : docs) {
		names.push_back(doc.name_);
	}

	return names;
}

Doc::~Doc() {
	//vazio
}