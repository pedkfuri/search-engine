#include <iostream>

#include "../include/term.h"

using namespace std;

Term::Term() {
	//vazio
}

Term::Term(string word) {
	this->word_ = word;
}

bool operator<(const Term& w1, const Term& w2) {
	return w1.word_ < w2.word_;
}

Term::~Term() {
	//vazio
}
