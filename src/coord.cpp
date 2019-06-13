#include "../include/coord.h"

Coord::Coord() {
	//vazio
}

map<Term, double> Coord::getPos() {
	return pos_;
}

void Coord::addPos(Term term, double val) {
	this->pos_.insert({ term, val });
}

void Coord::updateTermVal(Term term, double val) {
	this->pos_[term] = val;
}

Coord::~Coord() {
	//vazio
}