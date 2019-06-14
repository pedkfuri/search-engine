#include <list>
#include <algorithm>
#include <cmath>
#include <string>

#include "index.h"
#include "doc.h"
#include "coord.h"
#include "query.h"
#include "files.h"
#include "display.h"

#ifndef SEARCHENGINE_HEADER
#define SEARCHENGINE_HEADER

using namespace std;

class SearchEngine {
	public:
		SearchEngine();

		void loopSearchEngine();

		void defCoord();

		void calcDocsCoord();

		void calcDocsSim();

		void sortDocs();

		~SearchEngine();
	private: 
		Index index_;

		vector<Doc> docs_;

		Coord defCoord_;
		
		Query query_;

	friend class searchEngineTest;
};
#endif //SEARCHENGINE_HEADER


