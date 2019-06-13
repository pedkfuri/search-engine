#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h"
#include "../include/files.h"

#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>

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