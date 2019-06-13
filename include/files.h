#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <cstring>
#include <dirent.h>

#include "doc.h"
#include "term.h"
#include "index.h"

using namespace std;

namespace Files {

	list<Doc> readFiles();

	void getTerms(list<Doc>& docs, Index& index);

	void normalizeTerm(string& term);
	
	void addToII(Doc& doc, Index& Index, Term term);
	
	void addToDoc(Doc& doc, Term term);
}