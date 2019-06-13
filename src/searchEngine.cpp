#include "../include/searchEngine.h"

SearchEngine::SearchEngine() {
	//vazio
}

void SearchEngine::loopSearchEngine() {
	cout << " :: Máquina de Busca :: " << endl;
	cout << "Processando...\n\n" << endl;
	this->docs_ = Files::readFiles();
	Files::getTerms(this->docs_, this->index_);

	defCoord();
	calcDocsCoord();

	do {
		cout << "Digite a expressão de busca: ";
		string expInput = Display::getInput();
		
		this->query_ = Query();
		this->query_.setTerms(expInput);
		this->query_.calcTermsCoord(this->index_, (int)this->docs_.size());

		calcDocsSim();
		sortDocs();

		cout << "Resultados para a busca \"" << expInput << "\"" << endl;
		Display::printResult(Doc::getDocsNames(this->docs_));
		cout << "- - - - - - - - - - - - - - " << endl;
		if (Display::menu()) cin.ignore();
		else break;
		cout << "- - - - - - - - - - - - - - " << endl;

	} while (true);
}

void SearchEngine::defCoord() {
	Coord coordenadaACriar;
	map<Term, set<Doc>>& regs = index_.getRegs();

	for (const auto& reg : regs) {
		coordenadaACriar.addPos(reg.first, 0);
	}

	this->defCoord_ = coordenadaACriar;

	for (Doc& doc : docs_) {
		doc.setCoord(this->defCoord_);
	}

	this->query_.setCoord(this->defCoord_);
}

void SearchEngine::calcDocsCoord() {
	for (Doc& doc : this->docs_) {
		index_.calcCoordMap(doc, (int)docs_.size());
	}
}

void SearchEngine::calcDocsSim() {
	for (Doc& doc : docs_) {
		double num = 0;
		double denom = 0;
		double sumDocPos = 0;
		double sumQueryPos = 0;
		
		for (auto& termPos : doc.getCoord()) {
			num += query_.getCoord()[termPos.first] * termPos.second;
			sumDocPos += pow(termPos.second, 2);
			sumQueryPos += pow(query_.getCoord()[termPos.first], 2);
		}
		denom += sqrt(sumDocPos) * sqrt(sumQueryPos);
		doc.setSim(num/denom);
	}
}

void SearchEngine::sortDocs() {
	this->docs_.sort([](const Doc& d1, const Doc& d2) { return d1.getSim() > d2.getSim(); });
}

SearchEngine::~SearchEngine() {
	//vazio	
}