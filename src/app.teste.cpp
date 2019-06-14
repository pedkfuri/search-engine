#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h"
#include "../include/files.h"
#include "../include/doc.h"
#include "../include/coord.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

TEST_SUITE("Input"){
	TEST_CASE("normalizeTerm()"){
		string w1 = "Casa"; // maiscula
		string w2 = "Guarda-chuvas"; //separação
		string w3 = "casa."; //pontuação

		Files::normalizeTerm(w1);
		Files::normalizeTerm(w2);
		Files::normalizeTerm(w3);

		CHECK(w1 == "casa");
		CHECK(w2 == "guardachuvas");
		CHECK(w3 == "casa");
	}
}

TEST_SUITE("Doc"){
	TEST_CASE("getDocName"){
		Doc doc1("doc1");
		CHECK(doc1.Doc::getDocName() == "doc1");
	}

	TEST_CASE("getDocsNames"){
		vector<Doc> docs = {Doc("doc1"), Doc("doc2")};
		vector<string> names = {"doc1", "doc2"};
		CHECK(Doc::getDocsNames(docs) == names);
	}
}

TEST_SUITE("Coord"){
	TEST_CASE("getPos"){
		Coord c1;
		Term t1("Casa");
		c1.addPos(t1, 1);
		map<Term, double> coord;

		coord[t1] = 1;

		CHECK(c1.getPos()[t1] == 1);
	}

	TEST_CASE("addPos"){
		Coord c1;
		Term t1("Casa");
		c1.addPos(t1, 1);
		CHECK(c1.getPos()[t1] == 1);
	}
}